
#ifndef TEST_H
#define TEST_H


// Test is a base class for all tests.  It provides a command interface for
// running tests (run) as well as a data member for recording the name of 
// the test.
//
// Tests are constructed using the TEST macro.  TEST creates a subclass of
// Test and static instance of that subclass.  If you look at the constructor
// for the Test class, you'll notice that it registers the created object 
// with a global TestRegistry.  These features combine to make test creation
// particularly easy.

#include <vector>
#include <string.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include "checks.h"

#define FILE_S (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

class TestSetup
{
public:
    virtual void setup() = 0;
    virtual void teardown() = 0;
};



class TestResult;


class Test : public TestSetup
{
public:
	Test (const std::string& testName,const std::string& spacename,const std::string& test_name);

	virtual void	run (TestResult& result);
	virtual void	runTest (TestResult& result) = 0;
	
	std::string test_namespace;
	std::string test_name;

protected:
	std::string		name;


};


 /*classUnderTest##name##Test () : Test (#name "_Test" ) {} \*/
#define TEST(name,classUnderTest)\
	class classUnderTest##name##Test : public Test\
	{ \
		public: \
		classUnderTest##name##Test () : Test (#name "_Test",#name,#classUnderTest ) {} \
            void setup() {}; \
            void teardown() {}; \
			void runTest (TestResult& result_); \
	} classUnderTest##name##Instance; \
	void classUnderTest##name##Test::runTest (TestResult& result_) \


