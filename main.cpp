#include "gtestlite/TestHarness.h"
#include "gtestlite/TestResultStdErr.h"
#include "gtestlite/TestResult.h"
#include "gtestlite/Queue.cpp"
#include "gtestlite/MyTestClass.h"
#include "gtestlite/MyTest.cpp"

using namespace std;
TEST(array_test,one) {
        const float oned[2] = { 110, 20 };
        const float one[3] = { 10,20, 20 };
    CHECK_ARRAY_EQUAL(one, oned, 2);

}

TEST(throw_test,one) {
    struct TestException {};
    CHECK_THROW(throw TestException(), TestException); // succeeds
}

TEST(array_test,two) {
        const float oned[2] = { 10, 20 };
        const float one[3] = { 10,20, 20 };
    CHECK_ARRAY_EQUAL(one, oned, 2,"2");

}


TEST(array_test,three) {
        const float oned[2] = { 10, 20 };
        const float one[3] = { 10,20, 20 };
    CHECK_ARRAY_EQUAL(one, oned, 3,"3");

}

TEST (CHECK_CLOSE,MyTest2)
{

    CHECK_CLOSE(1,13,3,"12.2,13,1");
}

TEST (CHECK_CLOSE,MyTest1)
{
    float fnum = 1.0000f;
    CHECK_CLOSE(12.2,13,1,"12.2,13,1");
}

namespace check{

        float fnum = 1.1;
        TEST (CHECK,MyTest1)
        {

                CHECK ( fnum!=22  );
        }

        TEST (CHECK,MyTest3)
        {
                float fnum = 1.0000f;
                CHECK ((fnum==0x10) );
        }

        TEST (CHECK,MyTest4)
        {
                printf("fnum=    %f\n",fnum);
                CHECK (fnum==1.1f,"fnum==1.1");
        }

        TEST (CHECK,MyTest5)
        {
                float fnum = 1.0000f;
                CHECK (("abcd"=="abc"),"abcd==abc");
        }
}

namespace first{
        float fnum = 2.0000f;

        TEST (Double,MyTest1){
                CHECK_DOUBLES_EQUAL (fnum, 2.0f);
        }
        TEST (Double,MyTest2){
                float fnum = 1.1000f;
                CHECK_DOUBLES_EQUAL (fnum, 1.0222f);
        }
        TEST (Double,MyTest5){
                CHECK_DOUBLES_EQUAL (fnum, 2.0f);
        }
}

int foo(int a){

return a+2;
}

TEST (AAA,AAA)
{
    CHECK (3==foo(1),"3==foo(1)");
}

TEST (CHECK_STRINGS_EQUAL,MyTest1)
{
    CHECK_STRINGS_EQUAL((char const*)"SCEA","USA","USA==USA");
}
TEST (CHECK_STRINGS_EQUAL,MyTest2)
{
    char const* ref="scea";
    char const* tar="SCEA";
    CHECK_STRINGS_EQUAL(ref,tar);
}

TEST (check_eq,one) {
    CHECK_EQUAL("US","USA");
}

TEST (check_eq,two) {
    CHECK_EQUAL("US","1","tiugugu");
}

TEST (check_eq,three) {
        const char* ref="scea";
        const char* tar="SCEA";
    CHECK_EQUAL(ref,tar,"scea=SCEA??");
}

 TEST (check_eq,four) {
        const char* tar="SCEA";
    CHECK_EQUAL((const char*)"SCEA",tar,"scea=SCEA??");
}

class QueueTestSetup : public TestSetup{
protected:
  void setup()
  {
    q1_.enqueue(1);
    q2_.enqueue(2);
    q2_.enqueue(3);
  }
  void teardown(){}
  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};
// 测试默认构造函数
TESTWITHSETUP (QueueTest, IsEmptyInitially) {
  CHECK_EQUAL(0, q0_.size());
}

// 测试入队+扩容
TESTWITHSETUP (QueueTest, EnqueueWorks) {
  q1_.enqueue(2);
  q1_.enqueue(3);
  q1_.enqueue(4);
  int* n = q1_.dequeue();
  CHECK(n != NULL);
  CHECK_EQUAL(1, *n); 
  n = q1_.dequeue();
  CHECK(n != NULL);
  CHECK_EQUAL(2, *n);
  n = q1_.dequeue();
  CHECK(n != NULL);
  CHECK_EQUAL(3, *n);
  n = q1_.dequeue();
  CHECK(n != NULL);
  CHECK_EQUAL(4, *n);
  q1_.enqueue(1);
}

// 测试为空判断 
TESTWITHSETUP (QueueTest, IsEmptyWorks) {
  CHECK(q1_.isEmpty() == false);
  int* n = q1_.dequeue();
  CHECK(q1_.isEmpty() == true);
  q1_.enqueue(1);
}

