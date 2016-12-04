
#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int** lineLengths, int& size_lines, 
					 int** numbers, int& size_numbers);
static void printAnswer(int* lineLengths, int size_lines, 
						int* numbers, int size_numbers);
static void selectionSort(int size, int* arr);
static void swap(int &a, int &b);

////////////////////////////////////////////////////////////////////////////////
void ex22()
{
	int *lineLengths;
	int *numbers;
	int size_lines;
	int size_numbers;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(&lineLengths, size_lines, &numbers, size_numbers);

	printf("RASPUNS:\n");
	printAnswer(lineLengths, size_lines, numbers, size_numbers);

	//cleanup
	free(lineLengths);
	free(numbers);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program in care sa se"
		" citeasca dintr-un fisier o matrice a cu n linii. Fiecare linie"
		" contine un numar specific de elemente.Sa se sorteze ascendent"
		" elementele matricii.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int** lineLengths, int& size_lines, 
			  int** numbers, int& size_numbers)
{
	printf("inputul este citit din fisiererul ./input/ex22.txt\n");
	FILE *file;
	file = fopen("./input/ex22.txt", "rt");
	static const int buf_size = 1024;
	char line[buf_size], *p, *e;
	static const int max_size = 100;//both for lines and for numbers
	int length[max_size];
	int vec[max_size];
	int placeholder;
	size_lines = 0;
	int i = 0;
	size_numbers = 0;
	while (!feof(file))
	{
		fgets(line, buf_size, file);
		p = line;
		for (p = line; ; p = e) 
		{
			placeholder = strtol(p, &e, 10);
			if (p == e)
				break;
			vec[size_numbers] = placeholder;
			i++;
			size_numbers++;
		}
		length[size_lines] = i;
		i = 0;
		size_lines++;
	}
	fclose(file);

	(*lineLengths) = (int*)malloc(sizeof(int) * size_lines);
	(*numbers) = (int*)malloc(sizeof(int) * size_numbers);
	memcpy((*lineLengths), length, sizeof(int) * size_lines);
	memcpy((*numbers), vec, sizeof(int) * size_numbers);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int* lineLengths, int size_lines,
				 int* numbers, int size_numbers)
{
	selectionSort(size_numbers, numbers);
	int index = 0;
	for (int i = 0; i < size_lines; ++i)
	{
		for (int j = 0; j < lineLengths[i]; ++j)
		{
			printf("%d ", numbers[index]);
			index++;
		}
		printf("\n");
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
