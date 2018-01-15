#ifndef TESTRESULTSTDERR_H
#define TESTRESULTSTDERR_H

#include "TestResult.h"


class TestResultStdErr : public TestResult
{
public:
    TestResultStdErr(bool d=false);
    virtual void addFailure (const Failure & failure);
    virtual void endTests ();
};


#endif

