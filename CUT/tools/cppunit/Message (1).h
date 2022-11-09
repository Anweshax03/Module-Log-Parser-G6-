#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

class Message
{
	public:
		Message();
		Message(int timeseq1,string mname1,string msgType1,string errorCode1,string msg1);		   
		int getTimeSequence();
		string getModulName();
		string getMessageType();
		string getErrorCode();
		string getMessage();
	protected:	
		int timeseq;
		string mname;
		string msgType;
		string errorCode;
		string msg;
		multimap<string,Message*> list; 
};

#endif


