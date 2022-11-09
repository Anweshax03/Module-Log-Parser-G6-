#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include<fstream>
#include<Module.h>

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
	for(auto it=list.begin();it!=list.end();it++)
	{
		cout<<it->second->getTimeSequence()<<" "<<it->second->getModulName()<<" "<<it->second->getMessageType()<<" "<<it->second->getErrorCode()<<" "<<it->second->getMessage()<<endl;
	}
}
void Module::displayInvalidFile()
{
	string line;
	ifstream ip;
	ip.open("invalid.txt",ios::in);
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
	
}



