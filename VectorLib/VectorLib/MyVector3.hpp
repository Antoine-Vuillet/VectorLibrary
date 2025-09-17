#pragma once
template<typename T>
class MyVector3 {
public:
	T x, y, z;

	MyVector3(T x, T y, T z) : x(x), y(y), z(z) {}
	MyVector3<T> operator+(const MyVector3<T>& other) const {
		return MyVector3<T>(x + other.x, y + other.y, z + other.z);
	}
	MyVector3<T> operator-(const MyVector3<T>& other) const {
		return MyVector3<T>(x - other.x, y - other.y, z - other.z);
	}
	MyVector3<T> operator*(T scalar) const {
		return MyVector3<T>(x * scalar, y * scalar, z * scalar);
	}
	friend std::ostream& operator<<(std::ostream& os, const MyVector3<T>& v) {
		os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return os;
	}
};

struct Direction;
struct Color;

struct Point : public MyVector3<int> {
	using MyVector3::MyVector3;
	Point operator+(const Direction& dir) const;
};

struct Direction : public MyVector3<int> {
	using MyVector3::MyVector3;
};

struct Color : public MyVector3<int>{
	using MyVector3::MyVector3;
};