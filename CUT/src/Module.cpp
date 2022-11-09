#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include<fstream>
#include<thread>
#include<mutex>
#include<Module.h>
std::mutex mtx1;
using namespace std;

Module::Module()
{
}
Module::Module(string Mname1)
{
	Mname=Mname1;
}
string Module::getModuleName()
{
	return Mname;
}
void Module::display()
{
	cout<<"valid messages: "<<endl;
	for(auto it=list.begin();it!=list.end();it++)
	{
		cout<<it->second->getTimeSequence()<<" "<<it->second->getModulName()<<" "<<it->second->getMessageType()<<" "<<it->second->getErrorCode()<<" "<<it->second->getMessage()<<endl;
	}
}
void Module::displayInvalidFile()
{
	mtx1.lock();
	string line;
	ifstream ip;
	ip.open("invalidLog.txt",ios::in);
	try
	{
		if(!ip.is_open())
		{
			throw 1;
		}
	}
	catch(int i)
	{
		cout<<"unable to open file"<<endl;
	}
	cout<<endl<<"Messages in invalidLog file are: "<<endl<<endl;
	while(getline(ip,line))
	{
		cout<<line<<endl;
	}
	ip.close();
	mtx1.unlock();
	
}



