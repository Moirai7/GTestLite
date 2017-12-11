#include "Checks.h"

using namespace std;

void CheckStringsEqual(char const* expected, char const* actual,  string &errorMsg ) {
    if ( expected == actual ) {
        return  ;
    }
    if ( expected==0 || actual == 0 || strcmp(expected, actual) ) {
        if ( expected == 0 ) {
            expected = "null";
        }
        if ( actual == 0 ) {
            actual = "null";
        }
            std::ostringstream oss;
            oss << "Expected " << expected << " but was " << actual;
			errorMsg = oss.str();
			return  ;
    }
}

 


bool CheckEqual(char const* expected, char const* actual,string &errorMsg)
{
 
	  CheckStringsEqual(expected, actual, errorMsg);
	  if (errorMsg.size()<1){
		  return true;
	  }
	  else{
		  return false;
	  }
	 
}

bool CheckEqual(char* expected, char* actual,std::string &errorMsg)
{
	  CheckStringsEqual(expected, actual, errorMsg);
	  if (errorMsg.size()<1){
		  return true;
	  }
	  else{
		  return false;
	  }
}

bool CheckEqual( char* expected, char const* actual,std::string &errorMsg)
{
	  CheckStringsEqual(expected, actual, errorMsg);
	  if (errorMsg.size()<1){
		  return true;
	  }
	  else{
		  return false;
	  }
}

bool CheckEqual( char const* expected, char* actual,std::string &errorMsg)
{
	  CheckStringsEqual(expected, actual, errorMsg);
	  if (errorMsg.size()<1){
		  return true;
	  }
	  else{
		  return false;
	  }
}
