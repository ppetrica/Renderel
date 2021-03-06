#ifndef MATH_VEC2_HPP
#define MATH_VEC2_HPP

#include <iostream>

namespace renderel::math {

template <typename T = float>
union Vec2 {
	// Position
	struct {
		T x, y;
	};
	// Texture
	struct {
		T u, v;
	};
	T elements[2];

	Vec2();
	Vec2(T t);
	Vec2(T x, T y);

	void add(const Vec2 &other);
	void sub(const Vec2 &other);
	void mul(const Vec2 &other);
	void div(const Vec2 &other);

	Vec2 &operator+=(const Vec2 &other);
	Vec2 &operator-=(const Vec2 &other);
	Vec2 &operator*=(const Vec2 &other);
	Vec2 &operator/=(const Vec2 &other);

	bool operator==(const Vec2 &other) const;

	Vec2 &operator+=(T t);
	Vec2 &operator-=(T t);
	Vec2 &operator*=(T t);
	Vec2 &operator/=(T t);

	T &operator[](unsigned int index);
	T operator[](unsigned int index) const;
};

template <typename T>
T &Vec2<T>::operator[](unsigned int index) {
	return elements[index];
}

template <typename T>
T Vec2<T>::operator[](unsigned int index) const {
	return elements[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vec2<T> &vec) {
	std::cout << "Vec2(" << vec.x << ", " << vec.y << ")";
	return os;
}

template <typename T>
Vec2<T>::Vec2() : x(0), y(0) {}

template <typename T>
Vec2<T>::Vec2(T t) : x(t), y(t) {}

template <typename T>
Vec2<T>::Vec2(T x, T y) : x(x), y(y) {}

template <typename T>
void Vec2<T>::add(const Vec2<T> &other) {
	x += other.x;
	y += other.y;
}

template <typename T>
void Vec2<T>::sub(const Vec2<T> &other) {
	x -= other.x;
	y -= other.y;
}

template <typename T>
void Vec2<T>::mul(const Vec2<T> &other) {
	x *= other.x;
	y *= other.y;
}

template <typename T>
void Vec2<T>::div(const Vec2<T> &other) {
	x /= other.x;
	y /= other.y;
}

template <typename T>
Vec2<T> &Vec2<T>::operator+=(const Vec2<T> &other) {
	add(other);
	return *this;
}

template <typename T>
bool Vec2<T>::operator==(const Vec2<T> &other) const {
	return x == other.x && y == other.y;
}

template <typename T>
Vec2<T> &Vec2<T>::operator-=(const Vec2<T> &other) {
	sub(other);
	return *this;
}

template <typename T>
Vec2<T> &Vec2<T>::operator*=(const Vec2<T> &other) {
	mul(other);
	return *this;
}

template <typename T>
Vec2<T> &Vec2<T>::operator/=(const Vec2<T> &other) {
	div(other);
	return *this;
}

template <typename T>
Vec2<T> &Vec2<T>::operator+=(T t) {
	x += t;
	y += t;
	return *this;
}

template <typename T>
Vec2<T> &Vec2<T>::operator-=(T t) {
	x -= t;
	y -= t;
	return *this;
}
template <typename T>
Vec2<T> &Vec2<T>::operator*=(T t) {
	x *= t;
	y *= t;
	return *this;
}

template <typename T>
Vec2<T> &Vec2<T>::operator/=(T t) {
	x /= t;
	y /= t;
	return *this;
}

template <typename T>
Vec2<T> operator+(const Vec2<T> &first, const Vec2<T> &second) {
	return {first.x + second.x, first.y + second.y};
}

template <typename T>
Vec2<T> operator-(const Vec2<T> &first, const Vec2<T> &second) {
	return {first.x - second.x, first.y - second.y};
}

template <typename T>
Vec2<T> operator*(const Vec2<T> &first, const Vec2<T> &second) {
	return {first.x * second.x, first.y * second.y};
}

template <typename T>
Vec2<T> operator/(const Vec2<T> &first, const Vec2<T> &second) {
	return {first.x / second.x, first.y / second.y};
}

template <typename T>
Vec2<T> operator+(const Vec2<T> &vec, T t) {
	return {vec.x + t, vec.y + t};
}

template <typename T>
Vec2<T> operator-(const Vec2<T> &vec, T t) {
	return {vec.x - t, vec.y - t};
}

template <typename T>
Vec2<T> operator*(const Vec2<T> &vec, T t) {
	return {vec.x * t, vec.y * t};
}

template <typename T>
Vec2<T> operator/(const Vec2<T> &vec, T t) {
	return {vec.x / t, vec.y / t};
}

template <typename T>
Vec2<T> operator+(T t, const Vec2<T> &vec) {
	return {vec.x + t, vec.y + t};
}

template <typename T>
Vec2<T> operator-(T t, const Vec2<T> &vec) {
	return {t - vec.x, t - vec.y};
}

template <typename T>
Vec2<T> operator*(T t, const Vec2<T> &vec) {
	return {vec.x * t, vec.y * t};
}

template <typename T>
Vec2<T> operator/(T t, const Vec2<T> &vec) {
	return {vec.x / t, vec.y / t};
}

} // namespace renderel::math

#endif // MATH_VEC2_HPP
