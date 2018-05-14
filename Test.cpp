//
// Created by Артем Чумаченко on 07.05.2018.
//

#include "Test.h"
#define PI 3.1415926

Test::Test(int seed): seed(seed), average(0), sigma(0){
}

void Test::run_tests(int from_N, int to_N, int times) {
    float sum_d_weight = 0, sum_sq_d_weight = 0, weight_1, weight_2;
    std::vector<float> d_weight;
    FlatSpace FS;
    for(int i = 0; i < times; i++) {
        for (int N = from_N; N < to_N + 1; N++) {
            std::cout << N << std::endl;
            generate(N, FS);
            std::cout << FS << std::endl;
            PathFinder p(FS);

            weight_1 = 0;
            p.find_path_approx_2();
            std::cout << p << std::endl;
            for (int j = 0; j < N - 1; j++) {
                weight_1 += FS[p.el_path(j)] - FS[p.el_path(j + 1)];
            }
            std::cout << weight_1 << std::endl;
            std::cout << std::endl;

            weight_2 = 0;
            p.find_path_best();
            std::cout << p << std::endl;
            for (int j = 0; j < N - 1; j++) {
                weight_2 += FS[p.el_path(j)] - FS[p.el_path(j + 1)];
            }
            std::cout << weight_2 << std::endl;
            std::cout << std::endl;

            sum_d_weight += weight_1 / weight_2;
            d_weight.push_back(weight_1 / weight_2);
        }
        seed++;
    }

    average = sum_d_weight / (to_N - from_N + 1) / times;
    for(auto i: d_weight) {
        sum_sq_d_weight += pow(average - i, 2);
    }
    sigma = sqrt(sum_sq_d_weight / (to_N - from_N + 1) / times);
}

float Test::get_average() {
    return average;
}

float Test::get_sigma() {
    return sigma;
}

void Test::generate(int N, FlatSpace &FS) {
    FS.clear();
    std::mt19937 twister(seed);
    std::uniform_real_distribution<double> uniformRandom(0, 1);
    for(int i = 0; i < N; i++) {
        auto phi = static_cast<float>(2 * PI * uniformRandom(twister));
        auto r = static_cast<float>(sqrt(-1 * 2 * log(uniformRandom(twister))));
        FS.add_city(City(cos(phi) * r, sin(phi) * r, i));
    }
}
