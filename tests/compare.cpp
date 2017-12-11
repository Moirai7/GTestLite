
#include "TestHarness.h"

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



int foo(int a){

return a+2;
}

TEST (AAA,AAA)
{
    CHECK (3==foo(1),"3==foo(1)");
}	