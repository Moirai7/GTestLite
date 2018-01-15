#include <iostream>
using namespace std;

class MyTest
{
public:
	MyTest();
	~MyTest();
	void run(int n, int max);
};

MyTest::MyTest(){
}

MyTest::~MyTest(){
}

void MyTest::run(int n, int maxint){
	int result = 0, i = 0;
	if (n<0) n = -n;
	while(i<n && result<=maxint) {
		i = i+1;
		result = result+i;
	}
	if (result<=maxint) {
		cout<<result;
	} else {
		cout<<"the result is too large!";
	}
	return ;
}
