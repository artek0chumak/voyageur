//
// Created by Артем Чумаченко on 07.05.2018.
//

#ifndef VOYAGEUR_TEST_H
#define VOYAGEUR_TEST_H

#include "PathFinder.h"
#include "FlatSpace.h"
#include <iostream>

class Test {
public:
    explicit Test(int seed);
    Test(const Test &test) = default;
    Test& operator=(const Test &test) = default;
    ~Test() = default;

    void run_tests(int from_N, int to_N, int times);
    float get_average();
    float get_sigma();

private:
    int seed;
    float average;
    float sigma;

    void generate(int N, FlatSpace &FS);
};


#endif //VOYAGEUR_TEST_H
