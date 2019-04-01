#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
	cout << "Vector::Vector()" << endl;
	this->x = 0;
	this->y = 0;
}

Vector::Vector(double x, double y)
{
	cout << "Vector::Vector(double x, double y)" << endl;
	this->x = x;
	this->y = y;
}

Vector::~Vector()
{
	cout << "Vector::~Vector()" << endl;
}

double Vector::Abs() const
{
	return sqrt(this->x * this->x + this->y * this->y);
}

double Vector::GetX() const
{
	return this->x;
}

double Vector::GetY() const
{
	return this->y;
}

void Vector::SetX(double x)
{
	this->x = x;
}

void Vector::SetY(double y)
{
	this->y = y;
}

double & Vector::operator[](const int index)
{
	if (1 == index)
	{
		return this->x;
	}
	else if (2 == index)
	{
		return this->y;
	}
	else
	{
		throw "The index is out of bounds";
	}
}

bool operator<(const Vector & v1, const Vector & v2)
{
	double abs1 = v1.Abs();
	double abs2 = v2.Abs();
	return abs1 < abs2;
}
