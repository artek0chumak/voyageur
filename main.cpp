#include <iostream>
#include "Test.h"

int main() {
    Test test(420);
    test.run_tests(2, 11, 10);
    std::cout<<test.get_average()<<std::endl;
    std::cout<<test.get_sigma()<<std::endl;

    return 0;
}