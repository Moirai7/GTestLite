#include "TestHarness.h"
#include "MyTestClass.h"


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
