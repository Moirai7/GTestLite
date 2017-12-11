

#include "Test.h"
#include "TestRegistry.h"
#include "TestResult.h"
#include "Failure.h"


Test::Test (const std::string& testName,const std::string& spacename,const std::string& test_name) : name (testName),test_namespace(spacename),test_name(test_name) 
{
	TestRegistry::addTest (this);
	//printf("I am here: ");
	//std::cout<<test_namespace<<"_"<<test_name<<std::endl;
}


void Test::run (TestResult& result) 
{
#ifndef DONT_CATCH_EXCEPTIONS
    try
    {
#endif
        setup();
		//printf("I am HHHH\n");
	    runTest (result);
#ifndef DONT_CATCH_EXCEPTIONS
    }
    catch (...) {
        result.addFailure (Failure ("Unhandled exception", name, "", 0)); \
    }
#endif
    teardown();
	result.testWasRun();
}

