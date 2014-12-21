#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
        float *mat;
        int sizeX, sizeY;
    public:
        Matrix(int, int);
        ~Matrix();
        float getVal(int , int) const;
        void setVal(int, int, float);
};

#endif // MATRIX_H
