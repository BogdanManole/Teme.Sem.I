#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& row, int& column, int*** matrix);
static void printAnswer(int row, int column, int** matrix);
static bool isPrime(int n);

////////////////////////////////////////////////////////////////////////////////
void ex21()
{
	int row, column;
	int **matrix;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(row, column, &matrix);

	printf("RASPUNS:\n");
	printAnswer(row, column, matrix);

	//cleanup
	free(matrix);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program in care sa se"
		" citeasca dintr-un fisier o matrice A cu n linii si m"
		" coloane. Pentru aceasta sa se afle cate linii contin cel"
		" putin un element care este numar prim.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& row, int& column, int*** matrix)
{
	printf("inputul este citit din fisiererul ./input/ex21.txt\n");
	FILE *file;
	file = fopen("./input/ex21.txt", "rt");
	//read searched and size from file
	fscanf(file, "row : %d\ncolumn : %d", &row, &column);
	(*matrix) = (int**)malloc(sizeof(int*) * row);
	//read vector elements from file
	for (int i = 0; i < row; ++i)
	{
		(*matrix)[i] = (int*)malloc(sizeof(int) * column);
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			fscanf(file, "%d", &(*matrix)[i][j]);
		}
	}
	fclose(file);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int row, int column, int** matrix)
{
	int count = 0;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (isPrime(matrix[i][j]))
			{
				count++;
				break;
			}
		}
	}

	printf("numarul de linii cu cel putin un numar prim este : %d", count);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
bool isPrime(int n)
{
	if (n == 1) return false;
	if (n == 2) return true;

	bool result = true;
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}