#include <iostream>
#include "Tester.h"
#include "BruteForce.h"
#include "NearestNeighbour.h"
#include "TriOptimal.h"
#include "RandomSquareGenerator.h"

using namespace std;

int main()
{
    Tester *tester = new Tester();

    double testerTarget;
    cout << "Tester target: ";
    cin >> testerTarget;

    cout << "Tester target set to " << testerTarget << endl;
    tester->setTarget(testerTarget);




    TestGenerator * g = new RandomSquareGenerator("Random test generator");

    int problemSize;
    cout << "Problem size: ";
    cin >> problemSize;

    cout << "Generating test input with " << g << ", size: " << problemSize << endl;
    g->generateTest(problemSize);



    TravelingSalesmanSolver * t = new BruteForce();

    cout << "Set time limit for " << t << " to " << 5.0 <<endl;
    t->setTimeLimit(5.0);
    //tester->setSize();

    tester->test(cout, g, t);



    t = new NearestNeighbour();

    cout << "Set time limit for " << t << " to " << 10.0 <<endl;
    t->setTimeLimit(10.0);

    tester->test(cout, g, t);


     t = new TriOptimal();

    cout << "Set time limit for " << t << " to " << 5.0 <<endl;
    t->setTimeLimit(5.0);

    tester->test(cout, g, t);



    t = new AntColony();

    cout << "Set time limit for " << t << " to " << 5.0 <<endl;
    t->setTimeLimit(5.0);

    tester->test(cout, g, t);

    return 0;
}
