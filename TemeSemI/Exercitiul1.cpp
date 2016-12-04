

#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& sideAB, int& sideAC, int& sideBC);
static void printAnswer(int sideAB, int sideAC, int sideBC);
static bool isTriangle(int sideAB, int sideAC, int sideBC);
static float calculateAngle(int opposite, int nearL, int nearR);


////////////////////////////////////////////////////////////////////////////////
void ex1()
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
						 " de la tastatura 3 valori care sa reprezinte lungimile" 
						 " laturilor unui triunghi. Sa se verifice daca aceste"
						 " laturi pot fi laturile unui triunghi, si, daca acest"
						 " lucru este adevarat, sa se calculeze unghiurile "
						 " triunghiului (in grade).";
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
	float angleA = 0.f, angleB = 0.f, angleC = 0.f;
	if (isTriangle(sideAB, sideAC, sideBC))
	{
		angleA = calculateAngle(sideBC, sideAC, sideAB);
		angleB = calculateAngle(sideAC, sideBC, sideAB);
		angleC = calculateAngle(sideAB, sideBC, sideAC);
		printf("\nunghiul A : %f grade", angleA);
		printf("\nunghiul B : %f grade", angleB);
		printf("\nunghiul C : %f grade", angleC);
		printf("\n");
	}
	else
	{
		printf("valorile introduse nu reprezinta laturile unui triunghi\n");
	}
}

////////////////////////////////////////////////////////////////////////////////
float calculateAngle(int opposite, int nearL, int nearR)
{
	//cos A(radians) is (b^2+c^2-a^2)/2bc
	float cosAngle = float( (nearL*nearL + nearR*nearR - opposite*opposite) ) / 
					 float( ( 2 * nearL * nearR ) );
	//one radian is equivalent to 180/PI grade. 
	return (float) ( acos(cosAngle) * 180.f / PI );
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
