
#include<iostream>
#include<thread>
#include<cstring>
#include<Parser.h>
#include<vector>
#include<Module.h>

using namespace std;
vector<thread> threads;

int main(int argc, char* argv[])
{
	
	Parser p1(argv[1]);
	for(int i=2;i<argc;i++)
	{
		//threads.emplace_back(Parser(),argv[i]);
		p1.readInputFile(argv[i]);
	}
	/*for(auto& thr:threads)
		thr.join();*/	
	p1.display();
	p1.displayInvalidFile();
	return 0;
}



