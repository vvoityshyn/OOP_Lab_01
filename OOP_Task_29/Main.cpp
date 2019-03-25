#include <iostream>
#include "BinNumber.h"
#include "Main.h"

using namespace std;

/*
29. Створити клас – двійкове число. У закритій частині визначити поля: кількість розрядів та
рядок символів, що відповідає числу. Визначити конструктор, деструктор, функції введення та
виведення числа, додавання та віднімання двійкових чисел.
*/

void TestBinNumberAdd(const char* number1, const char* number2, const char* expectedResult);

int main()
{
	BinNumber *bin = new BinNumber();

	cout << "Initial number: " << bin->GetNumber() << endl;

	char originalNumber[] = "10001";

	bin->SetNumber(originalNumber);

	originalNumber[0] = '0';

	const char* binNumber = bin->GetNumber();


	cout << "Original Number: " << originalNumber << endl;
	cout << "BinNumber: " << binNumber << endl;

	delete bin;

	TestBinNumberAdd("101001", "100111", "1010000");
	//TestBinNumberAdd("101001", "101", "101110");

	system("pause");
	return 0;
}

void TestBinNumberAdd(const char* number1, const char* number2, const char* expectedResult)
{
	// Test #2
	BinNumber *bin1 = new BinNumber(8);
	BinNumber *bin2 = new BinNumber(8);

	bin1->SetNumber(number1);
	bin2->SetNumber(number2);

	// expected result: 101110
	bin1->Add(*bin2);

	const char* result = bin1->GetNumber();

	cout << "Expected result: " << expectedResult << endl;
	cout << "Actual   result: " << result << endl;

	delete bin1;
	delete bin2;
}
