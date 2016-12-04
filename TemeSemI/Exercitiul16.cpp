#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& size, int** arr);
static void printAnswer(int size, int* arr);
static void countSort(int size, int* arr);
static int findMin(int size, int* arr);
static int findMax(int size, int* arr);

////////////////////////////////////////////////////////////////////////////////
void ex16()
{
	int size;
	int *arr;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(size, &arr);

	printf("RASPUNS:\n");
	printAnswer(size, arr);

	//cleanup
	free(arr);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program de sortare prin"
		" numarare: se compara fiecare element cu toate celelalte din vector"
		" si se creeaza un vector auxiliar care contine in pozitia k numarul"
		" elemente din vectorul a mai mici decat a[k].";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& size, int** arr)
{
	printf("introduceti numarul de elemente:\n");
	scanf("%d", &size);
	(*arr) = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
	{
		printf("introduceti elemntul %d : ", i);
		scanf("%d", &(*arr)[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int size, int* arr)
{
	countSort(size, arr);
	printf("array cu count sort:\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void countSort(int size, int* arr)
{
	//allocate memory for count array
	int *bucketArr;
	int idx = 0;
	int min = findMin(size, arr);
	int max = findMax(size, arr);

	int bucketSize = max - min + 1;
	bucketArr = (int*)malloc(sizeof(int) * bucketSize);
	//init all values from bucket to 0
	memset(bucketArr, 0, sizeof(int) * bucketSize);

	for (int i = 0; i < size; ++i)
	{
		bucketArr[arr[i] - min]++;
	}

	for (int i = 0; i <= max; ++i)
	{
		for (int j = 0; j < bucketArr[i - min]; ++j)
		{
			arr[idx] = i;
			idx++;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
int findMin(int size, int* arr)
{
	int min = arr[0];
	for (int i = 1; i < size; ++i)
	{
		min = (arr[i] < min) ? arr[i] : min;
	}
	return min;
}

////////////////////////////////////////////////////////////////////////////////
int findMax(int size, int* arr)
{
	int max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		max = (arr[i] > max) ? arr[i] : max;
	}
	return max;
}
