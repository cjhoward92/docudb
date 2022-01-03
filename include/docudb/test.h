//
// Created by carson on 1/2/22.
//

#ifndef DOCUDB_TEST_H
#define DOCUDB_TEST_H

#include <iostream>

void Call() {
    std::cout << "Calling..." << std::endl;
}

class TestClass {
public:
    TestClass() = default;
    ~TestClass() = default;

    void DoWork() const;
};

#endif //DOCUDB_TEST_H
