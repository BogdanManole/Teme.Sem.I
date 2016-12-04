#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput();
static void printAnswer();
static unsigned int recurentMethod(unsigned int n, unsigned int k);
static unsigned int factorialMethod(unsigned int n, unsigned int k);
static unsigned int factorial(unsigned int n);

////////////////////////////////////////////////////////////////////////////////
void ex10()
{
	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput();

	printf("RASPUNS:\n");
	printAnswer();
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program pentru calculul"
		" combinarilor de n luate cite m , pentru n=10"
		" si m intre 1 si 10, prin doua metode :\n"
		" (a)Folosind relatia de recurenta :\n"
		" C(n, k) = C(n, k - 1) * (n - k + 1) /"
		" k ptr.k = 1, m si C(n, 0) = 1\n"
		" (b)Folosind relatia de calcul :\n"
		" C(n, m) = n!/ (m!*(n - m)!)";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput()
{
	printf("aceasta problema nu are niciun input!\n");
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer()
{
	unsigned int recurentAnswer;
	unsigned int factorialAnswer;
	for (size_t i = 1; i <= 10; ++i)
	{
		printf("\npentru n = 10 si m = %u", i);
		recurentAnswer = recurentMethod(10, i);
		printf("\nmetoda recurenta are raspunsul %u", recurentAnswer);
		factorialAnswer = factorialMethod(10, i);
		printf("\nmetoda factoriala are raspunsul %u", factorialAnswer);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
unsigned int recurentMethod(unsigned int n, unsigned int k)
{
	//C(n,0) = 1
	if (k == 0) return 1;
	//C(n,k) = C(n,k-1)*(n-k+1)/k pentru k = 1,m
	return (recurentMethod(n, k - 1) * (n - k + 1)) / k;
}

////////////////////////////////////////////////////////////////////////////////
unsigned int factorialMethod(unsigned int n, unsigned int k)
{
	return factorial(n) / (factorial(k) * factorial(n - k));
}

////////////////////////////////////////////////////////////////////////////////
unsigned int factorial(unsigned int n)
{
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}
