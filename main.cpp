

#include "gtestlite/TestHarness.h"
#include "gtestlite/TestResultStdErr.h"
#include "MyTestClass.h"


int foo(int a){

return a+2;
}

TEST (AAA,AAA)
{
    CHECK (3==foo(1),"3==foo(1)");
}


class MyFixtureSetup : public TestSetup
{
public:
    void setup()
    {
                //MyTestClass myObject;
        someValue = 2.0;
        str = "Hello";
    }

    void teardown()
    {
                //myObject.~MyTestClass();
    }

protected:
    float someValue;
    std::string str;
    //MyTestClass myObject;
};



TESTWITHSETUP (MyFixture,Test1)
{
    CHECK_DOUBLES_EQUAL (someValue, 2.0f,"2.0=2.0");
    someValue = 0;

    // CppUnitLite doesn't handle system exceptions very well either
   // myObject.UseBadPointer();

    // A regular exception works nicely though
    //myObject.ThrowException();
}

TESTWITHSETUP (MyFixture,Test2)
{
        MyTestClass myObject;
    CHECK_DOUBLES_EQUAL (someValue, 2.0f);
    CHECK_STRINGS_EQUAL (str, std::string("Hello"));
        str="SCEA";
        CHECK_LONGS_EQUAL (1, myObject.s_currentInstances,"CHECK_LONGS_EQUAL (1, myObject.s_currentInstances)");
        //myObject.~MyTestClass();
        //printf("current myObject.s_currentInstances %d\n",myObject.s_currentInstances);
        //myObject.~MyTestClass();
}


TESTWITHSETUP (MyFixture,Test3)
{
        MyTestClass myObject;
    // Unfortunately, it looks like the framework creates 3 instances of MyTestClass
    // right at the beginning instead of doing it on demand for each test. We would
    // have to do it dynamically in the setup/teardown steps ourselves.
        CHECK_STRINGS_EQUAL (str, std::string("Hello"));
        printf("current myObject.s_currentInstances %d\n",myObject.s_currentInstances);

    CHECK_LONGS_EQUAL (1, myObject.s_currentInstances,"CHECK_LONGS_EQUAL (1, myObject.s_currentInstances)");
    CHECK_LONGS_EQUAL (2, myObject.s_instancesCreated,"CHECK_LONGS_EQUAL (2, myObject.s_instancesCreated)");
    CHECK_LONGS_EQUAL (1, myObject.s_maxSimultaneousInstances,"CHECK_LONGS_EQUAL (1, myObject.s_maxSimultaneousInstances)");
        //myObject.~MyTestClass();
}

int main()
{   
    TestResultStdErr result;
    //TestRegistry::runAllTests(result);
	//return (result.getFailureCount());
	//TestRegistry::runTestsbyFullName(result,"MyFixture","Test1");

	///TestRegistry::runTestsbySuite(result,"MyFixture");
	///TestRegistry::runTestsbySuite(result,"Double");
	///TestRegistry::runTestsbySuite(result,"CHECK");
	//TestRegistry::runTestsbyFullName(result,"CHECK","MyTest1");
	///TestRegistry::runTestsbySuite(result,"CHECK_CLOSE");
	//TestRegistry::runTestsbyFullName(result,"MyFixture","Test1");
	 ///TestRegistry::runTestsbySuite(result,"CHECK_STRINGS_EQUAL");

	 TestRegistry::runTestsbySuite(result,"MyFixture");
	 TestRegistry::runTestsbySuite(result,"AAA");
	result.getTotalTestCases();
}

