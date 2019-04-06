#include <iostream>

using namespace std;

#pragma once
class Vector
{
private:
	int dimension; // розмірність вектора
	double* coordinates; // координати вектора

	/*
		Валідація коректності розмірності вектора.
		Допустимі межі для розмірності вектора: 1 <= dimension
	*/
	void EnsureDimensionxCorrectness(int dimension) const;
	/* 
		Валідація коректності індексу координат вектора.
		Допустимі межі для індексу: 0 <= index <= (dimension - 1)
	*/
	void EnsureIndexCorrectness(int index) const;

	/*
		Валідація того, що розмірність вказаного вектора дорівнює довжині поточного вектора.
	*/
	void EnsureDimensionEquals(const Vector& v) const;

public:
	Vector(int dimension);
	~Vector();

	// Довжина (модуль) вектора
	double Abs() const;
	
	// Розмірність вектора (кількість координат)
	int GetDimension() const;

	// Повертає координату вектора за вказаним індексом
	double Get(int index) const;
	// Змінює координату вектора за вказаним індексом
	void Set(int index, double value);

	friend bool operator < (const Vector &v1, const Vector &v2);
	friend bool operator > (const Vector &v1, const Vector &v2);
	friend bool operator <= (const Vector &v1, const Vector &v2);
	friend bool operator >= (const Vector &v1, const Vector &v2);

	double & operator[] (const int index);

	Vector& operator+=(const Vector& right);
	Vector& operator-=(const Vector& right);
	
	friend ostream & operator << (ostream &out, const Vector &v);
};
