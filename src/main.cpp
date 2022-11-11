#include <iostream>

#include "testable/Testable.hpp"

int main()
{
    std::cout << "Setting up test enviroment" << std::endl;

    prolog::testable::Testable testable;
    testable.start_test();

    std::cout << "Test env teardown" << std::endl;

    return 0;
}
