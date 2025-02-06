#pragma once
typedef struct PROGRAMMA_t* PROGRAMMA;

struct PROGRAMMA_t
{
	int r;
	int s;
	char*** mat;
};

void PROGRAMMAprint(PROGRAMMA p);
PROGRAMMA getsol(FILE* in);