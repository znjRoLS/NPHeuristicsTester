#include "Tester.h"
#include <iostream>

using namespace std;

Tester::Tester(TestGenerator* testGenerator, TravelingSalesmanSolver* travelingSalesmanSolver)
{
    this->testGenerator = testGenerator;
    this->travelingSalesmanSolver = travelingSalesmanSolver;
}

Tester::~Tester()
{
    //dtor
}

ostream& Tester::test(ostream& out, float target)
{

    out << "Testing" <<endl << "Test Generator: " << testGenerator << endl << "Traveling Salesman Solver: " << travelingSalesmanSolver << endl;

    out << "Generating test input..." << endl;

    Matrix *mat = testGenerator->generateTest();

    out << "Letting solver to solve for less than target..." <<endl;

    travelingSalesmanSolver->solve(target);
}
