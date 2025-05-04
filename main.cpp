#include "SquareMat.hpp"

int main() {
    SquareMat A(2);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    SquareMat B = A ^ 2;

    std::cout << "A:\n" << A;
    std::cout << "A squared:\n" << B;
    std::cout << "Determinant of A: " << !A << '\n';
    std::cout << "Transpose of A:\n" << ~A;

    return 0;
}
