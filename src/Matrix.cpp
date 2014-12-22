#include "Matrix.h"

Matrix::Matrix(int x): Matrix(x,x)
{

}

Matrix::Matrix(int x, int y): sizeX(x), sizeY(y)
{
    mat = new double[x*y];
}

Matrix::~Matrix()
{

}

double Matrix::getVal(int x, int y) const
{
    return mat[x + y*sizeX];
}

void Matrix::setVal(int x, int y, double val)
{
    mat[x + y*sizeX] = val;
}
