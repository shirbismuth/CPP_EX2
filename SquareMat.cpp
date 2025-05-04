
#include "SquareMat.hpp"

namespace matrix {

// --- בנאים ---
SquareMat::SquareMat(int n) : size(n) {
    if (n <= 0) {
        throw std::invalid_argument("Matrix size must be positive");
    }
    data = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));
}

SquareMat::SquareMat(const std::vector<std::vector<double>>& values) {
    int n = values.size();
    if (n == 0)
        throw std::invalid_argument("Matrix cannot be empty");

    for (const auto& row : values) {
        if ((int)row.size() != n)

            throw std::invalid_argument("Matrix is not square");
    }

    size = n;
    data = values;
}

// --- גישה לגודל ---
int SquareMat::getSize() const {
    return size;
}

// --- גישה והוספת איברים ---
std::vector<double>& SquareMat::operator[](int i) {
    if (i < 0 || i >= size)
        throw std::out_of_range("Index out of range");
    return data[i];
}

const std::vector<double>& SquareMat::operator[](int i) const {
    if (i < 0 || i >= size)
        throw std::out_of_range("Index out of range");
    return data[i];
}

// --- אופרטורים מתמטיים ---
SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Size mismatch");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] + other[i][j];
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Size mismatch");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] - other[i][j];
    return result;
}
SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = -data[i][j];
    return result;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Size mismatch");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                result[i][j] += data[i][k] * other[k][j];
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] * scalar;
    return result;
}

SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;  // מפעיל את מה שכבר מימשנו
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) throw std::invalid_argument("Size mismatch");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] * other[i][j];
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = fmod(data[i][j], scalar);
    return result;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) throw std::invalid_argument("Division by zero");
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] / scalar;
    return result;
}

SquareMat SquareMat::operator^(int exponent) const {
    if (exponent < 0) throw std::invalid_argument("Negative exponent not supported");
    if (exponent == 0) {
        SquareMat identity(size);
        for (int i = 0; i < size; ++i)
            identity[i][i] = 1;
        return identity;
    }
    SquareMat result = *this;
    for (int i = 1; i < exponent; ++i) {
        result = result * (*this);
    }
    return result;
}

// --- טרנספוזיציה ---
SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[j][i] = data[i][j];
    return result;
}

// --- דטרמיננטה (רקורסיבי בסיסי) ---
double SquareMat::operator!() const {
    if (size == 1) return data[0][0];
    if (size == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];

    double det = 0.0;
    for (int k = 0; k < size; ++k) {
        SquareMat minor(size - 1);
        for (int i = 1; i < size; ++i) {
            int colIndex = 0;
            for (int j = 0; j < size; ++j) {
                if (j == k) continue;
                minor[i - 1][colIndex++] = data[i][j];
            }
        }
        det += (k % 2 == 0 ? 1 : -1) * data[0][k] * !minor;
    }
    return det;
}

// --- אופרטורי השמה משולבים ---
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    return *this = *this + other;
}

SquareMat& SquareMat::operator-=(const SquareMat& other) {
    return *this = *this - other;
}

SquareMat& SquareMat::operator*=(const SquareMat& other) {
    return *this = *this * other;
}

SquareMat& SquareMat::operator*=(double scalar) {
    return *this = *this * scalar;
}

SquareMat& SquareMat::operator%=(const SquareMat& other) {
    return *this = *this % other;
}

SquareMat& SquareMat::operator%=(int scalar) {
    return *this = *this % scalar;
}

SquareMat& SquareMat::operator/=(double scalar) {
    return *this = *this / scalar;
}

// --- אופרטורי השוואה ---
bool SquareMat::operator==(const SquareMat& other) const {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            sum1 += data[i][j];
            sum2 += other[i][j];
        }
    return sum1 == sum2;
}

bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

bool SquareMat::operator<(const SquareMat& other) const {
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            sum1 += data[i][j];
            sum2 += other[i][j];
        }
    return sum1 < sum2;
}

bool SquareMat::operator>(const SquareMat& other) const {
    return other < *this;
}

bool SquareMat::operator<=(const SquareMat& other) const {
    return !(*this > other);
}

bool SquareMat::operator>=(const SquareMat& other) const {
    return !(*this < other);
}

// --- אופרטור פלט (<<) ---
std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            os << mat.data[i][j];
            if (j < mat.size - 1) os << " ";
        }
        os << '\n';
    }
    return os;
}



} // namespace matrix
