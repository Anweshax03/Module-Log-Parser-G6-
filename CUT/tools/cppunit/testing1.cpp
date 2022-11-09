#include <iostream>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include "Module.h"
#include "Parser.h"

using namespace CppUnit;
using namespace std;

class TestM:public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestM);
    CPPUNIT_TEST(testName); 
    CPPUNIT_TEST(testfname);
    CPPUNIT_TEST_SUITE_END();

    public:
    	void setUp(void);
    	void tearDown(void);

    protected:
    	void testName(void);
	void testfname(void);  
    private:
	Module *m[4];
	Parser *p[4];
};


void TestM::testName(void)
{
	//sunny testcases
	CPPUNIT_ASSERT("analyzer"==m[0]->getModuleName());
	CPPUNIT_ASSERT("commandTry"==m[1]->getModuleName());
	CPPUNIT_ASSERT("algo"==m[2]->getModuleName());
	CPPUNIT_ASSERT("interpreter"==m[3]->getModuleName());

	//rainy testcases
	CPPUNIT_ASSERT("algorithm"==m[0]->getModuleName());
	CPPUNIT_ASSERT("command"==m[1]->getModuleName());
	CPPUNIT_ASSERT("debug"==m[2]->getModuleName());
	CPPUNIT_ASSERT("install"==m[3]->getModuleName());
	

}

void TestM::testfname(void)
{
	//sunny testcases
	CPPUNIT_ASSERT("file"==p[0]->getFileName());
	CPPUNIT_ASSERT("inputfile1"==p[1]->getFileName());
	CPPUNIT_ASSERT("inputfile2"==p[2]->getFileName());
	CPPUNIT_ASSERT("inputfile3"==p[3]->getFileName());

	//rainy testcases
	
	CPPUNIT_ASSERT("inputf"==p[0]->getFileName());
	CPPUNIT_ASSERT("input1"==p[1]->getFileName());
	CPPUNIT_ASSERT("input2"==p[2]->getFileName());
	CPPUNIT_ASSERT("input3"==p[3]->getFileName());

}


void TestM::setUp(void)
{
	m[0]=new Module("analyzer");
	m[1]=new Module("commandTry");
	m[2]=new Module("algo");
	m[3]=new Module("interpreter");
	

	p[0]=new Parser("file");
	p[1]=new Parser("inputfile1");
	p[2]=new Parser("inputfile2");
	p[3]=new Parser("inputfile3");

}

void TestM::tearDown(void)
{
	delete *m;
	delete *p;
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestM );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("ModuleMessages.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

