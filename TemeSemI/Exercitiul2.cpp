#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void printAnswer(int sideAB, int sideAC, int sideBC);
static void getInput(int& sideAB, int& sideAC, int& sideBC);
static bool isTriangle(int sideAB, int sideAC, int sideBC);
static float calculateArea(int sideAB, int sideAC, int sideBC);


////////////////////////////////////////////////////////////////////////////////
void ex2()
{
	//declare variables
	int sideAB = 0, sideAC = 0, sideBC = 0;

	printf("DESCRIERE:\n");
	printDescription();
	
	printf("INPUT:\n");
	getInput(sideAB, sideAC, sideBC);
	
	printf("RASPUNS:\n");
	printAnswer(sideAB, sideAC, sideBC);	
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program care sa citeasca"
								" de la tastatura 3 valori care sa reprezinte"
								" lungimile laturilor unui triunghi.Daca cele"
								" trei valori pot reprezenta laturile unui"
								" triunghi, sa se calculeze aria triunghiului.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& sideAB, int& sideAC, int& sideBC)
{
	printf("introduceti cele trei numere: \n");
	printf("latura AB: ");
	scanf("%d", &sideAB);
	printf("latura AC: ");
	scanf("%d", &sideAC);
	printf("latura BC: ");
	scanf("%d", &sideBC);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int sideAB, int sideAC, int sideBC)
{
	float area = 0.f;
	if (isTriangle(sideAB, sideAC, sideBC))
	{
		area = calculateArea(sideAB, sideAC, sideBC);
		printf("Aria : %f", area);
	}
	else
	{
		printf("valorile introduse nu reprezinta laturile unui triunghi\n");
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
bool isTriangle(int sideAB, int sideAC, int sideBC)
{
	//is a triangle if any side is greater than 0 and sum of any two sides is
	//greater than the third side.
	return	( sideAB > 0 ) &&
			( sideAC > 0 ) &&
			( sideBC > 0 ) &&
			( ( sideAB + sideAC ) > sideBC ) &&
			( ( sideAC + sideBC ) > sideAB ) &&
			( ( sideAB + sideBC ) > sideAC );
}

////////////////////////////////////////////////////////////////////////////////
float calculateArea(int sideAB, int sideAC, int sideBC)
{
	float perimeter = (sideAB + sideAC + sideBC) / 2.f;
	return (float)sqrt(perimeter *
		(perimeter - sideAB) *
		(perimeter - sideAC) *
		(perimeter - sideBC));
}
