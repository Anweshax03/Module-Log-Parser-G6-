#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <Message.h>

using namespace std;
 
class Module:public Message
{
	public:
		Module();
		Module(string Mname1);
		void display();
		void displayInvalidFile();
	        string getModuleName();	
	protected:
		string Mname;
};

#endif

