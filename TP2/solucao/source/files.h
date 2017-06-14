#ifndef arquivo
#define arquivo

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct File{
	FILE **content;
	int size;
	int reserved;
}File;

FILE* back_file(File *p);

void init_file(File *p);

void grow_file(File *p);

void push_back_file(File *p, const char *c);

void free_file(File *p);
#endif
