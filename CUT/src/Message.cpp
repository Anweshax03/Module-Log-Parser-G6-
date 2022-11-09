#include<iostream>
#include<string>
#include<Message.h>

using namespace std;

Message::Message()
{
};
Message::Message(int timeseq1,string mname1,string msgType1,string errorCode1,string msg1)
{
	timeseq=timeseq1;
	mname=mname1;
	msgType=msgType1;
	errorCode=errorCode1;
	msg=msg1;
}
int Message::getTimeSequence()
{
	return timeseq;
};
string Message::getModulName()
{
	return mname;
};
string Message::getMessageType()
{
	return msgType;
};
string Message::getErrorCode()
{
	return errorCode;
};
string Message::getMessage()
{
	return msg;
};


