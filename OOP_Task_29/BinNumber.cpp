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

void BinNumber::SetNumber(const char * number)
{
	errno_t status = strcpy_s(this->number, this->length, number);
}

const char * BinNumber::GetNumber()
{
	return this->number;
}

void BinNumber::Add(const BinNumber & bin)
{
	char* buff = new char[this->length - 1];
	int i1 = strlen(this->number);
	int i2 = strlen(bin.number);
	int k = (i1 > i2 ? i1 : i2);
	int r = 0;
	for (int j = 0; j < k; j++)
	{
		i1 -= 1;
		i2 -= 1;

		if ('1' == this->number[i1])
		{
			r += 1;
		}

		if ('1' == bin.number[i2])
		{
			r += 1;
		}

		if (0 == r)
		{
			buff[j] = '0';
			r = 0;
		}
		else if (1 == r)
		{
			buff[j] = '1';
			r = 0;
		} 
		else if (2 == r)
		{
			buff[j] = '0';
			r = 1;
		}
		else if (3 == r)
		{
			buff[j] = '1';
			r = 1;
		}

		cout << "[Add] " 
			<< "; [ " << i1 << "] = " << this->number[i1] 
			<< "; [ " << i2 << "] = " << bin.number[i2] 
			<< "; [ " << j << "] = " << buff[j] << endl;
	}

	if (1 == r)
	{
		buff[k] = '1';
	}

	for (int l = 0; l <= k; l++)
	{
		this->number[k - l] = buff[l];
	}
	this->number[k + 1] = '\0';

	delete[] buff;
}

int BinNumber::GetLength()
{
	return this->length - 1;
}

