#pragma once

class Vector {
private:
	double* values;
	int size;
public:
	Vector(double vals[], int size);
	double getValues();
	void setValues(double vals[]);
	Vector operator+(const Vector& other);
	Vector operator-(const Vector& other);
	Vector operator*(double scalar);
	Vector operator*(const Vector& other);
	static Vector translate(const Vector& v1, const Vector& v2);
};