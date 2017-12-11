
#include "TestResult.h"
#include "Failure.h"


TestResult::TestResult() : count_failure_testcase_total(0),count_failure_total(0), count_failure_testcase_in_suite (0), count_failure_in_testcase(0), count_testcase_total(0), secondsElapsed(0),count_testcase_in_suite(0)
{
    ::time(&startTime);
}

void TestResult::getTotalTestCases(){
	printf("\n\n****** ****** ****** Total Test Cases:        %d ****** ****** ******\n",count_testcase_total);
	printf("****** ****** ****** Total Failed Test Cases: %d ****** ****** ******\n",count_failure_testcase_total);
}
void TestResult::testWasRun()
{
	count_testcase_total++;
	count_testcase_in_suite++;
	//printf("current_failure_count: %d\n",count_failure_in_testcase);
	if(count_failure_in_testcase==0){
		printf("\t\t***** TESTCASE PASS: no failures.\n\n");
	}
	else{
		printf("\t\t***** TESTCASE FAIL: (%d failures).\n\n",count_failure_in_testcase);
		count_failure_testcase_total++;
		count_failure_testcase_in_suite++;
	}
	count_failure_in_testcase=0;
}

void TestResult::startTests () 
{
	//printf("********** START ************\n\n");
}


void TestResult::addFailure (const Failure & /*failure*/) 
{
	count_failure_in_testcase++;
	//count_failure_in_suite++;
	count_failure_total++;
}

void TestResult::endTests () 
{
    time_t endTime;
    ::time(&endTime);
    secondsElapsed = endTime - startTime;
}
