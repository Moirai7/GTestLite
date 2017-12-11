#ifndef __CHECK_H__
#define __CHECK_H__

#include "TestResult.h"
//#include "memStream.h"
#include <sstream>
#include <cstring>

/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// 
template< typename Expected, typename Actual, typename Tolerance >
bool AreClose(Expected const expected, Actual const actual, Tolerance const tolerance) {
    return (actual >= (expected - tolerance)) && (actual <= (expected + tolerance));
}

template< typename Expected, typename Actual, typename Tolerance >
bool CheckClose(Expected const expected, Actual const actual, Tolerance const tolerance, std::string & errorMsg) {
    if (!AreClose(expected, actual, tolerance)) { 
        std::ostringstream oss;
        oss << "Expected " << expected << " +/- " << tolerance << " but was " << actual;
		errorMsg = oss.str();
		return false;
    }
	else {
		return true;
	}
}

/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// 

template< typename Expected, typename Actual >
bool CheckEqual( Expected const expected, Actual const actual, std::string & errorMsg) {
    if ( expected != actual) {  
            std::ostringstream oss;
            oss << "Expected " << expected << " but was " << actual;
			errorMsg = oss.str();
			return false;
		    //MemoryOutStream memstream;
            // memstream << "Expected " << expected << " but was " << actual;
			//result_.addFailure (Failure (oss.str(), theTestName, theFileName, theLineNumber));
            //results.OnTestFailure(details, stream.GetText());
    }  else	 {
		return true;
	}
}

bool CheckEqual(char const* expected, char const* actual, std::string & errorMsg);
bool CheckEqual(char* expected, char* actual, std::string & errorMsg);
bool CheckEqual(char* expected, char const* actual, std::string & errorMsg);
bool CheckEqual(char const* expected, char* actual, std::string & errorMsg);

/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///


template< typename Expected, typename Actual >
bool CheckArrayEqual( Expected const expected, Actual const actual, int const count,std::string & errorMsg ) {
    bool equal = true;
    for (int i = 0; i < count; ++i)
        equal &= (expected[i] == actual[i]);

    if (!equal) {
		std::ostringstream oss;
        oss << "Expected [ ";
        for (int i = 0; i < count; ++i)
            oss << expected[i] << " ";
        oss << "] but was [ ";
        for (int i = 0; i < count; ++i)
            oss << actual[i] << " ";
        oss << "]";
		errorMsg = oss.str();
		return false;
    } else {
		return true;
	}
}


#endif