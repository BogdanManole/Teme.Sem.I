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
static void getInput(Point& pointA);
static void printAnswer(Point& pointA);
static unsigned int getQuadrant(Point& pointA);


////////////////////////////////////////////////////////////////////////////////
void ex8()
{
	//declare variables
	Point pointA;

	printf("DESCRIERE:\n");
	printDescription();
	
	printf("INPUT:\n");
	getInput(pointA);
	
	printf("RASPUNS:\n");
	printAnswer(pointA);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program care citeste"
							" coordonatele(x, y) ale unui punct din plan si"
							" afiseaza numarul cadranului in care se afla"
							" (1, 2, 3, 4).";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(Point& pointA)
{
	printf("introduceti coordonatele: \n");
	printf("x pentru A: ");
	scanf("%d", &pointA.x);
	printf("y pentru A: ");
	scanf("%d", &pointA.y);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(Point& pointA)
{
	unsigned int quadrant = getQuadrant(pointA);
	if (0 != quadrant)
	{
		printf("punctul se afla in cadranul %d", quadrant);
	}
	else
	{
		printf("punctul se afla pe una din axe");
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
unsigned int getQuadrant(Point& pointA)
{
	return ( ( pointA.x > 0 ) && ( pointA.y > 0 ) ) ? 1 :
		   ( ( pointA.x < 0 ) && ( pointA.y > 0 ) ) ? 2 :
		   ( ( pointA.x < 0 ) && ( pointA.y < 0 ) ) ? 3 :
		   ( ( pointA.x > 0 ) && ( pointA.y < 0 ) ) ? 4 : 0;
}