// 测试队列大小
TESTWITHSETUP (QueueTest, SizeWorks) {
  CHECK_EQUAL(1, q1_.size());
  CHECK_EQUAL(2, q2_.size()); 
  q2_.enqueue(4);
  CHECK_EQUAL(3, q2_.size());
  q2_.enqueue(5);
  CHECK_EQUAL(4, q2_.size()); 
}

// 测试出队列
TESTWITHSETUP (QueueTest, DequeueWorks) {
  int* n = q0_.dequeue();
  CHECK_EQUAL(NULL, n);

  n = q1_.dequeue();
  CHECK(n != NULL);
  CHECK_EQUAL(1, *n);
  CHECK_EQUAL(0, q1_.size());

  n = q2_.dequeue();
  CHECK(n != NULL);
  CHECK_EQUAL(2, *n);
  CHECK_EQUAL(1, q2_.size());
}

// 测试对列头
TESTWITHSETUP (QueueTest, PeekWorks) {
  int* n = q0_.peek();
  CHECK_EQUAL(NULL, n);

  n = q1_.peek();
  CHECK(n != NULL);
  CHECK_EQUAL(1, *n);
  CHECK_EQUAL(1, q1_.size());

  n = q2_.peek();
  CHECK(n != NULL);
  CHECK_EQUAL(2, *n);
  CHECK_EQUAL(2, q2_.size());
}

// 测试清空
TESTWITHSETUP (QueueTest, ClearWorks) {
  int* n = q1_.peek();
  CHECK_EQUAL(1, *n);
  q1_.clear();
  n = q1_.peek();
  CHECK_EQUAL(NULL, n);
}


class MyFixtureSetup : public TestSetup
{

public:
    void setup()
    {
	list.enqueue(1);
	list.enqueue(2);
	list.dequeue();
        someValue = 2.0;
        str = "Hello";
    }

    void teardown()
    {
	//list.~Queue();
    }

protected:
    Queue<int> list;
    float someValue;
    std::string str;
    const float oned[2]={110,20};
    const float one[3]={10,11,12};
    bool check = true;
    long long num = 12345678998;
};

class MyTestSetup: public TestSetup
{
public:
    void setup(){}
    void teardown(){}
protected:
    MyTest mt;
};

TESTWITHSETUP (MyTest, MyTest)
{
	int test1=mt.run(0,10);
	CHECK_EQUAL (0,test1);
	int test2=mt.run(0,-1);
	CHECK_EQUAL (-1,test2);
	int test3=mt.run(-2,10);
	CHECK_EQUAL (1,test3);
	int test4=mt.run(-10,10);
	CHECK_EQUAL (1,test4);
}

TESTWITHSETUP (MyTest, MyTest3)
{
	int inputn[4]={3,10,6,7};
	int maxint[4]={100,5,21};
	int output[4]={6,-1,21,-1};
	for (int i=0; i<4; ++i) {
		int test=mt.run(inputn[i],maxint[i]);
		CHECK_EQUAL (output[i],test);
	}
}

TESTWITHSETUP (MyFixture,Test1)
{
    CHECK_EQUAL (1, list.size());
    CHECK_EQUAL (1,*list.peek());
    list.enqueue(2);
    list.enqueue(3);
    list.enqueue(4);
    list.enqueue(5);
    list.enqueue(6);
    list.enqueue(7);
    list.enqueue(8);
    list.enqueue(9);
    list.enqueue(10);
    CHECK_EQUAL (10,list.size());
    list.enqueue(11);
    CHECK_EQUAL (11,list.size());

    CHECK ( someValue<=22  );
    CHECK (check==true);  
    someValue = 1.0000f;
    CHECK ((someValue==0x10) );
    CHECK (str=="Hello");
    CHECK_DOUBLES_EQUAL (someValue, 2.0f,"2.0=2.0");
    CHECK_EQUAL(str,"USA");
    CHECK_EQUAL(str,"1","tiugugu");
    CHECK_EQUAL(str,"hello");
    CHECK_STRINGS_EQUAL(str,"Hello");
    CHECK_ARRAY_EQUAL(one, oned, 2,"hello");
    CHECK_ARRAY_EQUAL(one, oned, 2,"2");
    CHECK_ARRAY_EQUAL(one, oned, 3,"3");
    CHECK_CLOSE(someValue,13,3);
    struct TestException {};
    CHECK_THROW(throw TestException(), TestException,"hello");
    CHECK_LONGS_EQUAL(num, 12);
}

TESTWITHSETUP (MyFixture,Test2)
{
    CHECK_DOUBLES_EQUAL (someValue, 2.0f);
    CHECK_STRINGS_EQUAL (str, std::string("Hello"));
    str="SCEA";
}



int main()
{   
    TestResultStdErr result(true);
    //TestResult result;
    //TestRegistry::runAllTests(result);
    //TestRegistry::runTestsbyFullName(result,"QueueTest","IsEmptyInitially");
    TestRegistry::runTestsbySuite(result,"QueueTest");
    //result.getTotalTestCases();
}

