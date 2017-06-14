#include "files.h"

void init_file(File *p){
	p->size=0;
	p->reserved=2;
	p->content= malloc(2*sizeof(FILE*));
}

void grow_file(File *p){
	p->reserved*=2;
	p->content=realloc(p->content, sizeof(FILE*)*p->reserved);

}

void push_back_file(File *p, const char *aux){
	if(p->size==p->reserved) grow_file(p);
	FILE *fp;
	fp=fopen(aux, "r");
	p->content[p->size++]=fp;
}

void free_file(File *p){
	for(int i=0;i<p->size;i++){
		fclose(p->content[i]);
	}
	free(p->content);
}

FILE* back_file(File *p){
	return p->content[p->size-1];
}
