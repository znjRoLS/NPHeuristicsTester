#ifndef TRAVELINGSALESMANSOLVER_H
#define TRAVELINGSALESMANSOLVER_H
#include <string>

using namespace std;

#include "Matrix.h"

class TravelingSalesmanSolver
{
        string name;
    protected:
        double timeLimit;

    public:
        TravelingSalesmanSolver(string);
        virtual ~TravelingSalesmanSolver();

        virtual pair<int*,int> solve(Matrix* mat, double limit) = 0;

        friend ostream& operator<<(ostream&  out, TravelingSalesmanSolver* t)
        {
            return out << t->name;
        }

        void setTimeLimit(double t)
        {
            timeLimit = t;
        }

};

#endif // TRAVELINGSALESMANSOLVER_H
