#ifndef TESTER_H
#define TESTER_H

#include "TravelingSalesmanSolver.h"
#include "TestGenerator.h"


class Tester
{
    double target;
    int problemSize;

    public:
        Tester();
        virtual ~Tester();

        void test(ostream&, TestGenerator*, TravelingSalesmanSolver*);
        void setTarget(double);
        void setSize(int);
};

#endif // TESTER_H
