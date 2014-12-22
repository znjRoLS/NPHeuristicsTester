#include "RandomSquareGenerator.h"

#include <math.h>

RandomSquareGenerator::RandomSquareGenerator(string name): TestGenerator(name)
{
    //ctor
}

RandomSquareGenerator::~RandomSquareGenerator()
{
    //dtor
}

double dist (double x1, double y1, double x2, double y2)
{
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}

Matrix* RandomSquareGenerator::generateTest(int n)
{
    double *x = new double[n];
    double *y = new double[n];

    /* initialize random seed: */
    srand (time(NULL));

    double scale = 1/sqrt(2);

    for (int i =0; i < n; i++)
    {
        x[i] = (double) rand() / RAND_MAX * scale;
        y[i] = (double) rand() / RAND_MAX * scale;
    }

    Matrix *mat = new Matrix(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat->setVal(i, j, dist(x[i],y[i],x[j],y[j]));

    return mat;
}
