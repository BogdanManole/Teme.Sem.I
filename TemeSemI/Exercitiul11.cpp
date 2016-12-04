#include "stdafx.h"
#include "Exercitii.h"

//internal functions declarations:
static void printDescription();
static void getInput(int& input);
static void printAnswer(int input);
static unsigned int calculateBinarySize(int input);
static void calcAnswer(char** answer, int size, int input);

////////////////////////////////////////////////////////////////////////////////
void ex11()
{
	int input;

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
	static const char description[] = "Sa se scrie un program pentru afisarea"
						" echivalentului binar al unui numar natural (intreg"
						" cu semn) dat.\n"
						" Exemple: 11 = 1011, 25 = 1001, 23 = 10111.";
	printf("%s\n\n", description);
}

////////////////////////////////////////////////////////////////////////////////
void getInput(int& input)
{
	printf("introduceti numarul pentru conversie:\n");
	scanf("%d", &input);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
void printAnswer(int input)
{
	char* answer;
	unsigned int answerSize = calculateBinarySize(input);
	calcAnswer(&answer, answerSize, input);
	printf("forma binara a numarului %d, este %s", input, answer);
	free(answer);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
unsigned int calculateBinarySize(int input)
{
	unsigned int count = 0;
	while (input != 0)
	{
		input >>= 1;
		count++;
	}
	return count;
}


////////////////////////////////////////////////////////////////////////////////
void calcAnswer(char** answer, int size, int input)
{
	(*answer) = (char*)malloc(size + 1);//+1 for null terminator
	for (int i = 0; i < size; ++i)
	{
		int index = size - (i + 1);
		(*answer)[index] = ( (input >> i) & 1 ) ? '1' : '0';
	}
	(*answer)[size] = '\0';
}


