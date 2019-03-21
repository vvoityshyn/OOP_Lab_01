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

	void SetNumber(char* number);
	const char* GetNumber();

	void Add(BinNumber &bin);

	int GetLength();
};

