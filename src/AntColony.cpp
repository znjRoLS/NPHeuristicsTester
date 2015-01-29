#include "AntColony.h"

AntColony::AntColony() : TravelingSalesmanSolver("Ant Colony")
{
    //ctor
}

AntColony::~AntColony()
{
    //dtor
}


struct Ant
{
    int currCity;
    int* nextCity;

    Ant(int n): nextCity(new int[n]()) {}

}


constexpr double RAND_ANT_APPEAR = 0.1;
constexpr int MAX_ANTS = 50;
constexpr double alfa = 1;
constexpr double beta = 3;


bool antAppear() { return rand()/(RAND_MAX + 1.0) <= RAND_ANT_APPEAR; }


pair<int*,int> AntColony::solve(Matrix* mat, double limit)
{

    clock_t beginTime = clock();

    int n = mat->getSizeX();
    int antsSize = MAX_ANTS + 1 ;
    int* ants = new int[antsSize];

    int fst = 0, lst = 0;
    int currAnts = 0;


     while (true)
    {
        clock_t endTime = clock();

        double elapsed_secs = double(endTime - beginTime) / CLOCKS_PER_SEC;

        if (elapsed_secs > timeLimit)
            break;


        //add new ants
        while(antAppear() && currAnts != MAX_ANTS)
        {
            ants[lst++] = 0;
            currAnts++;
            if (lst == antsSize) lst = 0;
        }

        //iterate ants
        for (int i = fst; i != lst ; i = (i+1) % andsSize)
        {



        }


    }


    return pair<int*,int>(nullptr, 0);

}
