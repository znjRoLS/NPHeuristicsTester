#ifndef TESTER_H
#define TESTER_H

#include "TravelingSalesmanSolver.h"
#include "TestGenerator.h"


class Tester
{
        TestGenerator * testGenerator;
        TravelingSalesmanSolver * travelingSalesmanSolver;

    public:
        Tester(TestGenerator*, TravelingSalesmanSolver*);
        virtual ~Tester();

        ostream& test(ostream&, float);
};

#endif // TESTER_H
