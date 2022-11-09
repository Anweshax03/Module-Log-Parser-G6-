#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string>
#include<thread>
#include<mutex>
#include<vector>
#include<Parser.h>
std::mutex mtx;
 
using namespace std;

Parser::Parser()
{
}

Parser::Parser(char* filename1)
{
	filename=filename1;
}

string Parser::getFileName()
{
	return filename;
}

/*void operator()(string Mname1)
{
	readInputFile(Mname1);
}*/

void Parser::readInputFile(string Mname1)
{
	mtx.lock();
	Module m(Mname1);
	string line;
	int flag=0;
	ofstream op;
	op.open("invalidLog.txt");
	try
	{
		if(!op.is_open())
		{
			throw "unable to open file";
		}
	}
	catch(...)
	{
		cout<<"unable to open file"<<endl;
	}
	ifstream ip;
	ip.open(filename);
	try
	{
		if(!ip.is_open())
		{
			cout<<"unable to open"<<endl;
			throw "file not found";
		}

		while(getline(ip,line))
		{
			stringstream ss(line);                           
			int timeseq1;
			string mname1;
			string msgType1;
			string errorCode1;
			string msg1;
			string stimeseq;
			int count=0;
			if(getline(ss,stimeseq,' '))
			{
				timeseq1=stoi(stimeseq);
				count++;
			}
			if(getline(ss,mname1,' '))
			{
				count++;
			}
			if(getline(ss,msgType1,' '))
			{
				count++;
			}
			if(getline(ss,errorCode1,' '))
			{
				int l=errorCode1.length();
				if(errorCode1[0]=='E' && l==5)
					count++;
			}
			if(getline(ss,msg1,' '))
			{
				count++;
			}
			if(count==5)
			{
				if(mname1==Mname1)
				{
					list.insert(make_pair(msgType1,new Message(timeseq1,mname1,msgType1,errorCode1,msg1)));
					flag=1;
				}
			}
			else
			{
				
				op<<line<<endl;
			}
		}
		if(flag==0)
		{
			cout<<Mname1<<"not present"<<endl;
		}
	}
	catch(...)
	{
		cout<<filename<<" not found"<<endl;
	}
	ip.close();
	op.close();
	mtx.unlock();		
	
			
}


