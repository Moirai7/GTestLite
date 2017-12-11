#include "TestResultStdErr.h"
#include "Failure.h"
#include <iostream>
#include <sstream>
 

void TestResultStdErr::addFailure (const Failure & failure) 
{
    std::ostringstream oss;
    oss << failure;
    TestResult::addFailure(failure);
	printf("%s \n",oss.str().c_str());
}

void TestResultStdErr::endTests () 
{
    TestResult::endTests();
    std::ostringstream oss;
 
	printf("...........\t TEST CASES: %d\n",count_testcase_in_suite);
    //oss <<"...........\t"<< "TEST CASES: "<<count_testcase_in_suite << std::endl;
 
	//oss <<"...........\t" <<"TESTS FAILED: " << count_failure_testcase_in_suite;
 	printf("...........\t TEST FAILED: %d ",count_failure_testcase_in_suite);
    //oss << " (" << count_failure_total << " failures in total)";
 	printf("  (%d failures in total)",count_failure_total);
    //oss << " (time: " << secondsElapsed << "s)\n\n" ;
	printf("  (time: %ds)\n\n\n",secondsElapsed);
	secondsElapsed=0;
	count_failure_total=0;
	count_testcase_in_suite=0;
	count_failure_testcase_in_suite=0;

}
