#include "TestHarness.h"   
TEST(throw_test,one) {
 
    struct TestException {};
    CHECK_THROW(throw TestException(), TestException,"hello"); // succeeds
}


 