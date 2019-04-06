#include <iostream>
#include "Vector.h"

using namespace std;

/*
1. Перевантажити операції <, >, =<, => (порівняння векторів за довжиною), + (приєднання другого вектора
до першого), відсортувати масив екземплярів класу векторів за зростанням довжин з
використанням алгоритму сортування обміном, обчислити середню довжину для векторів у
масиві.
*/

// Сортування масиву векторів за їх довжиною
void SortVectorsByAbs(Vector** vectors, int n);
// Обчислення середньої довжини вектора в масиві
double GetVectorsAvgAbs(Vector** vectors, int n);

int main()
{
	Vector v1(2);
	v1[0] = 1.0;
	v1[1] = 1.0;

	Vector v2(2);
	v2[0] = 2.0;
	v2[1] = 2.0;

	/* === Оператори порівняння === */
	cout << "Comparison v1 < v2: " << (v1 < v2) << endl;
	cout << "Comparison v1 <= v2: " << (v1 <= v2) << endl;
	cout << "Comparison v1 > v2: " << (v1 > v2) << endl;
	cout << "Comparison v1 >= v2: " << (v1 >= v2) << endl;


	/* === Оператор індексації === */
	cout << "v1[0] = " << v1[0] << endl;
	cout << "v1[1] = " << v1[1] << endl;

	v1[0] = 3.0;
	v1[1] = 4.0;

	cout << "v1[0] = " << v1[0] << endl;
	cout << "v1[1] = " << v1[1] << endl;

	/* === Додавання векторів === */
	v1 += v2;
	cout << v1 << v2;
	cout << "Vector 1: " << v1 << endl;
	cout << "Vector 2: " << v2 << endl;

	/* === Віднімання векторів === */
	v2 -= v1;
	cout << "Vector 1: " << v1 << endl;
	cout << "Vector 2: " << v2 << endl;

	/* === Сортування масиву векторів === */

	// створення динамічного масиву векторів
	// масив є динамічним масивом вказівників на екзепляри об'єтів векторів
	const int numberOfVectors = 5;
	Vector** vectors = new Vector*[numberOfVectors];

	// створення векторів в масиві
	vectors[0] = new Vector(2);
	vectors[0]->Set(0, 1.0);
	vectors[0]->Set(1, 1.0);

	vectors[1] = new Vector(2);
	vectors[1]->Set(0, 5.0);
	vectors[1]->Set(1, 5.0);

	vectors[2] = new Vector(2);
	vectors[2]->Set(0, 2.0);
	vectors[2]->Set(1, 2.0);

	vectors[3] = new Vector(2);
	vectors[3]->Set(0, 4.0);
	vectors[3]->Set(1, 4.0);

	vectors[4] = new Vector(2);
	vectors[4]->Set(0, 3.0);
	vectors[4]->Set(1, 3.0);

	cout << "Vector array before sorting: " << endl;
	for (int i = 0; i < numberOfVectors; i++)
	{
		cout << i << ": " << *vectors[i] << endl;
	}

	// сортування масиву векторів
	SortVectorsByAbs(vectors, numberOfVectors);

	cout << "Vector array after sorting: " << endl;
	for (int i = 0; i < numberOfVectors; i++)
	{
		cout << i << ": " << *vectors[i] << endl;
	}

	// обчислення середньої довжини вектора в масиві
	double avgAbs = GetVectorsAvgAbs(vectors, numberOfVectors);
	cout << "Average absolute value of the vectors: " << avgAbs << endl;

	// знищення векторів у масиві
	for (int i = 0; i < numberOfVectors; i++)
	{
		delete vectors[i];
	}

	// знищення димамічного масиву векторів
	delete[] vectors;

	system("pause");
	return 0;
}

void SortVectorsByAbs(Vector** vectors, int n)
{
	Vector* temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j <= n - 2; j++)
		{
			if (vectors[j]->Abs() > vectors[j + 1]->Abs())
			{
				temp = vectors[j];
				vectors[j] = vectors[j + 1];
				vectors[j + 1] = temp;
			}
		}
	}
}

double GetVectorsAvgAbs(Vector ** vectors, int n)
{
	double s = 0.0;
	for (int i = 0; i < n; i++)
	{
		s += vectors[i]->Abs();
	}
	double avg = s / ((double)n);
	return avg;
}
