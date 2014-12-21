#include "Matrix.h"

Matrix::Matrix(int x, int y): sizeX(x), sizeY(y)
{
    mat = new float[x*y];
}

Matrix::~Matrix()
{

}

float Matrix::getVal(int x, int y) const
{
    return mat[x + y*sizeX];
}

void Matrix::setVal(int x, int y, float val)
{
    mat[x + y*sizeX] = val;
}