#define TESTWITHSETUP(name,classUnderTest)\
	class classUnderTest##name##Test : public Test, name##Setup\
	{ \
		public: \
		classUnderTest##name##Test () : Test (#name "_Test",#name,#classUnderTest ) {} \
            void setup() {name##Setup::setup();} \
            void teardown() {name##Setup::teardown();} \
			void runTest (TestResult& result_); \
	} classUnderTest##name##Instance; \
	void classUnderTest##name##Test::runTest (TestResult& result_) \



// Here is a collection of testing macros that can be used in the 
// bodies of tests.  CHECK tests a boolean expression and records
// a failure if the expression evaluates to false.  CHECK_LONGS_EQUAL
// and CHECK_DOUBLES_EQUAL compare longs and doubles respectively.
//
// To make this an industrial strength test harness, you should
// add equals macros for various low level types as you develop them.
// If, for instance, you have a daterange class, the ability to compare
// them directly and print out their values in the test output is 
// invaluable.



#ifndef DONT_CATCH_EXCEPTIONS


#define CHECK(condition, ...) \
    try { \
		if (!(condition)) \
		result_.addFailure (Failure ( #condition " is incorrect" , name, FILE_S, __LINE__,##__VA_ARGS__)); \
		else if (result_.debug){\
		printf("%s (%s line:%d)\n","Pass: "#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } catch(...) { \
		result_.addFailure (Failure ("Unhandled exception in CHECK " #condition , name, FILE_S, __LINE__,##__VA_ARGS__)); \
    }

#define CHECK_EQUAL(expected, actual,...) \
     try { \
	       std::string errorMsg;\
               if (expected != actual){\
                        std::ostringstream oss;\
                        oss << "Expected " << expected << " but was " << actual;\
                        errorMsg = oss.str();\
			   result_.addFailure (Failure (errorMsg, name, FILE_S, __LINE__,##__VA_ARGS__));\
            }\
		else if (result_.debug){\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } catch(...) { \
	     result_.addFailure (Failure ("Unhandled exception", name, FILE_S, __LINE__,##__VA_ARGS__)); \
    }\


#define CHECK_CLOSE(expected, actual, tolerance,...) \
	try { \
	    std::string errorMsg;\
        if ( CheckClose(expected, actual,tolerance,errorMsg)==false ){ \
            result_.addFailure (Failure (errorMsg, name, FILE_S, __LINE__,##__VA_ARGS__));\
		} \
		else {\
	if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } \
    catch (...) { \
	result_.addFailure (Failure ("Unhandled exception in CHECK_CLOSE ",name, FILE_S, __LINE__,##__VA_ARGS__)); \
    } \
 

#define CHECK_LONGS_EQUAL(expected,actual, ...)\
{\
    try { \
        long _expected = (expected);\
        long _actual = (actual);\
        if (_expected != _actual) {\
            char message [80];\
            sprintf (message, "expected %ld but was: %ld", _expected, _actual);\
			result_.addFailure (Failure (message, name, FILE_S, __LINE__,##__VA_ARGS__));\
        }\
		else {\
	if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } catch(...) { \
	result_.addFailure (Failure ("Unhandled exception", name, FILE_S, __LINE__,##__VA_ARGS__)); \
    }\
}


#define CHECK_DOUBLES_EQUAL(expected,actual, ...)\
{\
    try { \
        double _expected = (expected);\
        double _actual = (actual);\
        if (fabs ((_expected)-(_actual)) > 0.001) {\
            char message [80];\
            sprintf (message, "expected %lf but was: %lf", (_expected), (_actual));\
			result_.addFailure (Failure (message, name, FILE_S, __LINE__,##__VA_ARGS__));\
        }\
		else {\
	if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } catch(...) { \
	result_.addFailure (Failure ("Unhandled exception", name, FILE_S, __LINE__,##__VA_ARGS__)); \
    }\
}


#define CHECK_POINTS_EQUAL(expected,actual, ...)\
{\
    try { \
        Point3d _expected = (expected); \
        Point3d _actual = (actual); \
        if (!_actual.Equals(_expected)) { \
            char message [256];\
            sprintf (message, "expected point (%f, %f, %f) but was: (%f, %f, %f)", \
                 _expected.x, _expected.y, _expected.z,\
                 _actual.x, _actual.y, _actual.z); \
				 result_.addFailure (Failure (message, name, FILE_S, __LINE__,##__VA_ARGS__));\
        }\
		else {\
	if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } catch(...) { \
	result_.addFailure (Failure ("Unhandled exception", name, FILE_S, __LINE__,##__VA_ARGS__)); \
    }\
}


#define CHECK_STRINGS_EQUAL(expected,actual, ...)\
{\
    try { \
        std::string _expected(expected);\
        std::string _actual(actual);\
        if (_expected != _actual) {\
            std::string msg = std::string("expected '") + _expected + \
                              std::string("' but was: '") + _actual + "'"; \
							  result_.addFailure (Failure (msg.c_str(), name, FILE_S, __LINE__,##__VA_ARGS__));\
        }\
		else {\
	if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } catch(...) { \
	result_.addFailure (Failure ("Unhandled exception", name, FILE_S, __LINE__,##__VA_ARGS__)); \
    }\
}

#define CHECK_ARRAY_EQUAL(expected, actual, count,...) \
    { \
        try { \
			 std::string errorMsg;\
			 if ( CheckArrayEqual(  expected, actual, count,errorMsg )==false){ \
			      result_.addFailure (Failure (errorMsg, name, FILE_S, __LINE__,##__VA_ARGS__));\
             }\
		     else {\
	if (result_.debug)\
		        printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		      }\
        } \
        catch (...) { \
			result_.addFailure (Failure ("Unhandled exception", name, FILE_S, __LINE__,##__VA_ARGS__)); \
        } \
    }  


 
#define CHECK_THROW(expression, ExpectedExceptionType, ...) \
    do \
    { \
        bool caught_ = false; \
        try {\
		   expression; \
		} \
        catch (ExpectedExceptionType const&) { caught_ = true; } \
        catch (...) {} \
        if (!caught_) {\
			result_.addFailure (Failure ("Expected exception: \"" #ExpectedExceptionType "\" not thrown", name, FILE_S, __LINE__,##__VA_ARGS__));\
		}\
		else {\
	if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}\
    } while(0)
 


#else


#define CHECK(condition) \
	if (!(condition)) \
		result_.addFailure (Failure (#condition, name, __FILE__, __LINE__));\
		else if (result_.debug){\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
		}

#define CHECK_LONGS_EQUAL(expected,actual)\
{\
	long _expected = (expected);\
	long _actual = (actual);\
	if (_expected != _actual) {\
		char message [80];\
		sprintf (message, "expected %ld but was: %ld", _expected, _actual);\
		result_.addFailure (Failure (message, name, __FILE__, __LINE__));\
	}\
		else if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
}


#define CHECK_DOUBLES_EQUAL(expected,actual)\
{\
	double _expected = (expected);\
	double _actual = (actual);\
	if (fabs ((_expected)-(_actual)) > 0.001) {\
		char message [80];\
		sprintf (message, "expected %lf but was: %lf", (_expected), (_actual));\
		result_.addFailure (Failure (message, name, __FILE__, __LINE__));\
	}\
		else if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
}


#define CHECK_POINTS_EQUAL(expected,actual)\
{\
    Point3d _expected = (expected); \
    Point3d _actual = (actual); \
    if (!_actual.Equals(_expected)) { \
        char message [256];\
        sprintf (message, "expected point (%f, %f, %f) but was: (%f, %f, %f)", \
                _expected.x, _expected.y, _expected.z,\
                _actual.x, _actual.y, _actual.z); \
        result_.addFailure (Failure (message, name, __FILE__, __LINE__));\
    }\
		else if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
}


#define CHECK_STRINGS_EQUAL(expected,actual)\
{\
    std::string _expected(expected);\
    std::string _actual(actual);\
    if (_expected != _actual) {\
        std::string msg = std::string("expected '") + _expected + \
                            std::string("' but was: '") + _actual + "'"; \
        result_.addFailure (Failure (msg.c_str(), name, __FILE__, __LINE__));\
    }\
		else if (result_.debug)\
		    printf("%s (%s line:%d) \n","Pass:\t"#__VA_ARGS__,FILE_S,__LINE__);\
}




#endif // DONT_CATCH_EXCEPTIONS


#endif



