#include <iostream>

using namespace std;

template<typename T> int CheckSum(T value);

int main()
{
	int intValue = 0b11010;
	int intCheck = CheckSum(intValue);
	cout << "Check Sum of " << intValue << " is " << intCheck << endl;

	double doubleValue = 13.3;
	int doubleCheck = CheckSum(doubleValue);
	cout << "Check Sum of " << doubleValue << " is " << doubleCheck << endl;

	system("pause");
	return 0;
}

template<typename T> int CheckSum(T value)
{
	int size = sizeof(value);
	int result = 0;

	char* p = (char*)&value;

	char c = 0;
	for (int i = 0; i < size; i++, p++)
	{
		c = *p;
		for (int b = 0; b < 8; b++)
		{
			result += c - ((c >> 1) << 1);
			c = c >> 1;
		}
	}

	return result;
}