//
// Parser.cpp
//
// Code by Caleb Biasco (biasc007) for Assignment-1 of CSCI5607

/*
 * The Parser class is meant to streamline the file-reading process but
 * still restrict the user from messing with the input stream.
 * The user can get keywords and numbers from a specified file and
 * check if an expected token was a number.
 */

#include "Parser.h"

using std::ifstream;
using std::string;
using std::stringstream;

Parser::Parser() {}

Parser::~Parser()
{
	if (m_inputFile.is_open())
		m_inputFile.close();
}

bool Parser::loadFile(string filename)
{
	// Close the currently opened file.
	if (m_inputFile.is_open())
		m_inputFile.close();

	// Try to open the requested file.
	m_inputFile.open(filename);
	if (m_inputFile.fail())
		return false;

	// Reset the EndOfFile flag.
	m_eof = false;
	return true;
}

bool Parser::endOfFile()
{
	return m_eof;
}

void Parser::nextLine()
{
	if (m_inputFile.is_open())
	{
		// Get the next line from the input file and put it in the string. If it's the
		// end of the file, close the file, set the EndOfFile flag and leave.
		if (!std::getline(m_inputFile, m_curLineStr))
		{
			m_inputFile.close();
			m_eof = true;
			return;
		}

		// Load the line into the stringstream.
		m_curLineSS.clear();
		m_curLineSS.str(m_curLineStr);
	}
}

double Parser::getNum(bool &b)
{
	// Grab the next line while there's nothing to read from the current one.
	while (!m_curLineSS || m_curLineSS.peek() <= 0 || m_curLineSS.peek() == '#')
	{
		if (m_eof)
		{
			b = false;
			return -1;
		}
		nextLine();
	}

	// Return the next token in the line.
	double d;
	m_curLineSS >> d;
	b = b && !m_curLineSS.fail();
	return d;
}

bool Parser::skipChar(char c)
{
	char s;
	m_curLineSS >> s;
	if (c == s)
		return true;
	return false;
}

char Parser::peekChar()
{
	return m_curLineSS.peek();
}

string Parser::getKeyword()
{
	// Grab the next line while there's nothing to read from the current one.
	while (!m_curLineSS || m_curLineSS.peek() <= 0 || m_curLineSS.peek() == '#')
	{
		if (m_eof)
			return "";
		nextLine();
	}

	// Return the next token in the line.
	string str;
	m_curLineSS >> str;
	return str;
}

string Parser::swapFileName(string pathAndFile, string newFile)
{
	int pathEnd = pathAndFile.length() - 1;

	while (pathEnd > 0 && pathAndFile[pathEnd] != '\\' && pathAndFile[pathEnd] != '/')
		pathEnd--;
	
	if (pathEnd <= 0)
		return newFile;
	
	return pathAndFile.substr(0, pathEnd + 1) + newFile;
}
