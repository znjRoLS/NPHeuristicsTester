#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
        double *mat;
        int sizeX, sizeY;

    public:
        Matrix(int);
        Matrix(int, int);
        virtual ~Matrix();
        double getVal(int , int) const;
        void setVal(int, int, double);
        int getSizeX(){ return sizeX;};
        int getSizeY(){ return sizeY;};

        double *x,*y;
};

#endif // MATRIX_H
