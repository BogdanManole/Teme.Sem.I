#include "stdafx.h"
#include "Exercitii.h"

//internal structure
struct Point
{
	int x;
	int y;
};

//internal functions declarations:
static void printDescription();

static void getInput(unsigned int& polinomGrade, 
					 int& givenPoint, 
					 float** polinomValues);

static void printAnswer(unsigned int& polinomGrade, 
						int& givenPoint, 
						float** polinomValues);

static float calculatePolinomValue(unsigned int& polinomGrade,
							int& givenPoint,
							float** polinomValues);


////////////////////////////////////////////////////////////////////////////////
void ex9()
{
	//declare variables
	unsigned int polinomGrade;
	int givenPoint;
	float* polinomValues;

	printf("DESCRIERE:\n");
	printDescription();
	
	printf("INPUT:\n");
	getInput(polinomGrade, givenPoint, &polinomValues);

	printf("RASPUNS:\n");
	printAnswer(polinomGrade, givenPoint, &polinomValues);

	//cleanup
	free(polinomValues);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program care sa calculeze"
								" valoarea unui polinom cu coeficienti intregi"
								" intr-un punct dat.\n"
								" P(x) = a[0] * x^n + a[1] * x ^ (n - 1) + ... +"
										" a[n - 1] * x + a[n]";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(unsigned int& polinomGrade, 
			  int& givenPoint, 
			  float** polinomValues)
{
	printf("introduceti datele de intrare: \n");
	printf("gradul polinomului: ");
	scanf("%ud", &polinomGrade);
	printf("punctul de calcul: ");
	scanf("%d", &givenPoint);
	(*polinomValues) = (float*) malloc(sizeof(float) * polinomGrade);
	for (size_t i = 0; i < polinomGrade; ++i)
	{
		printf("introduceti coeficientul %d :", i);
		scanf("%f", &(*polinomValues)[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(unsigned int& polinomGrade, 
				 int& givenPoint, 
				 float** polinomValues)
{
	float polinomValue = calculatePolinomValue(polinomGrade, 
											   givenPoint, 
											   polinomValues);
	printf("valoarea polinomului este : %f", polinomValue);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
float calculatePolinomValue(unsigned int& polinomGrade,
	int& givenPoint,
	float** polinomValues)
{
	//using Horner's method
	float val = 0.f;
	for (int i = polinomGrade - 1; i >= 0; --i)
	{
		val *= givenPoint;
		val += (*polinomValues)[i];
	}
	return val;
}