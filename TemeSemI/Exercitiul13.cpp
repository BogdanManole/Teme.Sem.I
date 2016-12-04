#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& size, int** arr);
static void printAnswer(int& size, int* arr);
static void bubbleSort(int size, int* arr);
static void swap(int &a, int &b);

////////////////////////////////////////////////////////////////////////////////
void ex13()
{
	//ax^2 + bx + c = 0
	int size;
	int *arr;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(size, &arr);

	printf("RASPUNS:\n");
	printAnswer(size, arr);

	//cleanup
	free(arr);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program pentru ordonarea" 
				" unui vector de numere intregi prin metoda bulelor: se compara"
				" elemente vecine din vector(a[i] si a[i + 1]) si, daca este:"
				" necesar, se schimba intre ele pentru ca a[i] & lt; = a[i + 1]."
				" In general sunt necesare mai multe treceri prin vector pentru"
				" ordonarea sa.Indicatii:\n"
				"	a) Numarul de treceri este egal cu dimensiune vector minus 1.\n"
				"	b) Se fac atatea treceri cate sunt necesare pentru ordonarea" 
				" vectorului\n"
				"	c) Se memoreaza daca au fost necesare schimbari de elemente"
				" in vector si se opreste repetarea cand nu a mai fost necesara"
				" nici o schimbare.\n"
				"	d) O trecere prin vector se face de la prima la ultima"
				" pereche\n"
				"	e) O trecere prin vector se face de la ultima pereche catre"
				" prima pereche";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& size, int** arr)
{
	printf("introduceti numarul de elemente:\n");
	scanf("%d", &size);
	(*arr) = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
	{
		printf("introduceti elemntul %d : ", i);
		scanf("%d", &(*arr)[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int& size, int* arr)
{
	bubbleSort(size, arr);
	printf("array cu bubble sort:\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void bubbleSort(int size, int* arr)
{
	bool swapped = true;
	while (true == swapped)
	{
		//flag to keep the fact that array has changed
		swapped = false;
		for (int i = 0; i < size - 1; ++i)
		{
			//compare first value with next one
			if ( arr[i] > arr[i + 1] ) 
			{
				//swap values
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}