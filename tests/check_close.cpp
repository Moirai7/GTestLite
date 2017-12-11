#include "TestHarness.h" 

TEST (CHECK_CLOSE,MyTest2)
{
 
    CHECK_CLOSE(1,13,3,"12.2,13,1");
}	

TEST (CHECK_CLOSE,MyTest1)
{
    float fnum = 1.0000f;
    CHECK_CLOSE(12.2,13,1,"12.2,13,1");
}
