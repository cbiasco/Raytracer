#pragma once
//
// Parser.h
//
// Code by Caleb Biasco (biasc007) for Assignment-1A of CSCI5607

/*
 * The Parser class is meant to streamline the file-reading process but
 * still restrict the user from messing with the input stream.
 * The user can get keywords and numbers from a specified file and
 * check if an expected token was a number.
 */
#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::string;
using std::stringstream;

class Parser
{
public:
	Parser();
	virtual ~Parser();

	// Load a file for reading.
	// Returns false if the file could not be loaded.
	bool loadFile(string filename);

	// Check if the end of the file has been reached.
	bool endOfFile();

	// Jump to the next line in the file.
	void nextLine();

	// Get the next token and return it as a number.
	// Sets the given boolean to false if it actually was not a number.
	double getNum(bool &a);

	// Get the next token and return it as a string.
	string getKeyword();

private:
	ifstream m_inputFile; // the opened file
	string m_curLineStr; // a middleman string for the stringstream
	stringstream m_curLineSS; // the stringstream outputting the tokens
	bool m_eof = false; // a flag for reaching the end of the opened file
};