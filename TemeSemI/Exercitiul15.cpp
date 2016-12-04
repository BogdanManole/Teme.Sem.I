#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& size, int** arr);
static void printAnswer(int& size, int* arr);
static void selectionSort(int size, int* arr);
static void swap(int &a, int &b);

////////////////////////////////////////////////////////////////////////////////
void ex15()
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
	static const char description[] = "Sa se scrie un program pentru program de"
		" sortare prin selectie: se compara fiecare element (pornind cu"
		" ultimul) cu toate elementele precedente si se fac schimbarile"
		" necesare.Se repeta acest proces pentru un numar de elemente"
		" care scade progresiv.In aceasta varianta se aduce maximul in"
		" ultima pozitie din (sub)vector si se scade indicele ultimului"
		" element la trecerea urmatoare.";
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
	printf("array cu selection sort(maximul in ultima pozitie):\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void selectionSort(int size, int* arr)
{
	for (int i = size - 1; i > 1; --i)
	{
		// assume the max is the first element
		int jMax = i;

		// test against elements after j to find the greatest
		for (int j = i - 1; j > 0; --j)
		{
			//if this element is more, then it is the new maximum
			if (arr[j] > arr[jMax]) jMax = j;
		}

		if (jMax != i)
		{
			swap(arr[i], arr[jMax]);
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
