#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <TestGenerator.h>


class RandomSquareGenerator : public TestGenerator
{
    public:
        RandomSquareGenerator(string);
        ~RandomSquareGenerator();
        Matrix* generateTest(int) override;
};

#endif // RANDOMGENERATOR_H
