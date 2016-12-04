#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(unsigned int& input);
static void printAnswer(unsigned int input);
static unsigned int countDigits(unsigned int input);

////////////////////////////////////////////////////////////////////////////////
void ex7()
{
	//declare variables
	unsigned int input;

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
	static const char description[] = "Sa se scrie un program care sa determine"
								" numarului de cifre al unui numar de tip intreg,"
								" citit de la tastatura.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(unsigned int& input)
{
	printf("introduceti numarul: \n");
	scanf("%d", &input);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(unsigned int input)
{
	unsigned int count = countDigits(input);
	printf("numarul %d contine %d cifre", input, count);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
unsigned int countDigits(unsigned int input)
{
	unsigned int count = 0;
	while (input != 0)
	{
		input /= 10;
		count++;
	}
	return count;
}

