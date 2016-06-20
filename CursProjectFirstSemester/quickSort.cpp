// нахождение опорного элемента
int partition(int* a, int p, int r)
{
	int x = a[r];
	int i = p;
	int j;
	int tmp;
	for (j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
		}
	}
	tmp = a[r];
	a[r] = a[i];
	a[i] = tmp;
	return i;
}

void quickSort(int* a, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(a, p, r);
		quickSort(a, p, q - 1);
		quickSort(a, q + 1, r);
	}
}

void quickSort(int* a, int length)
{
	quickSort(a, 0, length - 1);
}