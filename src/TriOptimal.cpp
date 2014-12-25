#include "TriOptimal.h"
#include <iostream>

using namespace std;

TriOptimal::TriOptimal(string name): TravelingSalesmanSolver(name)
{
    //ctor
}

TriOptimal::~TriOptimal()
{
    //dtor
}

pair<int*,int> TriOptimal::generateRandomPath(Matrix* mat)
{
    int matSize = mat->getSizeX();
    pair<int*,int> r;
    r.first = new int[matSize];
    r.second = matSize;

    bool used[matSize];

    for (int i = 0; i < matSize ; i++)
        used[i] = false;

    srand(time(NULL));

    for ( int i = 0; i < matSize; i++)
    {
        int randomI = rand() % (matSize - i);

        int v = 0;
        while( used[v] ) v++;
        for ( int h = 0; h < randomI; h++ )
        {
            v++;
            while( used[v] ) v++;
        }

        used[v] = true;

        r.first[i] = v;
    }

    return r;


}

pair<int*,int> TriOptimal::solve(Matrix *mat, double limit)
{
    clock_t beginTime = clock();

    int matSize = mat->getSizeX();

    pair<int*,int> currSolution = generateRandomPath(mat);

    double currSolutionScore = 0;

    for (int i = 1 ; i < matSize ; i++)
        currSolutionScore += mat->getVal( currSolution.first[i-1], currSolution.first[i] );
    currSolutionScore += mat->getVal( currSolution.first[0], currSolution.first[matSize-1] );

    while (true)
    {

        clock_t endTime = clock();

        double elapsed_secs = double(endTime - beginTime) / CLOCKS_PER_SEC;

        if (elapsed_secs > timeLimit)
            break;

        int rand1 = rand() % matSize;
        int rand2 = rand() % matSize;
        int rand3 = rand() % matSize;
        while ( rand2 == rand1 ) rand2 = rand() % matSize;
        while ( rand3 == rand1 || rand3 == rand2 ) rand3 = rand() % matSize;

        if (rand2 < rand1){
            rand2 += rand1;
            rand1 = rand2 - rand1;
            rand2 -= rand1;
        }

        if (rand3 < rand2){
            rand3 += rand2;
            rand2 = rand3 - rand2;
            rand3 -= rand2;
        }

        if (rand2 < rand1){
            rand2 += rand1;
            rand1 = rand2 - rand1;
            rand2 -= rand1;
        }

        pair<int*,int> path1;
        path1.second = rand2 - rand1;
        path1.first = new int[ path1.second ];
        for (int i = 0; i < path1.second ; i++)
            path1.first[i] = currSolution.first[rand1 + 1 + i];

        pair<int*,int> path2;
        path2.second = rand3 - rand2;
        path2.first = new int[ path2.second ];
        for (int i = 0; i < path2.second ; i++)
            path2.first[i] = currSolution.first[rand2 + 1 + i];

        pair<int*,int> path3;
        path3.second = rand1 - rand3 + matSize;
        path3.first = new int[ path3.second ];
        for (int i = 0; i < path3.second ; i++)
            path3.first[i] = currSolution.first[ (rand3 + 1 + i) % matSize];



        int node[3][2];

        node[0][0] = path1.first[0];
        node[0][1] = path1.first[path1.second - 1];
        node[1][0] = path2.first[0];
        node[1][1] = path2.first[path2.second - 1];
        node[2][0] = path3.first[0];
        node[2][1] = path3.first[path3.second - 1];

        double edge[3][2][3][2];

        for (int a1 = 0; a1 < 3; a1++) for(int a2 = 0; a2 < 2; a2++) for (int a3 = 0; a3 < 3; a3++) for(int a4 = 0; a4 < 2; a4++)
            edge[a1][a2][a3][a4] = mat->getVal(node[a1][a2], node[a3][a4]);

        int mini = 0;
        double minx = 1000000000;
        double score;

        for(int a0 = 0 ; a0 < 2; a0++) for (int a1 = 0 ; a1 < 2 ; a1++) for (int a2 = 0 ; a2 < 2 ; a2++)
        {
            score = edge[0][a0][1][1-a1] + edge[1][a1][2][1-a2] + edge[2][a2][0][1-a0];

            if (score < minx)
            {
                minx = score;
                mini = a2;
                mini *= 2;
                mini += a1;
                mini *= 2;
                mini += a0;
            }
        }

        for (int i = 0; i < path1.second; i++)
            currSolution.first[i] = path1.first[i];

        if (mini % 2 == 1)
        {
            if (mini % 4 == 3)
            {
                for (int i = 0; i < path2.second; i++)
                    currSolution.first[ i + path1.second ] = path2.first[i];
            }

            else
            {
                for (int i = 0; i < path2.second; i++)
                    currSolution.first[ path2.second - 1 - i + path1.second ] = path2.first[i];
            }

            if (mini > 4)
            {
                for (int i = 0; i < path3.second; i++)
                    currSolution.first[ path2.second + path1.second + i ] = path3.first[i];
            }
            else
            {
                for (int i = 0; i < path3.second; i++)
                    currSolution.first[ path2.second + path1.second + path3.second - 1 - i ] = path3.first[i];
            }

        }

        else
        {
            if (mini < 3)
            {
                for (int i = 0 ; i < path3.second; i++)
                    currSolution.first[ i + path1.second ] = path3.first[i];
            }
            else
            {
                for (int i = 0 ; i < path3.second; i++)
                    currSolution.first[ path3.second - 1 - i + path1.second ] = path3.first[i];
            }

            if (mini % 4 == 0)
            {
                for (int i = 0; i < path2.second; i++)
                    currSolution.first[ path1.second + path3.second + i] = path2.first[i];
            }
            else
            {
                for (int i = 0; i < path2.second; i++)
                    currSolution.first[ path1.second + path3.second + path2.second - i - 1] = path2.first[i];
            }
        }

        currSolutionScore = 0;
        for (int i = 1 ; i < matSize ; i++)
            currSolutionScore += mat->getVal( currSolution.first[i-1], currSolution.first[i] );
        currSolutionScore += mat->getVal( currSolution.first[0], currSolution.first[matSize-1] );

        if (currSolutionScore <= limit)
            return currSolution;

    }

    return pair<int*,int> (nullptr,0);

}
