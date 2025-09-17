#pragma once
#include <vector>
#include <iostream>

class Vector {
private:
    std::vector<double> values;
public:
    Vector(const std::vector<double>& vals);
    std::vector<double> getValues() const;
    void setValues(const std::vector<double>& vals);

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
    Vector operator*(const Vector& other) const;

    static Vector translate(const Vector& v1, const Vector& v2);

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};