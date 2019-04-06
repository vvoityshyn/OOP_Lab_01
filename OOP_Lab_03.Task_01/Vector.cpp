#include "Vector.h"
#include <iostream>

using namespace std;

void Vector::EnsureDimensionxCorrectness(int dimension) const
{
	if (!(dimension >= 1))
	{
		throw "The specified dimension is not correct";
	}
}

void Vector::EnsureIndexCorrectness(int index) const
{
	if (!(0 <= index) && (index <= this->dimension - 1))
	{
		throw "The index is out of bounds";
	}
}

void Vector::EnsureDimensionEquals(const Vector& v) const
{
	if (!(this->dimension == v.dimension))
	{
		throw "The dimensions of vectors are different";
	}
}

Vector::Vector(int dimension)
{
	cout << "Vector::Vector(int dimension)" << endl;

	// Валідація: генерує помилку, вказана розмірність вектора виходить за допустимі межі
	this->EnsureDimensionxCorrectness(dimension);

	this->dimension = dimension;
	this->coordinates = new double[this->dimension];

	for (int i = 0; i < this->dimension; i++)
	{
		this->coordinates[i] = 0.0;
	}
}

Vector::~Vector()
{
	delete[] this->coordinates;
	cout << "Vector::~Vector()" << endl;
}

double Vector::Abs() const
{
	// Довжина вектора визначається як
	// корінь квадратний з суми квадратів його координат
	double s = 0;
	for (int i = 0; i < this->dimension; i++)
	{
		s += pow(this->coordinates[i], 2);
	}
	return sqrt(s);
}

int Vector::GetDimension() const
{
	return this->dimension;
}

double Vector::Get(int index) const
{
	// Валідація: генерує помилку, якщо індекс виходить за допустимі межі
	this->EnsureIndexCorrectness(index);
	return this->coordinates[index];
}

void Vector::Set(int index, double value)
{
	// Валідація: генерує помилку, якщо індекс виходить за допустимі межі
	this->EnsureIndexCorrectness(index);
	this->coordinates[index] = value;
}

double & Vector::operator[](const int index)
{
	// Валідація: генерує помилку, якщо індекс виходить за допустимі межі
	this->EnsureIndexCorrectness(index);
	return this->coordinates[index];
}

bool operator<(const Vector & v1, const Vector & v2)
{
	double abs1 = v1.Abs();
	double abs2 = v2.Abs();
	return abs1 < abs2;
}

bool operator>(const Vector & v1, const Vector & v2)
{
	double abs1 = v1.Abs();
	double abs2 = v2.Abs();
	return abs1 > abs2;
}

bool operator<=(const Vector & v1, const Vector & v2)
{
	double abs1 = v1.Abs();
	double abs2 = v2.Abs();
	return abs1 <= abs2;
}

bool operator>=(const Vector & v1, const Vector & v2)
{
	double abs1 = v1.Abs();
	double abs2 = v2.Abs();
	return abs1 >= abs2;
}

Vector& Vector::operator+=(const Vector& v)
{
	// Генерує помилку, якщо довжина вказаного вектора відрізняється від довжини поточного вектора
	this->EnsureDimensionEquals(v);

	// додавання відповідних координат векторів
	for (int i = 0; i < this->dimension; i++)
	{
		this->coordinates[i] += v.coordinates[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
	// Генерує помилку, якщо довжина вказаного вектора відрізняється від довжини поточного вектора
	this->EnsureDimensionEquals(v);

	// відніміння відповідних координат векторів
	for (int i = 0; i < this->dimension; i++)
	{
		this->coordinates[i] -= v.coordinates[i];
	}
	return *this;
}

ostream & operator<<(ostream & out, const Vector & v)
{
	out << "[ ";
	for (int i = 0; i < v.GetDimension(); i++)
	{
		out << v.Get(i);
		if (i < v.GetDimension() - 1)
		{
			out << ", ";
		}
	}
	out << " ]";
	return out;
}
