#include <iostream>
#include <locale>
#include "sorts.h"

using namespace std;

int* mainArray;
int length;

bool isArrayInitiallized()
{
	return length!=0;
}

void fillArray()
{
	if (isArrayInitiallized())
	{
		delete[] mainArray;
	}
	cout << "Введите размер массива" << endl;
	cin >> length;
	if (length <= 0)
	{
		cout << "Длина массива должна быть положительная" << endl;
		length = 0;
		return;
	}
	cout << "Введите все элементы массива:" << endl;
	
	mainArray = new int[length];

	for (int i = 0; i < length; i++)
	{
		cin >> mainArray[i];
	}
}

int* copyMainArray()
{
	int* res = new int[length];
	memcpy(res, mainArray, length*sizeof(int));

	return res;
}

void printArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

void generateRandomMas()
{
	if (isArrayInitiallized())
	{
		delete[] mainArray;
	}
	cout << "Введите размер массива" << endl;
	cin >> length;	

	if (length <= 0)
	{
		cout << "Длина массива должна быть положительная" << endl;
		length = 0;
		return;
	}

	mainArray = new int[length];

	for (int i = 0; i < length; i++)
	{
		mainArray[i] = rand();
	}

	cout << "Массив сгенерирован" << endl;
}

void timer(void(*function) (int* m, int l))
{	
	if (!isArrayInitiallized())
	{
		cout << "Массив пустой" << endl;
		return;
	}

	unsigned int start_time = clock();

	int* tempArray = copyMainArray();
	function(tempArray, length);
	//printArray(tempArray, length);
	delete[] tempArray;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "Время выполнения сортировки: " << search_time << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int command = -1;
	length = 0;
	while (command != 0)
	{
		cout << "Доступные команды:" << endl;
		cout << "1. Ввести массив для тестирования" << endl;
		cout << "2. Сортировка слиянием" << endl;
		cout << "3. Быстрая сортировка" << endl;
		cout << "4. С помощью кучи" << endl;
		cout << "5. Распечатать текущий массив" << endl;
		cout << "6. Сгенерировать массив заданной длины" << endl;
		cout << "7. Очистить экран" << endl;
		cout << "0. Выйти" << endl;
		cin >> command;
		switch (command)
		{
		case 1:
			fillArray();
			break;
		case 2:
			timer(mergeSort);
			break;
		case 3:
			timer(quickSort);
			break;
		case 4:
			timer(heapSort);
			break;
		case 5:
			if (!isArrayInitiallized())
			{
				cout << "Массив пустой" << endl;
			}
			else 
			{
				printArray(mainArray, length);
			}
			break;
		case 6:
			generateRandomMas();
			break;
		case 7:
			system("cls");
			break;
		}

		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	}

	return 0;
}