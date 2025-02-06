#ifndef INCLUDED
#define INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "articolo.h"
#include "programma.h"
#endif

int main()
{
	char filename[MAXC];
	int flag;
	ARTICOLI a;
	PROGRAMMA sol;
	FILE* in;

	in = fopen("articoli.txt", "r");

	a = ARTICOLIread(in);

	ARTICOLIprint(a, stdout);

	fclose(in);

	printf("Inserire il nome del file di input della soluzione: ");
	scanf("%s", filename);

	in = fopen(filename, "r");

	sol = getsol(in);

	fclose(in);

	PROGRAMMAprint(sol, stdout);

	flag = checkprogramma(sol, a);

	if (flag == -1)
		printf("Soluzione proposta non valida");

	else
		printf("Soluzione proposta valida");
}

