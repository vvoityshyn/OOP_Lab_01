#pragma once

class BinNumber
{
private:
	int length;
	char *number;
	void initNumber();
public:
	BinNumber();
	BinNumber(int length);
	~BinNumber();

	void SetNumber(const char* number);
	const char* GetNumber();

	void Add(const BinNumber &bin);

	int GetLength();
};

