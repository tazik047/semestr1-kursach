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
	std::cout << "������� ������ �������" << std::endl;
	std::cin >> length;
	std::cout << "������� ��� �������� �������:" << std::endl;
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
		std::cout << "��������� �������:" << std::endl;
		std::cout << "1. ������ ������ ��� ������������" << std::endl;
		std::cout << "2. ���������� ��������" << std::endl;
		std::cout << "3. ������� ����������" << std::endl;
		std::cout << "4. � ������� ����" << std::endl;
		std::cout << "5. ����������� ������� ������" << std::endl;
		std::cout << "6. �������� �����" << std::endl;
		std::cout << "0. �����" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case 1:
			fillArray();
			break;
		case 2:
			if (!isArrayInitiallized())
			{
				std::cout << "������ ������" << std::endl;
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
				std::cout << "������ ������" << std::endl;
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
				std::cout << "������ ������" << std::endl;
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