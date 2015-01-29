#include "NearestNeighbour.h"
#include <cstring>

using namespace std;

NearestNeighbour::NearestNeighbour() : TravelingSalesmanSolver("Nearest Neighbour")
{
    //ctor
}

NearestNeighbour::~NearestNeighbour()
{
    //dtor
}

pair<int*,int> NearestNeighbour::solve(Matrix*mat, double target)
{

    int matSize = mat->getSizeX();

    pair<int*,int> currSolution;
    currSolution.first = new int[matSize];
    currSolution.second = matSize;
    double currSolutionScore = 0;

    bool used[matSize];

    memset(used, false, sizeof(bool) * matSize);

    for (int i = 0; i < matSize; i++)
    {
        currSolutionScore = 0;
        currSolution.first[0] = i;
        used[i] = true;

        for (int j = 1; j< matSize; j++)
        {
            double minNext = 1000000000;
            int mini = 0;

            for (int h = 0; h < matSize; h++)
                if (! used[h] && mat->getVal(currSolution.first[j-1], h) < minNext )
                    minNext = mat->getVal(currSolution.first[j-1], mini = h);

            currSolutionScore += minNext;
            used[mini] = true;
            currSolution.first[j] = mini;
        }

        currSolutionScore += mat->getVal( currSolution.first[0], currSolution.first[matSize-1] );

        if (currSolutionScore <= target)
            return currSolution;

    }

    return pair<int*,int> (nullptr,0);
}
