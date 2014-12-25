#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H
#include <string>
#include "Matrix.h"

using namespace std;

class TestGenerator
{
        string name;
    protected:
        Matrix *mat;

    public:
        TestGenerator(string);
        virtual ~TestGenerator();
        virtual void generateTest(int) = 0;

        Matrix * getTest()
        {
            return mat;
        }

        friend ostream& operator<<(ostream&  out, TestGenerator*t)
        {
            return out << t->name;
        }
};

#endif // TESTGENERATOR_H
