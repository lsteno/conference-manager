#ifndef INCLUDED
#define INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "articolo.h"
#include "programma.h"
#endif



struct ARTICOLO
{
	char titolo[MAXC];
	char relatore[MAXC];
	int slot;
	char argomento[MAXC];
};

struct ARTICOLI_t
{
	struct ARTICOLO* array;
	int N;
};

static ARTICOLI ARTICOLIinit(int A)
{
	ARTICOLI a;
	a = malloc(sizeof(*a));
	a->array = malloc(A * sizeof(*a->array));
	a->N = A;
	return a;
}

ARTICOLI ARTICOLIread(FILE* in)
{
	int A, i = 0;
	ARTICOLI a;
	fscanf(in, "%d", &A);
	a = ARTICOLIinit(A);
	while (fscanf(in, "%s %s %d %s", a->array[i].titolo, a->array[i].relatore, &a->array[i].slot, a->array[i].argomento) == 4)
		i++;
	return a;
}

void ARTICOLIprint(ARTICOLI a, FILE* out)
{
	int i;
	for (i = 0; i < a->N; i++)
	{
		fprintf(out, "%s %s %d %s", a->array[i].titolo, a->array[i].relatore, a->array[i].slot, a->array[i].argomento);
		fprintf(out, "\n");
	}
	fprintf(out, "\n\n");
}

struct ARTICOLO ARTICOLOinit(char titolo[], char relatore[], int slot, char argomento[])
{
	struct ARTICOLO item;
	strcpy(item.titolo, titolo);
	strcpy(item.relatore, relatore);
	item.slot = slot;
	strcpy(item.argomento, argomento);
	return item;
}

struct ARTICOLO ARTICOLOread(FILE* in)
{
	struct ARTICOLO item;
	fscanf(in, "%s %s %d %s", item.titolo, item.relatore, &item.slot, item.argomento);
	return item;
}

void ARTICOLOprint(struct ARTICOLO item, FILE* out)
{
	fprintf(out, "%s %S %d %s", item.titolo, item.relatore, item.slot, item.argomento);
}

static char* relatorefromarticolo(PROGRAMMA sol, ARTICOLI a, char articolo[])
{
	int i;
	char* relatore;
	for (i = 0; i < a->N; i++)
	{
		if (strcmp(articolo, a->array[i].titolo) == 0)
		{
			relatore = _strdup(a->array[i].relatore);
			return relatore;
		}
	}
}

int checkprogramma(PROGRAMMA sol, ARTICOLI a)
{
	int i, j, z, k;
	int contatore = 0;
	char* relatore1 = NULL;
	char* relatore2 = NULL;
	char articolo[MAXC];
	int* check = calloc(a->N, sizeof(int));

	for (i = 0; i < sol->r; i++)
	{
		for (j = 0; j < sol->s; j++)
		{
			if(sol->mat[i][j] != '\0')
			for (z = 0; z < a->N; z++)
				if (strcmp(sol->mat[i][j], a->array[z].titolo) == 0)
				{
					for (k = 1; k < a->array[i].slot; k++)
						if (strcmp(sol->mat[i][j + k], a->array[z].titolo) != 0)
						{
							printf("All'articolo %d non sono forniti abbastanza slot di tempo\n\n", i);
							return -1;
						}

					break;
				}
		}
	}

	for (j = 0; j < sol->s; j++)
	{
		for (i = 0; i < sol->r; i++)
		{
			if (sol->mat[i][j] != '\0')
			{
				strcpy(articolo, sol->mat[i][j]);

			
				relatore1 = relatorefromarticolo(sol, a, articolo);

				for (k = 0; k + i < sol->r; k++)
				{
					if (sol->mat[i + k][j] != '\0')
					{
						strcpy(articolo, sol->mat[i + k][j]);
						relatore2 = relatorefromarticolo(sol, a, articolo);
						if (strcmp(relatore1, relatore2) == 0)
							contatore++;
					}
				}

				if (contatore > 1)
				{
					printf("Il relatore %s dovrebbe presentare in due sale contemporaneamente\n\n", relatore1);
					return -1;
				}

				contatore = 0;
			}
		}
	}

	for (i = 0; i < a->N; i++)
	{
		for (z = 0; z < sol->r; z++)
		{
			for (k = 0; k < sol->s; k++)
			{
				if(sol->mat[z][k] != '\0')
					if (strcmp(a->array[i].titolo, sol->mat[z][k]) == 0)
					{
						check[i]++;
					}
			}
		}
	}

	for (i = 0; i < a->N; i++)
		if (check[i] != 1)
		{
			if (check[i] == 0)
				printf("L'articolo %d non viene presentato\n\n", i);

			else
				printf("L'articolo %d viene presentato piu' di una volta\n\n", i);

			return -1;
		}

	return 0;
}
