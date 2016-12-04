#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& input);
static void printAnswer(int input);
static int** createPascalTriangle(int n);
static int factorial(int n);

////////////////////////////////////////////////////////////////////////////////
void ex20()
{
	int input;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(input);

	printf("RASPUNS:\n");
	printAnswer(input);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program in care se citeste"
				" de la tastatura un numar n de la tastatura. Sa se scrie intr-un"
				" fisier txt matricea triunghiulara a lui Pascal.Pentru n = 5"
				" aceasta matrice este : \n"
				" 1\n"
				" 1 1\n"
				" 1 2 1\n"
				" 1 3 3 1\n"
				" 1 4 6 4 1\n"
				"x(i, j) = x(i - 1, k - 1) + x(i - 1, k)";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& input)
{
	printf("introduceti numarul n : \n");
	scanf("%d", &input);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int input)
{
	FILE *file;
	int** pascalMatrix = createPascalTriangle(input);
	file = fopen("./output/ex20.txt", "wb");
	for (int i = 0; i < input; ++i)
	{
		for (int j = 0; j < input; ++j)
		{
			if (pascalMatrix[i][j] != 0)
			{
				fprintf(file, "%d ", pascalMatrix[i][j]);
			}
		}
		fprintf(file, "\n");
	}
	fclose(file);
	printf("rezultatul il gasiti in ./output/ex20.txt");
	printf("\n");

	//cleanup
	for (int i = 0; i < input; ++i)
	{
		free(pascalMatrix[i]);
	}
	free(pascalMatrix);
}

////////////////////////////////////////////////////////////////////////////////
int** createPascalTriangle(int n)
{
	int** pascalMatrix;
	pascalMatrix = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		pascalMatrix[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			pascalMatrix[i][j] = (j > i) ? 0 : factorial(i) / 
											    ( factorial(j) * factorial(i - j) );
		}
	}
	return pascalMatrix;
}

////////////////////////////////////////////////////////////////////////////////
int factorial(int n)
{
	return (n > 1) ? ( n * factorial(n - 1) ) : 1;
}

