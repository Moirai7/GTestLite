#include "TestHarness.h" 
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
