#include "MyVector.h"

Vector::Vector(const std::vector<double>& vals) : values(vals) {}

std::vector<double> Vector::getValues() const {
    return values;
}

void Vector::setValues(const std::vector<double>& vals) {
    values = vals;
}

Vector Vector::operator+(const Vector& other) const {
    if (values.size() != other.values.size())
        throw std::runtime_error("Vector sizes must match");

    std::vector<double> result(values.size());
    for (size_t i = 0; i < values.size(); ++i)
        result[i] = values[i] + other.values[i];

    return Vector(result);
}

Vector Vector::operator-(const Vector& other) const {
    if (values.size() != other.values.size())
        throw std::runtime_error("Vector sizes must match");

    std::vector<double> result(values.size());
    for (size_t i = 0; i < values.size(); ++i)
        result[i] = values[i] - other.values[i];

    return Vector(result);
}

Vector Vector::operator*(double scalar) const {
    std::vector<double> result(values.size());
    for (size_t i = 0; i < values.size(); ++i)
        result[i] = values[i] * scalar;

    return Vector(result);
}

Vector Vector::operator*(const Vector& other) const {
    if (values.size() != other.values.size())
        throw std::runtime_error("Vector sizes must match");

    std::vector<double> result(values.size());
    for (size_t i = 0; i < values.size(); ++i)
        result[i] = values[i] * other.values[i];

    return Vector(result);
}

Vector Vector::translate(const Vector& v1, const Vector& v2) {
    return v1 + v2;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (size_t i = 0; i < v.values.size(); ++i) {
        os << v.values[i];
        if (i != v.values.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
