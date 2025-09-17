#include "MyVector.h"

Vector::Vector(double vals[], int size) {
	this->size = size;
	values = new double[size];
	*values = *vals;
}
double Vector::getValues() {
	return *values;
}
void Vector::setValues(double vals[]) {
	*values = *vals;
}

Vector Vector::operator+(const Vector& other) {
	if (other.size == this->size)
	{
		double* result = new double[size];
		for (int i = 0; i < size; ++i) {
			result[i] = values[i] + other.values[i];
		}
		return Vector(result, size);
	}
	else {
		throw "Vectors must be of the same size";
	}
}

Vector Vector::operator-(const Vector& other) {
	if (other.size == this->size)
	{
		double* result = new double[size];
		for (int i = 0; i < size; ++i) {
			result[i] = values[i] - other.values[i];
		}
		return Vector(result, size);
	}
	else {
		throw "Vectors must be of the same size";
	}
}

Vector Vector::operator*(double scalar) {
	double* result = new double[size];
	for (int i = 0; i < size; ++i) {
		result[i] = values[i] * scalar;
	}
	return Vector(result, size);
}

Vector Vector::operator*(const Vector& other) {
	double* result = new double[size];
	for (int i = 0; i < size; ++i) {
		result[i] = values[i] * other.values[i];
	}
	return Vector(result, size);
}
