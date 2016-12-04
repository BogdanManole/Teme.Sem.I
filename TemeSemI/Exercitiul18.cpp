#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& order, int*** matrix);
static void printAnswer(int& order, int** matrix);
static int calcDiagSum(int& order, int** matrix);
static int calcDiagProd(int& order, int** matrix);
static int calcUpperDiagSum(int& order, int** matrix);

////////////////////////////////////////////////////////////////////////////////
void ex18()
{
	int order;
	int **matrix;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(order, &matrix);

	printf("RASPUNS:\n");
	printAnswer(order, matrix);

	//cleanup
	for (int i = 0; i < order; ++i)
	{
		free(matrix[i]);
	}
	free(matrix);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program in care sa se"
				" citeasca dintr-un fisier o matrice patratica A cu n linii si"
				" coloane pentru care sa se calculeze suma elementelor de pe"
				" diagonala principala, produsul elementelor de pe diagonala"
				" secundara si suma elementelor de deasupra diagonalei principale.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& order, int*** matrix)
{
	printf("inputul este citit din fisiererul ./input/ex18.txt\n");
	FILE *file;
	file = fopen("./input/ex18.txt", "rt");
	//read searched and size from file
	fscanf(file, "ordin matrice : %d", &order);
	(*matrix) = (int**)malloc(sizeof(int*) * order);
	//read vector elements from file
	for (int i = 0; i < order; ++i)
	{
		(*matrix)[i] = (int*)malloc(sizeof(int) * order);
	}
	for (int i = 0; i < order; ++i)
	{
		for (int j = 0; j < order; ++j)
		{
			fscanf(file, "%d", &(*matrix)[i][j]);
		}	
	}
	fclose(file);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int& order, int** matrix)
{
	int sum = calcDiagSum(order, matrix);
	int product = calcDiagProd(order, matrix);
	int upperSum = calcUpperDiagSum(order, matrix);
	printf("suma diagonala principala este : %d", sum);
	printf("\nprodusul diagonalei secundare este : %d", product);
	printf("\nsuma elementelero de deasupra diagonalei este : %d", upperSum);
	printf("\n");
}


////////////////////////////////////////////////////////////////////////////////
int calcDiagSum(int& order, int** matrix)
{
	int sum = 0;
	for (int i = 0; i < order; ++i)
	{
		for (int j = 0; j < order; ++j)
		{
			if (i == j) sum += matrix[i][j];
		}
	}
	return sum;
}

////////////////////////////////////////////////////////////////////////////////
int calcDiagProd(int& order, int** matrix)
{
	int prod = 1;
	for (int i = 0; i < order; ++i)
	{
		for (int j = 0; j < order; ++j)
		{
			if ((i + j) == (order - 1))
			{
				prod *= matrix[i][j];
			}
		}
	}
	return prod;
}

////////////////////////////////////////////////////////////////////////////////
int calcUpperDiagSum(int& order, int** matrix)
{
	int sum = 0;
	for (int i = 0; i < order; ++i)
	{
		for (int j = 0; j < order; ++j)
		{
			if (i == j - 1) sum += matrix[i][j];
		}
	}
	return sum;
}