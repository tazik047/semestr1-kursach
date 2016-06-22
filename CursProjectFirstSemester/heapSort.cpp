#include <iostream>
#include "sorts.h"

using namespace std;

//  ��������� ����������� ���������� �������� 
//  �� ���������: a[k+1]...a[n]  - �������� 
//  �����:  a[k]...a[n]  - �������� 
void downHeap(int a[], int k, int n) {

	int new_elem;
	int child;
	new_elem = a[k];

	while (2*k + 1 < n) {  		// ���� � a[k] ���� ���� 
		child = 2 * k + 1;
		//  �������� �������� ���� 
		if (child < n && a[child] < a[child + 1])
			child++;
		if (new_elem >= a[child]) break;
		// ����� 
		a[k] = a[child]; 	// ��������� ���� ������ 
		k = child;
	}
	a[k] = new_elem;
}

void heapSort(int* a, int length)
{
	int temp;

	// ������ �������� 
	for (int i = length / 2 - 1; i >= 0; i--) downHeap(a, i, length - 1);

	// ������ a[0]...a[length-1] �������� 

	for (int i = length - 1; i > 0; i--) {
		// ������ ������ � ��������� 
		temp = a[i]; a[i] = a[0]; a[0] = temp;

		// ��������������� ��������������� a[0]...a[i-1] 
		downHeap(a, 0, i - 1);
	}
}