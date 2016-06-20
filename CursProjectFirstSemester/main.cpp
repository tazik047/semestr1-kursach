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
	cout << "������� ������ �������" << endl;
	cin >> length;
	if (length <= 0)
	{
		cout << "����� ������� ������ ���� �������������" << endl;
		length = 0;
		return;
	}
	cout << "������� ��� �������� �������:" << endl;
	
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
	cout << "������� ������ �������" << endl;
	cin >> length;	

	if (length <= 0)
	{
		cout << "����� ������� ������ ���� �������������" << endl;
		length = 0;
		return;
	}

	mainArray = new int[length];

	for (int i = 0; i < length; i++)
	{
		mainArray[i] = rand();
	}

	cout << "������ ������������" << endl;
}

void timer(void(*function) (int* m, int l))
{	
	if (!isArrayInitiallized())
	{
		cout << "������ ������" << endl;
		return;
	}

	unsigned int start_time = clock();

	int* tempArray = copyMainArray();
	function(tempArray, length);
	//printArray(tempArray, length);
	delete[] tempArray;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "����� ���������� ����������: " << search_time << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int command = -1;
	length = 0;
	while (command != 0)
	{
		cout << "��������� �������:" << endl;
		cout << "1. ������ ������ ��� ������������" << endl;
		cout << "2. ���������� ��������" << endl;
		cout << "3. ������� ����������" << endl;
		cout << "4. � ������� ����" << endl;
		cout << "5. ����������� ������� ������" << endl;
		cout << "6. ������������� ������ �������� �����" << endl;
		cout << "7. �������� �����" << endl;
		cout << "0. �����" << endl;
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
				cout << "������ ������" << endl;
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