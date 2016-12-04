#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(unsigned int& limit);
static void printAnswer(unsigned int limit);
static unsigned int findPrimeNumbers(unsigned int limit);
static bool isPrime(unsigned int n);

////////////////////////////////////////////////////////////////////////////////
void ex6()
{
	//declare variables
	unsigned int limit;

	printf("DESCRIERE:\n");
	printDescription();
	
	printf("INPUT:\n");
	getInput(limit);
	
	printf("RASPUNS:\n");
	printAnswer(limit);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program care sa numere"
							" cate numere prime sunt mai mici decat un numar"
							" natural n, citit de la tastatura.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(unsigned int& limit)
{
	printf("introduceti numarul: \n");
	scanf("%d", &limit);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(unsigned int limit)
{
	unsigned int count = findPrimeNumbers(limit);
	printf("pana la numarul %d sunt %d numere prime", limit, count);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
unsigned int findPrimeNumbers(unsigned int limit)
{
	unsigned int temp = 0;
	unsigned int count = 0;
	for (size_t i = 0; i < limit; ++i)
	{
		if (isPrime(i)) count++;
	}
	return count;
}

////////////////////////////////////////////////////////////////////////////////
bool isPrime(unsigned int n)
{
	//taken from https://en.wikipedia.org/wiki/Primality_test
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0) return false;
	if (n % 3 == 0) return false;
	unsigned int i = 5;
	while (i*i <= n)
	{
		if( ( n % i == 0 ) || 
		    ( n % ( i + 2) == 0 ) )
		{
			return false;
		}
		i = i + 6;
	}
	return true;
}

