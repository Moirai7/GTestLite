#include "TestHarness.h" 
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