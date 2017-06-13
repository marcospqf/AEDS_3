#ifndef arow 
#define arow

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "process.h"
#include "files.h"

typedef struct term{
	char word[40];
	int doc,freq,pos;
}term;

int menor( char *s1, char *s2);

int igual( char *s1, char *s2);

int compara_s(const void *p1, const void *p2);

void ordena(FILE *in, FILE *out);

void merge_file(int node, int b, int e, char *basename, char *in);

void mistura(FILE *in1, FILE *in2, FILE *out);

int menort(term a, term b);

void gera_freq(char *input);

void gera_output(char *input, char *output);
#endif
