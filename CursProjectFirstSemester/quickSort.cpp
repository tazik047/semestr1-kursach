//для вещественных чисел
int partition(int* a, int p, int r)
{
	int x = *(a + r);
	int i = p - 1;
	int j;
	int tmp;
	for (j = p; j < r; j++)
	{
		if (*(a + j) <= x)
		{
			i++;
			tmp = *(a + i);
			*(a + i) = *(a + j);
			*(a + j) = tmp;
		}
	}
	tmp = *(a + r);
	*(a + r) = *(a + i + 1);
	*(a + i + 1) = tmp;
	return i + 1;
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