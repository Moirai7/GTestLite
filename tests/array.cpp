
#include "TestHarness.h"   
TEST(array_test,one) {
	const float oned[2] = { 110, 20 };
	const float one[3] = { 10,20, 20 };
    CHECK_ARRAY_EQUAL(one, oned, 2,"hello");
    
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