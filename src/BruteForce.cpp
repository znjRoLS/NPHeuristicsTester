#include "BruteForce.h"

#include <stdio.h>

using namespace std;

BruteForce::BruteForce() : TravelingSalesmanSolver("Brute force solver")
{

}

BruteForce::~BruteForce()
{

}


pair<int*,int> BruteForce::solve(Matrix*mat, double target)
{

    clock_t beginTime = clock();

    int matSize = mat->getSizeX();

    pair<int*,int> currSolution;
    currSolution.first = new int[matSize];
    currSolution.second = matSize;
    double currSolutionScore = 0;

    bool *used = new bool[matSize]();

    int level = 0;
    int lastLevel = 0;

    while (true)
    {
        clock_t endTime = clock();

        double elapsed_secs = double(endTime - beginTime) / CLOCKS_PER_SEC;

        if (elapsed_secs > timeLimit)
            break;

        //didnt find a solution, lets go out
        if (level == -1) break;

        //got to the bottom
        if (level == matSize)
        {
            currSolutionScore += mat->getVal( currSolution.first[0], currSolution.first[matSize-1] );

            if (currSolutionScore <= target)
            {
                return currSolution;
            }

            currSolutionScore -= mat->getVal( currSolution.first[0], currSolution.first[matSize-1] );

            //set lastLevel to matsize, so we should know that we shoul go up
            lastLevel = matSize;
        }

        //return to up level
        if (lastLevel == matSize)
        {
            level--;
            if (level >= 0)
            {
                used[ currSolution.first[level] ] = false;
                lastLevel = currSolution.first[level] + 1;
            }

            if (level > 0)
                currSolutionScore -= mat->getVal( currSolution.first[level - 1], currSolution.first[level] );
        }

        //go down one level
        else
        {
            while(lastLevel < matSize && used[lastLevel]) lastLevel++;

            if (lastLevel == matSize) continue;

            //go down
            used[ lastLevel ] = true;
            currSolution.first[level] = lastLevel;
            if (level > 0)
                currSolutionScore += mat->getVal( currSolution.first[level-1], lastLevel );
            level++;
            lastLevel = 0;

        }
    }

    return pair<int*,int>(nullptr, 0);


}
