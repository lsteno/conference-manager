#pragma once
#include <stdio.h>
#include "programma.h"
#define MAXC 25




typedef struct ARTICOLI_t* ARTICOLI;

ARTICOLI ARTICOLIread(FILE* in);

void ARTICOLIprint(ARTICOLI a, FILE* out);

struct ARTICOLO ARTICOLOinit(char titolo[], char relatore[], int slot, char argomento[]);

struct ARTICOLO ARTICOLOread(FILE* in);

void ARTICOLOprint(struct ARTICOLO item, FILE* out);

int checkprogramma(PROGRAMMA sol, ARTICOLI a);