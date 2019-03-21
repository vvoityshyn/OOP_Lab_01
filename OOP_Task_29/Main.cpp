#include <iostream>
#include "BinNumber.h"

using namespace std;

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

	BinNumber *bin1 = new BinNumber(8);
	BinNumber *bin2 = new BinNumber(8);

	char number1[] = "101001";
	char number2[] = "100111";

	bin1->SetNumber(number1);
	bin2->SetNumber(number2);



	system("pause");
	return 0;
}