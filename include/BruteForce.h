#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <TravelingSalesmanSolver.h>

using namespace std;

class BruteForce : public TravelingSalesmanSolver
{


    public:
        BruteForce();
        ~BruteForce();

        pair<int*,int> solve(Matrix *mat, double limit) override;
};

#endif // BRUTEFORCE_H
