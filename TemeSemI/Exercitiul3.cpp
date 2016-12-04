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
static void getInput(Point& pointA, Point& pointB);
static void printAnswer(Point& pointA, Point& pointB);
static bool equivalentPoints(Point& pointA, Point& pointB);
static float calculateSegmentLength(Point& pointA, Point& pointB);
static float calculateSlope(Point& pointA, Point& pointB);

////////////////////////////////////////////////////////////////////////////////
void ex3()
{
	//declare variables
	Point pointA, pointB;

	printf("DESCRIERE:\n");
	printDescription();
	
	printf("INPUT:\n");
	getInput(pointA, pointB);
	
	printf("RASPUNS:\n");
	printAnswer(pointA, pointB);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program care sa citeasca" 
							" de la tastatura coordonatele extremitatilor unui" 
							" segment (2D). Sa se calculeze lungimea si panta" 
							" segmentului dintre cele doua puncte.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(Point& pointA, Point& pointB)
{
	printf("introduceti coordonatele: \n");
	printf("x pentru A: ");
	scanf("%d", &pointA.x);
	printf("y pentru A: ");
	scanf("%d", &pointA.y);
	printf("x pentru B: ");
	scanf("%d", &pointB.x);
	printf("y pentru B: ");
	scanf("%d", &pointB.y);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(Point& pointA, Point& pointB)
{
	float length = 0.f, slope = 0.f;
	if ( false == equivalentPoints(pointA, pointB) )
	{
		length = calculateSegmentLength(pointA, pointB);
		printf("lungimea segmentului : %f", length);
		slope = calculateSlope(pointA, pointB);
		printf("\npanta dreptei : %f", slope);
	}
	else
	{
		printf("cele doua puncte coinicid!");
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
bool equivalentPoints(Point& pointA, Point& pointB)
{
	return ( pointA.x == pointB.x ) &&
		   ( pointA.y == pointB.y ); 
}

////////////////////////////////////////////////////////////////////////////////
float calculateSegmentLength(Point& pointA, Point& pointB)
{
	//segment length is sqrt( (a.x - b.x)^2 + (a.y - b.y)^2 )
	return ( float ) 
		   ( sqrt ( ( pointA.x - pointB.x ) * ( pointA.x - pointB.x ) + 
				    ( pointA.y - pointB.y ) * ( pointA.y - pointB.y ) ) );
}

////////////////////////////////////////////////////////////////////////////////
float calculateSlope(Point& pointA, Point& pointB)
{
	return (float) ( (pointB.y - pointA.y) /
					 (pointB.x - pointA.x) );
}