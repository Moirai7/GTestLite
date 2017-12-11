

#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <time.h>


class Failure;

class TestResult
{
public:
    TestResult ();
    virtual ~TestResult() {};

	virtual void testWasRun ();
	virtual void startTests ();
	virtual void addFailure (const Failure & failure);
	virtual void endTests ();

	void getTotalTestCases();
    //int getFailureCount() const { return failureCount; }

protected:
	//int failureCount;
	//int current_failure_count;
	//int testCount;
	//int suite_test_count;
    time_t startTime;
    int secondsElapsed;

	int count_testcase_total;  /// how many testcases totally
	int count_testcase_in_suite;  /// how many	testcases in each test suite

	int count_failure_testcase_total;  	  /// how many failed testcases in total
	int count_failure_in_testcase;	 /// how many failures in each test cases
	int count_failure_testcase_in_suite;  /// how many failed TestCases in each test Suite
	int count_failure_total;     /// How many failures in total in each suite
};

#endif
