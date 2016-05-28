#include <iostream>
#include <locale>
#include "sorts.h"

int* mainArray;
int length;

typedef void(*SORTFUNCTION) (int*, int);

bool isArrayInitiallized()
{
	return length!=0;
}

void fillArray()
{
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> length;
	if (length <= 0)
	{
		std::cout << "Длина массива должна быть положительная" << std::endl;
		length = 0;
		return;
	}
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

void generateRandomMas()
{
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> length;

	if (isArrayInitiallized())
	{
		delete[] mainArray;
	}

	mainArray = new int[length];

	for (int i = 0; i < length; i++)
	{
		mainArray[i] = rand();
	}

	std::cout << "Массив сгенерирован" << std::endl;
}

void timer(SORTFUNCTION function)
{	
	if (!isArrayInitiallized())
	{
		std::cout << "Массив пустой" << std::endl;
		return;
	}

	unsigned int start_time = clock();

	int* tempArray = copyMainArray();
	function(tempArray, length);
	//printArray(tempArray, length);
	delete[] tempArray;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	std::cout << "Время выполнения сортировки: " << search_time << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int command = -1;
	length = 0;
	while (command != 0)
	{
		std::cout << "Доступные команды:" << std::endl;
		std::cout << "1. Ввести массив для тестирования" << std::endl;
		std::cout << "2. Сортировка слиянием" << std::endl;
		std::cout << "3. Быстрая сортировка" << std::endl;
		std::cout << "4. С помощью кучи" << std::endl;
		std::cout << "5. Распечатать текущий массив" << std::endl;
		std::cout << "6. Сгенерировать массив заданной длины" << std::endl;
		std::cout << "7. Очистить экран" << std::endl;
		std::cout << "0. Выйти" << std::endl;
		std::cin >> command;
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
				std::cout << "Массив пустой" << std::endl;
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

		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
	}

	return 0;
}