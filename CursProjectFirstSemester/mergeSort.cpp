#include "sorts.h"

void merge(int* const A, int const lengthA, int* const B, int const lengthB, int* C)
{
	//Выполнить слияние массива A, содержащего nA элементов,
	//  и массива B, содержащего nB элементов.
	//  Результат записать в массив C.

	int a = 0, b = 0; //Номера текущих элементов в массивах A и B

	while (a + b < lengthA + lengthB) //Пока остались элементы в массивах
	{
		if ((b >= lengthB) || ((a < lengthA) && (A[a] <= B[b])))
		{ //Копирую элемент из массива A
			C[a + b] = A[a];
			++a;
		}
		else { //Копирую элемент из массива B
			C[a + b] = B[b];
			++b;
		}
	}
}

void mergeSort(int* array, int length)
{
	if (length < 2) return; //Сортировка не нужна

	if (length == 2) //Два элемента проще поменять местами,
	{            //  если нужно, чем делать слияние
		if (array[0] > array[1])
		{
			int temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}

		return;
	}

	mergeSort(array, length / 2); //Сортируем первую половину
	mergeSort(array + length / 2, length - length / 2); //Сортируем вторую половину

	int* tempArr = new int[length]; //Сюда запишем результат слияния

	merge(array, length / 2, array + length / 2, length - length / 2, tempArr); //Слияние половин

	//Копирование результата слияния в исходный массив:
	for (int i = 0; i < length; ++i)
	{
		array[i] = tempArr[i];
	}

	delete[] tempArr; //Удаляем временный буфер
}