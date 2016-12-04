#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& coefA, int& coefB, int& coefC);
static void printAnswer(int coefA, int coefB, int coefC);
static int getDelta(int coefA, int coefB, int coefC);

////////////////////////////////////////////////////////////////////////////////
void ex12()
{
	//ax^2 + bx + c = 0
	int coefA, coefB, coefC;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(coefA, coefB, coefC);

	printf("RASPUNS:\n");
	printAnswer(coefA, coefB, coefC);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program pentru rezolvarea"
						"unei ecuatii de gradul 2. Coeficientii se citesc de la"
						"tastatura.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& coefA, int& coefB, int& coefC)
{
	printf("introduceti coeficientul lui x^2:\n");
	scanf("%d", &coefA);
	printf("introduceti coeficientul lui x^1:\n");
	scanf("%d", &coefB);
	printf("introduceti coeficientul lui x^0:\n");
	scanf("%d", &coefC);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int coefA, int coefB, int coefC)
{
	int delta = getDelta(coefA, coefB, coefC);
	float x1, x2;
	if (delta >= 0)
	{
		x1 = (float) ( ( -coefB + sqrt(delta) ) / ( 2 * coefA ) );
		x2 = (float) ( ( -coefB - sqrt(delta) ) / ( 2 * coefA ) );

		printf("\nx1 : %f", x1);
		printf("\nx2 : %f", x2);
	}
	else
	{
		printf("delta < 0, nu exista solutii reale ale ecuatiei");
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
int getDelta(int coefA, int coefB, int coefC)
{
	//delta = b^2 - 4ac
	return (coefB*coefB) - (4*coefA*coefC);
}