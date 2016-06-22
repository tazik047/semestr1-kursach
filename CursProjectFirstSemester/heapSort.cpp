#include <iostream>
#include "sorts.h"

using namespace std;

//  процедура просеивани€ следующего элемента 
//  ƒо процедуры: a[k+1]...a[n]  - пирамида 
//  ѕосле:  a[k]...a[n]  - пирамида 
void downHeap(int a[], int k, int n) {

	int new_elem;
	int child;
	new_elem = a[k];

	while (2*k + 1 < n) {  		// пока у a[k] есть дети 
		child = 2 * k + 1;
		//  выбираем большего сына 
		if (child < n && a[child] < a[child + 1])
			child++;
		if (new_elem >= a[child]) break;
		// иначе 
		a[k] = a[child]; 	// переносим сына наверх 
		k = child;
	}
	a[k] = new_elem;
}

void heapSort(int* a, int length)
{
	int temp;

	// строим пирамиду 
	for (int i = length / 2 - 1; i >= 0; i--) downHeap(a, i, length - 1);

	// теперь a[0]...a[length-1] пирамида 

	for (int i = length - 1; i > 0; i--) {
		// мен€ем первый с последним 
		temp = a[i]; a[i] = a[0]; a[0] = temp;

		// восстанавливаем пирамидальность a[0]...a[i-1] 
		downHeap(a, 0, i - 1);
	}
}