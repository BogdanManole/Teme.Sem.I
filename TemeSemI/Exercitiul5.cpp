#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& firstVal, int& secondVal);
static void printAnswer(int firstVal, int secondVal);
static unsigned int calculateGCD(int firstVal, int secondVal);
static unsigned int findGCD(unsigned int n1, unsigned int n2);

////////////////////////////////////////////////////////////////////////////////
void ex5()
{
	//declare variables
	int firstVal, secondVal;

	printf("DESCRIERE:\n");
	printDescription();
	
	printf("INPUT:\n");
	getInput(firstVal, secondVal);
	
	printf("RASPUNS:\n");
	printAnswer(firstVal, secondVal);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program care sa determine"
							" cel mai mare divizor comun a doua numere intregi"
							" citite de la tastatura utilizand algoritmul lui"
							" Euclid.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& firstVal, int& secondVal)
{
	printf("introduceti primul numar: \n");
	scanf("%d", &firstVal);
	printf("introduceti al doilea numar: \n");
	scanf("%d", &secondVal);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int firstVal, int secondVal)
{
	unsigned int gcd = calculateGCD(firstVal, secondVal);
	if (gcd == 0)
	{
		printf("una din cifrele introduse este zero\n");
	}
	else
	{
		printf("cel mai mare divizor comun : %d", gcd);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
unsigned int calculateGCD(int firstVal, int secondVal)
{
	//ensure we don't have a zero:	
	if ( ( firstVal == 0 ) ||
		 ( secondVal == 0 ) )
	{
		return 0;
	}

	//ensure we have positive values. For example gcd between 
	//-15 & -21 is the same as 15 & 21, -15 & 21, 15 & -21
	firstVal = ( firstVal > 0 ) ? firstVal : -firstVal;
	secondVal = ( secondVal > 0 ) ? secondVal : -secondVal;
	
	return findGCD(firstVal, secondVal);
}

////////////////////////////////////////////////////////////////////////////////
unsigned int findGCD(unsigned int n1, unsigned int n2)
{
	//using recursion, just for fun
	return ( n2 == 0 ) ? n1 : findGCD(n2, (n1 % n2));
}
