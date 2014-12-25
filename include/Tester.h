#ifndef TESTER_H
#define TESTER_H

#include "TravelingSalesmanSolver.h"
#include "TestGenerator.h"


class Tester
{
    double target;
    double timeLimit;

    public:
        Tester();
        virtual ~Tester();

        void test(ostream&, TestGenerator*, TravelingSalesmanSolver*);
        void setTarget(double);
};

#endif // TESTER_H
