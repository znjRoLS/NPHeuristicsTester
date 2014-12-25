#include "Tester.h"
#include <iostream>

using namespace std;

Tester::Tester()
{

}

Tester::~Tester()
{
    //dtor
}

void Tester::setTarget(double target)
{
    this->target = target;
}


void Tester::test(ostream& out, TestGenerator* testGenerator, TravelingSalesmanSolver* travelingSalesmanSolver)
{

    out << "Testing" <<endl << "Test Generator: " << testGenerator << endl << "Traveling Salesman Solver: " << travelingSalesmanSolver << endl;

    //out << "Generating test input..." <<endl;

    Matrix *mat = testGenerator->getTest();
    /*
    out << "Matrix of weights: " << endl;



    int problemSize = mat->getSizeX();

    for (int i = 0; i < problemSize ; i++)
    {
        for(int j = 0; j< problemSize; j++)
        {
            out << mat->getVal(i,j) << " ";
        }
        out << endl;
    }
*/
    out << endl << "Letting solver to solve for less than target: " << target << endl;

    clock_t begin = clock();
    pair<int*,int> solution = travelingSalesmanSolver->solve(mat, target);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    if (solution.first == nullptr)
    {
        out << "Didn't find any solution !" << endl <<endl << endl << endl;
    }

    else
    {
        out << "Found solution: ";

        double solutionScore = mat->getVal( solution.first[ solution.second -1 ], solution.first[0] );
        for (int i = 0; i < solution.second ; i++)
        {
            out << solution.first[i] << " ";
            if (i > 0)
                solutionScore += mat->getVal( solution.first[i-1], solution.first[i] );
        }

        out << endl << "Solution lenght: " << solutionScore << endl << "Time: " << elapsed_secs << endl <<endl << endl << endl;
    }



}
