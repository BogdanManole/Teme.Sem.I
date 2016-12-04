#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& size, int& searched, int** arr);
static void printAnswer(int size, int searched, int* arr);
static void countSort(int size, int* arr);
static int findMin(int size, int* arr);
static int findMax(int size, int* arr);
static bool isInArray(int size, int searched, int* arr);

////////////////////////////////////////////////////////////////////////////////
void ex17()
{
	int size, searched;
	int *arr;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(size, searched, &arr);

	printf("RASPUNS:\n");
	printAnswer(size, searched, arr);

	//cleanup
	free(arr);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program pentru cautare"
		" binara intr-un vector ordonat citit dintr-un fisier. Daca vectorul"
		" nu este ordonat, acesta se ordoneaza prin una din metodele descrise"
		" in problemele anterioare. (Cautarea binara se face prin compararea"
		" valorii cautate cu valoarea din mijlocul vectorului cercetat si"
		" alegerea primei sau ultimei jumatati din vector pentru pasul urmator,"
		" in functie de rezultatul comparatiei.Procesul de injumatatire a"
		" vectorului se opreste fie la gasirea valorii cautate, fie la reducerea"
		" dimensiunii pana la 1.)";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& size, int& searched, int** arr)
{
	printf("inputul este citit din fisiererul ./input/ex17.txt\n");
	FILE *file;
	file = fopen("./input/ex17.txt", "rt");
	//read searched and size from file
	fscanf(file, "searched : %d\nsize : %d", &searched, &size);
	(*arr) = (int*)malloc(sizeof(int) * size);
	//read vector elements from file
	for (int i = 0; i < size; ++i)
	{
		fscanf(file, "%d", &(*arr)[i]);
	}
	fclose(file);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int size, int searched, int* arr)
{
	countSort(size, arr);
	if (isInArray(size, searched, arr))
	{
		printf("numarul %d este in vector ", searched);
	}
	else
	{
		printf("numarul %d nu este in vector ", searched);
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

////////////////////////////////////////////////////////////////////////////////
bool isInArray(int size, int searched, int* arr)
{
	bool result = false;
	int middle;
	int first = 0;
	int last = size - 1;

	while (first <= last)
	{
		middle = (first + last) / 2;
		if (arr[middle] == searched)
		{
			result = true;
			break;	
		}
		if (arr[middle] < searched)
		{
			first = middle + 1;
		}
		else
		{
			last = middle - 1;
		}
	}
	return result;
}