#include "sorts.h"

void merge(int* const A, int const lengthA, int* const B, int const lengthB, int* C)
{
	//��������� ������� ������� A, ����������� nA ���������,
	//  � ������� B, ����������� nB ���������.
	//  ��������� �������� � ������ C.

	int a = 0, b = 0; //������ ������� ��������� � �������� A � B

	while (a + b < lengthA + lengthB) //���� �������� �������� � ��������
	{
		if ((b >= lengthB) || ((a < lengthA) && (A[a] <= B[b])))
		{ //������� ������� �� ������� A
			C[a + b] = A[a];
			++a;
		}
		else { //������� ������� �� ������� B
			C[a + b] = B[b];
			++b;
		}
	}
}

void mergeSort(int* array, int length)
{
	if (length < 2) return; //���������� �� �����

	if (length == 2) //��� �������� ����� �������� �������,
	{            //  ���� �����, ��� ������ �������
		if (array[0] > array[1])
		{
			int temp = array[0];
			array[0] = array[1];
			array[1] = temp;
		}

		return;
	}

	mergeSort(array, length / 2); //��������� ������ ��������
	mergeSort(array + length / 2, length - length / 2); //��������� ������ ��������

	int* tempArr = new int[length]; //���� ������� ��������� �������

	merge(array, length / 2, array + length / 2, length - length / 2, tempArr); //������� �������

	//����������� ���������� ������� � �������� ������:
	for (int i = 0; i < length; ++i)
	{
		array[i] = tempArr[i];
	}

	delete[] tempArr; //������� ��������� �����
}