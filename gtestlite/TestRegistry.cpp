

#include "Test.h"
#include "TestResult.h"
#include "TestRegistry.h"


void TestRegistry::addTest (Test *test) 
{
	instance ().add (test);
}


void TestRegistry::runAllTests (TestResult& result) 
{
	instance ().run (result);
}


TestRegistry& TestRegistry::instance () {
	static TestRegistry registry;
	return registry;
}


void TestRegistry::add (Test *test) {
	tests.push_back (test);
}


void TestRegistry::run (TestResult& result) {
	result.startTests ();
	for (std::vector<Test *>::iterator it = tests.begin (); it != tests.end (); ++it){
		printf("[TEST-RUN]\t\t<SUITE>%s\t\t<TEST>%s\n",(*it)->test_namespace.c_str(),(*it)->test_name.c_str());
		(*it)->run (result);

	}
	result.endTests ();
}

/// /// #####################  Run by Test Suite   ###########################
void TestRegistry::runTestsbySuite (TestResult& result, std::string test_space) 
{
	instance ().runbySuite (result,test_space);
}

void TestRegistry::runbySuite (TestResult& result, std::string test_space) {
	result.startTests ();
	for (std::vector<Test *>::iterator it = tests.begin (); it != tests.end (); ++it) {
		if ((*it)->test_namespace==test_space){
			printf("[TEST-RUN]\t\t<SUITE>%s\t\t<TEST>%s\n",(*it)->test_namespace.c_str(),(*it)->test_name.c_str());
			(*it)->run (result);
		}
		
	}
	result.endTests ();
}
/// /// #####################  Run by Full Test Name  ###########################
void TestRegistry::runTestsbyFullName (TestResult& result, std::string test_space, std::string test_name) 
{
	instance ().runbyFullName (result,test_space,test_name);
}

void TestRegistry::runbyFullName (TestResult& result, std::string test_space, std::string test_name) {
	result.startTests ();
	for (std::vector<Test *>::iterator it = tests.begin (); it != tests.end (); ++it) {
		if ((*it)->test_namespace==test_space && (*it)->test_name==test_name){
			printf("[TEST-RUN]\t\t<SUITE>%s\t\t<TEST>%s\n",(*it)->test_namespace.c_str(),(*it)->test_name.c_str());
			(*it)->run (result);
		}
		
	}
	result.endTests ();
}