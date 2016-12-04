
#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int** numbers, int& size_numbers);
static void printAnswer(int* numbers, int size_numbers);
static void getOrderedSequence(int* numbers, int size_numbers,
							   int& sequence_size, int** sequence);

////////////////////////////////////////////////////////////////////////////////
void ex23()
{
	int *numbers;
	int size_numbers;

	printf("DESCRIERE:\n");
	printDescription();

	printf("INPUT:\n");
	getInput(&numbers, size_numbers);

	printf("RASPUNS:\n");
	printAnswer(numbers, size_numbers);

	//cleanup
	free(numbers);
}

////////////////////////////////////////////////////////////////////////////////
void printDescription()
{
	static const char description[] = "Sa se scrie un program pentru afisarea"
				" celei mai lungi secvente ordonate de elemente consecutive dintr-"
				" un vector citit dintr - un fisier.\n"
				" Exemplu de date : 6 4 7 2 5 7 8 4 1 Rezultat : 2 5 7 8";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int** numbers, int& size_numbers)
{
	printf("inputul este citit din fisiererul ./input/ex23.txt\n");
	FILE *file;
	file = fopen("./input/ex23.txt", "rt");
	int placeholder;
	int buf_int[512];
	size_numbers = 0;
	while (fscanf(file, "%d", &placeholder) == 1)
	{
		buf_int[size_numbers] = placeholder;
		size_numbers++;
	}
	fclose(file);
	(*numbers) = (int*)malloc(sizeof(int) * size_numbers);
	memcpy((*numbers), buf_int, sizeof(int) * size_numbers);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int* numbers, int size_numbers)
{
	int sequence_size = 0;
	int* sequence = NULL;
	getOrderedSequence(numbers, size_numbers, sequence_size, &sequence);
	printf("rezultat : ");
	for (int i = 0; i < sequence_size; ++i)
	{
		printf("%d ", sequence[i]);
	}
	printf("\n");

	//cleanup
	free(sequence);
}

////////////////////////////////////////////////////////////////////////////////
void getOrderedSequence(int* numbers, int size_numbers,
						int& sequence_size, int** sequence)
{
	int temp_sequence_size = 0;
	int temp_sequence[100];
	for (int i = 0; i < size_numbers; ++i)
	{

		if ( ( temp_sequence_size == 0 ) ||
			 ( numbers[i] > numbers[i - 1] ) )
		{
			temp_sequence[temp_sequence_size] = numbers[i];
			temp_sequence_size++;
		} 
		else
		{
			if (temp_sequence_size > sequence_size)
			{
				sequence_size = temp_sequence_size;
				(*sequence) = (int*)realloc(*sequence, sizeof(int) * sequence_size);
				memcpy((*sequence), temp_sequence, sizeof(int) * sequence_size);
			}
			temp_sequence[0] = numbers[i];
			temp_sequence_size = 1;
		}
	}
}