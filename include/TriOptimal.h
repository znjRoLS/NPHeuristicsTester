#ifndef TRIOPTIMAL_H
#define TRIOPTIMAL_H

#include <TravelingSalesmanSolver.h>


class TriOptimal : public TravelingSalesmanSolver
{

    pair<int*,int> generateRandomPath(Matrix*);

    public:
        TriOptimal();
        ~TriOptimal();

        pair<int*,int> solve(Matrix *mat, double limit) override;
};

#endif // TRIOPTIMAL_H
