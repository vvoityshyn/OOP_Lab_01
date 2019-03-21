#include <iostream>
#include "BinNumber.h"
#include "string.h"

using namespace std;

void BinNumber::initNumber()
{
	for (int i = 0; i <= this->length - 2; i++) {
		this->number[i] = '0';
	}
	this->number[this->length - 1] = '\0';
}

BinNumber::BinNumber()
{
	cout << "BinNumber()" << endl;
	this->length = 9;
	this->number = new char[this->length];
	this->initNumber();
}

BinNumber::BinNumber(int length)
{
	cout << "BinNumber(int length)" << endl;
	this->length = length + 1;
	this->number = new char[this->length];
	this->initNumber();
}

BinNumber::~BinNumber()
{
	cout << "~BinNumber()" << endl;
	delete[] this->number;
}

void BinNumber::SetNumber(char * number)
{
	errno_t status = strcpy_s(this->number, this->length, number);
}

const char * BinNumber::GetNumber()
{
	return this->number;
}

void BinNumber::Add(BinNumber & bin)
{

}

int BinNumber::GetLength()
{
	return this->length - 1;
}

