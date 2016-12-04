#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& lAMatrix, int& colAMatrix, int& lBMatrix, int& colBMatrix,
						int*** AMatrix, int*** BMatrix);
static void printAnswer(int lAMatrix, int colAMatrix, int lBMatrix, int colBMatrix,
							int** AMatrix, int** BMatrix);
static int** calcMatrixProduct(int lAMatrix, int colAMatrix, int lBMatrix, int colBMatrix,
							int** AMatrix, int** BMatrix);
static bool isMultipliable(int colAMatrix, int lBMatrix);

////////////////////////////////////////////////////////////////////////////////
void ex19()
{
	int lAMatrix, colAMatrix, lBMatrix, colBMatrix;
	int **AMatrix, **BMatrix;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(lAMatrix, colAMatrix, lBMatrix, colBMatrix, &AMatrix, &BMatrix);

	printf("RASPUNS:\n");
	printAnswer(lAMatrix, colAMatrix, lBMatrix, colBMatrix, AMatrix, BMatrix);

	//cleanup
	for (int i = 0; i < colAMatrix; ++i)
	{
		free(AMatrix[i]);
	}
	free(AMatrix);

	for (int i = 0; i < colBMatrix; ++i)
	{
		free(BMatrix[i]);
	}
	free(BMatrix);

}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program in care sa se"
		" citeasca de la tastatura 2 matrici cu m linii si n coloane si"
		" respectiv p linii si q coloane.Daca este posibil, sa se calculeze"
		" produsul celor doua matrici si sa se scrie rezultatul intr-un"
		" fisier txt; altfel afisati un mesaj care sa indice acest lucru.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& lAMatrix, int& colAMatrix, int& lBMatrix, int& colBMatrix,
				int*** AMatrix, int*** BMatrix)
{
	printf("introduceti elementele : \n");
	printf("introduceti numarul de linii pentru matricea A : ");
	scanf("%d", &lAMatrix);
	printf("introduceti numarul de coloane pentru matricea A : ");
	scanf("%d", &colAMatrix);
	//allocate memory for AMatrix
	(*AMatrix) = (int**)malloc(sizeof(int*) * lAMatrix);
	for (int i = 0; i < lAMatrix; ++i)
	{
		(*AMatrix)[i] = (int*)malloc(sizeof(int) * colAMatrix);
	}

	printf("introduceti numarul de linii pentru matricea B : ");
	scanf("%d", &lBMatrix);
	printf("introduceti numarul de coloane pentru matricea B : ");
	scanf("%d", &colBMatrix);
	//allocate memory for BMatrix
	(*BMatrix) = (int**)malloc(sizeof(int*) * lBMatrix);
	for (int i = 0; i < lBMatrix; ++i)
	{
		(*BMatrix)[i] = (int*)malloc(sizeof(int) * colBMatrix);
	}

	printf("introduceti elementele matricei A : \n");
	for (int i = 0; i < lAMatrix; ++i)
	{
		for (int j = 0; j < colAMatrix; ++j)
		{
			scanf("%d", &(*AMatrix)[i][j]);
		}	
	}

	printf("introduceti elementele matricei B : \n");
	for (int i = 0; i < lBMatrix; ++i)
	{
		for (int j = 0; j < colBMatrix; ++j)
		{
			scanf("%d", &(*BMatrix)[i][j]);
		}
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int lAMatrix, int colAMatrix, int lBMatrix, int colBMatrix,
					int** AMatrix, int** BMatrix)
{
	if (isMultipliable(colAMatrix, lBMatrix))
	{
		int** PMatrix = calcMatrixProduct(lAMatrix, colAMatrix, lBMatrix,
										colBMatrix, AMatrix, BMatrix);
		FILE *file;
		file = fopen("./output/ex19.txt", "wb");
		for (int i = 0; i < lAMatrix; ++i)
		{
			for (int j = 0; j < colBMatrix; ++j)
			{
				fprintf(file, "%d ", PMatrix[i][j]);
			}
			fprintf(file, "\n");
		}
		fclose(file);
		for (int i = 0; i < colBMatrix; ++i)
		{
			free(PMatrix[i]);
		}
		free(PMatrix);
		printf("rezultatul il gasiti in ./output/ex19.txt");
	}
	else
	{
		printf("Nu pot inmultii cele doua matrici (numarul de linii a primei"
			"nu este egal cu numarul de coloane a celei de-a doua matrici)\n");
	}
	printf("\n");
}


////////////////////////////////////////////////////////////////////////////////
int** calcMatrixProduct(int lAMatrix, int colAMatrix, int lBMatrix, int colBMatrix,
						int** AMatrix, int** BMatrix)
{
	int** PMatrix;
	int lPMatrix = lAMatrix;
	int colPMatrix = colBMatrix;
	PMatrix = (int**)malloc(sizeof(int*) * lPMatrix);
	for (int i = 0; i < lPMatrix; ++i)
	{
		PMatrix[i] = (int*)malloc(sizeof(int) * colPMatrix);
	}

	for (int i = 0; i < lPMatrix; ++i)
	{
		for (int j = 0; j < colPMatrix; ++j)
		{
			PMatrix[i][j] = 0;
			for (int k = 0; k < colAMatrix; ++k)
			{
				PMatrix[i][j] += AMatrix[i][k] * BMatrix[k][j];
			}
		}
	}
	return PMatrix;
}

////////////////////////////////////////////////////////////////////////////////
bool isMultipliable (int colAMatrix, int lBMatrix)
{
	return (colAMatrix == lBMatrix);
}
