#include <iostream>
using namespace std;

class MyTest
{
public:
	MyTest();
	~MyTest();
	int run(int n, int max);
};

MyTest::MyTest(){
}

MyTest::~MyTest(){
}

int MyTest::run(int n, int maxint){
	int result = 0, i = 0;
	if (n<0) n = -n;
	while(i<n && result<=maxint) {
		i = i+1;
		result = result+i;
	}
	if (result<=maxint) {
		return result;
	} else {
		return -1;
	}
}
