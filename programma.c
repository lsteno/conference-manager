#ifndef INCLUDED
#define INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "articolo.h"
#include "programma.h"
#endif

void PROGRAMMAprint(PROGRAMMA p, FILE* out)
{
	int i, j;

	for (i = 0; i < p->r; i++)
	{
		for (j = 0; j < p->s; j++)
		{
			fprintf(out, "%s ", p->mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

PROGRAMMA getsol(FILE* in)
{
	int r, s, i, j, z;

	PROGRAMMA a = malloc(sizeof(struct PROGRAMMA_t));
	char buf[MAXC];
	char nul[MAXC] = {'0'};
	fscanf(in, "%d %d", &r, &s);
	a->r = r;
	a->s = s;

	a->mat = malloc(r * sizeof(char**));
	for (i = 0; i < r; i++)
	{
		a->mat[i] = malloc(s * sizeof(char*));
		for (j = 0; j < s; j++)
		{
			a->mat[i][j] = malloc(MAXC * sizeof(char));
		}
	}

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < s; j++)
		{
			fscanf(in, "%s", buf);

			if (strcmp(buf, nul) == 0)
				a->mat[i][j] = '\0';
			else
				strcpy(a->mat[i][j], buf);
		}
	}
	return a;
}