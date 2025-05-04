#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

using namespace matrix;

TEST_CASE("Constructor and size") {
    SquareMat m1(2);
    CHECK(m1.getSize() == 2);

    SquareMat m2({{1, 2}, {3, 4}});
    CHECK(m2.getSize() == 2);
}

TEST_CASE("Element access and modification") {
    SquareMat m({{1, 2}, {3, 4}});
    CHECK(m[0][0] == 1);
    m[1][1] = 10;
    CHECK(m[1][1] == 10);
}

TEST_CASE("Addition and subtraction") {
    SquareMat a({{1, 2}, {3, 4}});
    SquareMat b({{5, 6}, {7, 8}});
    SquareMat c = a + b;
    CHECK(c[0][0] == 6);
    SquareMat d = b - a;
    CHECK(d[1][1] == 4);
}

TEST_CASE("Unary minus operator") {
    SquareMat m({{1, -2}, {-3, 4}});
    SquareMat neg = -m;
    CHECK(neg[0][0] == -1);
    CHECK(neg[0][1] == 2);
    CHECK(neg[1][0] == 3);
    CHECK(neg[1][1] == -4);
}


TEST_CASE("Multiplication") {
    SquareMat a({{1, 2}, {3, 4}});
    SquareMat b({{2, 0}, {1, 2}});
    SquareMat c = a * b;
    CHECK(c[0][0] == 4);
    CHECK(c[1][1] == 8);
}

TEST_CASE("Scalar multiplication and division") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat s = m * 2;
    CHECK(s[1][0] == 6);

    SquareMat d = m / 2;
    CHECK(d[0][1] == 1);
}

TEST_CASE("Modulo operations") {
    SquareMat m({{5.0, 6.0}, {7.0, 8.0}});
    SquareMat mod_s = m % 3;
    CHECK(static_cast<int>(mod_s[0][0]) == 5 % 3);
    SquareMat mod_m = m % m;
    CHECK(mod_m[1][1] == 64);
}

TEST_CASE("Exponentiation") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat pow2 = m ^ 2;
    CHECK(pow2[0][0] == 7);
    SquareMat identity = m ^ 0;
    CHECK(identity[0][0] == 1);
}

TEST_CASE("Transpose") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat t = ~m;
    CHECK(t[0][1] == 3);
}

TEST_CASE("Determinant") {
    SquareMat m({{1, 2}, {3, 4}});
    CHECK(static_cast<int>(!m) == -2);
}

TEST_CASE("Compound assignment") {
    SquareMat m({{1, 2}, {3, 4}});
    SquareMat n({{1, 1}, {1, 1}});
    m += n;
    CHECK(m[0][0] == 2);
    m -= n;
    CHECK(m[0][0] == 1);
    m *= n;
    CHECK(m[0][0] == 3);
    m *= 2;
    CHECK(m[0][0] == 6);
    m %= n;
    CHECK(m[0][0] == 6);
    m %= 2;
    CHECK(static_cast<int>(m[0][0]) == 0);
    m /= 2;
    CHECK(m[0][1] == 0);
}

TEST_CASE("Comparisons") {
    SquareMat a({{1, 2}, {3, 4}});
    SquareMat b({{4, 3}, {2, 1}});
    CHECK(a == b); // same sum
    CHECK(!(a != b));
    SquareMat c({{5, 6}, {7, 8}});
    CHECK(c > a);
    CHECK(a < c);
    CHECK(a <= c);
    CHECK(c >= a);
}
