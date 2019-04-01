#pragma once
class Vector
{
private:
	double x;
	double y;
public:
	Vector();
	Vector(double x, double y);
	~Vector();

	double Abs() const;
	
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);


	friend bool operator < (const Vector &v1, const Vector &v2);
	double & operator[] (const int index);
};

