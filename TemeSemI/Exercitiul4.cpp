#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(char& inputChar);
static void printAnswer(char inputChar);
static bool isLetter(char ch);

////////////////////////////////////////////////////////////////////////////////
void ex4()
{
	//declare variables
	char inputChar;

	printf("DESCRIERE:\n");
	printDescription();
	
	printf("INPUT:\n");
	getInput(inputChar);
	
	printf("RASPUNS:\n");
	printAnswer(inputChar);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program care sa verifice" 
					" daca un caracter dat este o litera ( fie mare, fie mica).";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(char& inputChar)
{
	printf("introduceti un caracter: \n");
	inputChar = getchar();
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(char inputChar)
{
	float length = 0.f, slope = 0.f;
	if ( isLetter(inputChar) )
	{
		printf("caracterul introdus este litera.");
	}
	else
	{
		printf("caracterul introdus nu este litera");
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
bool isLetter(char ch)
{
	return ( ( ch >= 'a' ) && ( ch <= 'z' ) ) ||
		   ( ( ch >= 'A' ) && ( ch <= 'Z' ) );
}
