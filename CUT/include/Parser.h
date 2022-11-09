#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <cstring>
#include <Module.h>
#include <Message.h>

using namespace std;

class Parser:public Module
{
	public:
		Parser();
		Parser(char* filename1);
		void readInputFile(string );
		string getFileName();
	protected:
		char* filename=NULL;
};

#endif

