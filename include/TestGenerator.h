#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H
#include <string>
#include "Matrix.h"

using namespace std;

class TestGenerator
{
        string name;

    public:
        TestGenerator(string);
        virtual ~TestGenerator();
        virtual Matrix* generateTest(int) = 0;
        friend ostream& operator<<(ostream&  out, TestGenerator*t)
        {
            return out << t->name;
        }
};

#endif // TESTGENERATOR_H
