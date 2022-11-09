#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <cstring>
#include "Module.h"
#include "Message.h"

using namespace std;

class Parser:public Module
{
	public:
		Parser();
		Parser(string filename1);
		void readInputFile(string );
		string getFileName();
	protected:
		string filename;
};

#endif

