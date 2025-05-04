#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <cmath>

namespace matrix {

class SquareMat {
private:
    std::vector<std::vector<double>> data;
    int size;

public:
    // --- בנאים ---
    SquareMat(int n);
    SquareMat(const std::vector<std::vector<double>>& values);

    // --- גישה לגודל ---
    int getSize() const;

    // --- גישה והוספת איברים ---
    std::vector<double>& operator[](int i);
    const std::vector<double>& operator[](int i) const;

    // --- אופרטורים מתמטיים ---
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator-() const;
    SquareMat operator*(const SquareMat& other) const;

    SquareMat operator*(double scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator/(double scalar) const;

    SquareMat operator^(int exponent) const;

    // --- אופרטורי השמה משולבים ---
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);  // כפל מטריצות
    SquareMat& operator*=(double scalar);           // כפל בסקלר
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);
    SquareMat& operator/=(double scalar);

    // --- אופרטורי השוואה ---
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    // --- טרנספוזיציה ---
    SquareMat operator~() const;

    // --- דטרמיננטה ---
    double operator!() const;

  
    SquareMat& operator++();    // ++prefix
    SquareMat operator++(int);  // postfix++
    SquareMat& operator--();    // --prefix
    SquareMat operator--(int);  // postfix--

    // --- פלט ---
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

SquareMat operator*(double scalar, const SquareMat& mat);

} // namespace matrix

#endif
