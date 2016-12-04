// TemeSemI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Exercitii.h"

static const int arraySize = 23;
void (*pFunction[arraySize])(void);


void initFunctionPointers()
{
	pFunction[0] = ex1;
	pFunction[1] = ex2;
	pFunction[2] = ex3;
	pFunction[3] = ex4;
	pFunction[4] = ex5;
	pFunction[5] = ex6;
	pFunction[6] = ex7;
	pFunction[7] = ex8;
	pFunction[8] = ex9;
	pFunction[9] = ex10;
	pFunction[10] = ex11;
	pFunction[11] = ex12;
	pFunction[12] = ex13;
	pFunction[13] = ex14;
	pFunction[14] = ex15;
	pFunction[15] = ex16;
	pFunction[16] = ex17;
	pFunction[17] = ex18;
	pFunction[18] = ex19;
	pFunction[19] = ex20;
	pFunction[20] = ex21;
	pFunction[21] = ex22;
	pFunction[22] = ex23;
}

struct A
{
	int a;
	int b;
	int c;
	int d;
};

////////////////////////////////////////////////////////////////////////////////
int main()
{
	initFunctionPointers();
	int index = 0;
	while (true)
	{
		printf("--------------------------------------------------------------\n");
		printf("intorduceti numarul exercitiului(0 pentru a incheia) : ");
		scanf("%d", &index);
		//index - 1 - numaratoarea o incepem de la 0
		if (index == 0)
		{
			printf("Bye!\n");
			break;
		}
		--index;
		if (index < arraySize)
		{
			(*pFunction[index])();
		}
		else
		{
			printf("nu am gasit niciun exercitiu cu acest numar. Mai incercati.\n");
		}
	}
    return 0;
}

