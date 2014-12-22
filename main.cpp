#include <iostream>
#include "Tester.h"
#include "BruteForce.h"
#include "RandomSquareGenerator.h"

using namespace std;

int main()
{

    TravelingSalesmanSolver * t = new BruteForce("Brute force solver");
    TestGenerator * g = new RandomSquareGenerator("Random test generator");

    Tester *tester = new Tester();

    tester->setTarget(100.0);
    tester->setSize(20);

    tester->test(cout, g, t);

    return 0;
}
