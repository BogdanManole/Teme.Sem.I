#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& size, int** arr);
static void printAnswer(int& size, int* arr);
static void selectionSort(int size, int* arr);
static void swap(int &a, int &b);

////////////////////////////////////////////////////////////////////////////////
void ex14()
{
	//ax^2 + bx + c = 0
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
	static const char description[] = "Sa se scrie un program pentru sortarea"
			" prin selectie: se compara fiecare element cu toate elementele"
			" urmatoare si se fac schimbarile necesare.Se repeta acest proces"
			" pentru un numar de elemente care scade progresiv.In aceasta"
			" varianta se aduce minimul in prima pozitie din(sub)vector si se"
			" mareste indicele primului element la trecerea urmatoare.";
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
void printAnswer(int& size, int* arr)
{
	selectionSort(size, arr);
	printf("array cu selection sort(minim in prima pozitie):\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void selectionSort(int size, int* arr)
{
	for (int i = 0; i < size - 1; ++i)
	{
		// assume the min is the first element
		int jMin = i;

		// test against elements after j to find the smallest
		for (int j = i + 1; j < size; ++j) 
		{
			//if this element is less, then it is the new minimum
			if (arr[j] < arr[jMin]) jMin = j;
		}

		if (jMin != i)
		{
			swap(arr[i], arr[jMin]);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}