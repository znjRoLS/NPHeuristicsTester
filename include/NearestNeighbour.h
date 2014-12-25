#ifndef NEARESTNEIGHBOUR_H
#define NEARESTNEIGHBOUR_H

#include <TravelingSalesmanSolver.h>


class NearestNeighbour : public TravelingSalesmanSolver
{
    public:
        NearestNeighbour(string);
        ~NearestNeighbour();

        pair<int*,int> solve(Matrix *mat, double limit) override;

};

#endif // NEARESTNEIGHBOUR_H
