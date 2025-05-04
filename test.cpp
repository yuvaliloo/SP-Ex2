#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

TEST_CASE("Matrix addition") {
    SquareMat A(2), B(2);
    A[0][0] = 1; A[1][1] = 1;
    B[0][1] = 2; B[1][0] = 2;

    SquareMat C = A + B;
    CHECK(C[0][0] == 1);
    CHECK(C[0][1] == 2);
    CHECK(C[1][0] == 2);
    CHECK(C[1][1] == 1);
}

TEST_CASE("Matrix power") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;

    SquareMat B = A ^ 5;
    CHECK(B[0][0] == 8);  
    CHECK(B[0][1] == 5);
}
TEST_CASE("Matrix transpose") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    SquareMat T = ~A;
    CHECK(T[0][0] == 1);
    CHECK(T[0][1] == 3);
    CHECK(T[1][0] == 2);
    CHECK(T[1][1] == 4);
}

TEST_CASE("Determinant 2x2") {
    SquareMat A(2);
    A[0][0] = 4; A[0][1] = 6;
    A[1][0] = 3; A[1][1] = 8;

    CHECK(!A == doctest::Approx(14.0));
}

TEST_CASE("Determinant 3x3") {
    SquareMat A(3);
    A[0][0] = 6; A[0][1] = 1; A[0][2] = 1;
    A[1][0] = 4; A[1][1] = -2; A[1][2] = 5;
    A[2][0] = 2; A[2][1] = 8; A[2][2] = 7;

    CHECK(!A == doctest::Approx(-306.0));
}
TEST_CASE("Matrix equality") {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;  // sum = 10

    SquareMat B(1);
    B[0][0] = 10;  // sum = 10

    SquareMat C(3);  // sum = 0 (default initialized)

    CHECK(A == B);
    CHECK(A != C);
    CHECK(!(A != B));
    CHECK(!(A == C));
}