#include <iostream>
#include "SquareMat.hpp"

using namespace matrix;

int main() {
    try {
        std::cout << "Creating matrices..." << std::endl;
        SquareMat m1({{1, 2}, {3, 4}});
        SquareMat m2({{4, 3}, {2, 1}});

        std::cout << "Matrix 1:\n" << m1;
        std::cout << "Matrix 2:\n" << m2;

        std::cout << "\nAddition:\n" << m1 + m2;
        std::cout << "Subtraction:\n" << m1 - m2;
        std::cout << "Unary minus:\n" << -m1;
        std::cout << "Multiplication (matrix):\n" << m1 * m2;
        std::cout << "Multiplication (scalar):\n" << m1 * 2;
        std::cout << "Scalar * Matrix:\n" << 2 * m1;
        std::cout << "Element-wise multiplication (%):\n" << m1 % m2;
        std::cout << "Modulo with scalar (%):\n" << m1 % 3;
        std::cout << "Division by scalar:\n" << m1 / 2;

        std::cout << "\nPower (^) m1^2:\n" << (m1 ^ 2);
        std::cout << "Transpose (~m1):\n" << ~m1;
        std::cout << "Determinant (!m1): " << !m1 << std::endl;

        SquareMat m3({{1, 2}, {3, 4}});
        SquareMat m4({{1, 1}, {1, 1}});
        m3 += m4;
        std::cout << "\nm3 += m4:\n" << m3;
        m3 -= m4;
        std::cout << "m3 -= m4:\n" << m3;
        m3 *= m4;
        std::cout << "m3 *= m4:\n" << m3;
        m3 *= 2;
        std::cout << "m3 *= 2:\n" << m3;
        m3 %= m4;
        std::cout << "m3 %= m4:\n" << m3;
        m3 %= 2;
        std::cout << "m3 %= 2:\n" << m3;
        m3 /= 2;
        std::cout << "m3 /= 2:\n" << m3;

        std::cout << "\nComparisons:" << std::endl;
        std::cout << "m1 == m2: " << (m1 == m2) << std::endl;
        std::cout << "m1 != m2: " << (m1 != m2) << std::endl;
        std::cout << "m1 < m2: " << (m1 < m2) << std::endl;
        std::cout << "m1 > m2: " << (m1 > m2) << std::endl;
        std::cout << "m1 <= m2: " << (m1 <= m2) << std::endl;
        std::cout << "m1 >= m2: " << (m1 >= m2) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
