#ifndef process
#define process

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "sorter.h"

void process_file(FILE* in, int maxtam, int *ncreated, int idxdoc);

void gen_namefile(char *namefile , char *numfile, char *basename);

void get_num(int x, char *s);

#endif
