#include <iostream>
#include <locale>
#include "sorts.h"

int* mainArray;
int length;

typedef void(*SORTFUNCTION) (int*, int);

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

void generateRandomMas()
{
	std::cout << "������� ������ �������" << std::endl;
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

	std::cout << "������ ������������" << std::endl;
}

void timer(SORTFUNCTION function)
{	
	if (!isArrayInitiallized())
	{
		std::cout << "������ ������" << std::endl;
		return;
	}

	unsigned int start_time = clock();

	int* tempArray = copyMainArray();
	function(tempArray, length);
	//printArray(tempArray, length);
	delete[] tempArray;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	std::cout << "����� ���������� ����������: " << search_time << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int command = -1;
	while (command != 0)
	{
		std::cout << "��������� �������:" << std::endl;
		std::cout << "1. ������ ������ ��� ������������" << std::endl;
		std::cout << "2. ���������� ��������" << std::endl;
		std::cout << "3. ������� ����������" << std::endl;
		std::cout << "4. � ������� ����" << std::endl;
		std::cout << "5. ����������� ������� ������" << std::endl;
		std::cout << "6. ������������� ������ �������� �����" << std::endl;
		std::cout << "7. �������� �����" << std::endl;
		std::cout << "0. �����" << std::endl;
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
/*
#include <iostream>
#include <conio.h>

using namespace std;

void iswap(int &n1, int &n2)
{
int temp = n1;
n1 = n2;
n2 = temp;
}

int main()
{
int const n = 100;
int a[n];
for ( int i = 0; i < n; ++i ) { a[i] = n - i; cout << a[i] << " "; }
//��������� ������ ��� �����������.
//-----------����������------------//
//��������� ��-�����������. ����� ��������� ��-��������,
//��������� ����� ��������� � ��������, ���������� (����)
int sh = 0; //��������
bool b = false;
for (;;)
{
	b = false;
	for (int i = 0; i < n; i++)
	{
		if (i * 2 + 2 + sh < n)
		{
			if ((a[i + sh] >  a[i * 2 + 1 + sh]) || (a[i + sh] >  a[i * 2 + 2 + sh]))
			{
				if (a[i * 2 + 1 + sh] <  a[i * 2 + 2 + sh])
				{
					iswap(a[i + sh], a[i * 2 + 1 + sh]);
					b = true;
				}
				else if (a[i * 2 + 2 + sh] <  a[i * 2 + 1 + sh])
				{
					iswap(a[i + sh], a[i * 2 + 2 + sh]);
					b = true;
				}
			}
			//�������������� �������� ��� ��������� ���� ���������
			//� ������� ���� �������� ����� ������������� ��������
			//��������� ����� ���� �� ���� ���������
			if (a[i * 2 + 2 + sh] <  a[i * 2 + 1 + sh])
			{
				iswap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
				b = true;
			}
		}
		else if (i * 2 + 1 + sh < n)
		{
			if (a[i + sh] >  a[i * 2 + 1 + sh])
			{
				iswap(a[i + sh], a[i * 2 + 1 + sh]);
				b = true;
			}
		}
	}
	if (!b) sh++; //�������� �������������, ����� �� ������� �����
	//����������� ������ ������
	if (sh + 2 == n) break;
}  //����� ����������


cout << endl << endl;
for (int i = 0; i < n; ++i) cout << a[i] << " ";


getch();
return 0;
}

*/