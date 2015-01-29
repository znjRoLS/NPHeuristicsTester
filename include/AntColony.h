#ifndef ANTCOLONY_H
#define ANTCOLONY_H

#include <TravelingSalesmanSolver.h>


class AntColony : public TravelingSalesmanSolver
{
    public:
        AntColony();
        ~AntColony();

        pair<int*,int> solve(Matrix* mat, double limit) override;
};

#endif // ANTCOLONY_H
