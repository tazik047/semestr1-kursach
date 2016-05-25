#include <iostream>
#include <locale>
#include "sorts.h"

int* mainArray;
int length;

bool isArrayInitiallized()
{
	return mainArray;
}

void fillArray()
{
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> length;
	std::cout << "Введите все элементы массива:" << std::endl;
	if (isArrayInitiallized())
	{
		delete[] mainArray;
	}

	mainArray = new int[length];

	for (int i = 0; i < length; i++)
	{
		std::cin >> mainArray[i];
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
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int command = -1;
	int* tempArray;
	while (command != 0)
	{
		std::cout << "Доступные команды:" << std::endl;
		std::cout << "1. Ввести массив для тестирования" << std::endl;
		std::cout << "2. Сортировка слиянием" << std::endl;
		std::cout << "3. Быстрая сортировка" << std::endl;
		std::cout << "4. С помощью кучи" << std::endl;
		std::cout << "5. Распечатать текущий массив" << std::endl;
		std::cout << "6. Очистить экран" << std::endl;
		std::cout << "0. Выйти" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case 1:
			fillArray();
			break;
		case 2:
			if (!isArrayInitiallized())
			{
				std::cout << "Массив пустой" << std::endl;
			}
			else 
			{
				tempArray = copyMainArray();
				mergeSort(tempArray, length);
				printArray(tempArray, length);
				delete[] tempArray;
			}
			break;
		case 3:
			if (!isArrayInitiallized())
			{
				std::cout << "Массив пустой" << std::endl;
			}
			else
			{
				tempArray = copyMainArray();
				quickSort(tempArray, length);
				printArray(tempArray, length);
				delete[] tempArray;
			}
			break;
		case 4:
			break;
		case 5:
			if (!isArrayInitiallized())
			{
				std::cout << "Массив пустой" << std::endl;
			}
			else 
			{
				printArray(mainArray, length);
			}
			break;
		case 6:
			system("cls");
			break;
		}

		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	}

	return 0;
}