//
// Created by carson on 1/2/22.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "docudb/test.h"

TEST_CASE("Test example", "[example]") {
    TestClass test;
    test.DoWork();
    assert(true);
}
