#include "process.h"

void get_num(int x, char *s){
	int sz=0;
	while(x>0){
		s[sz++]=(char)( (x%10)+'0');
		x/=10;
	}
	s[sz]='\0';
	int tam=strlen(s);
	for(int i=0;i<tam/2;i++){
		char c;
		c=s[i];
		s[i]=s[tam-i-1];
		s[tam-i-1]=c;
	}
}


void gen_namefile(char *namefile, char *numfile, char *basename){
	int y=strlen(basename);
	int x=strlen(numfile);
	for(int i=0;i<y;i++) namefile[i]=basename[i];
	for(int i=y;i<x+y;i++) namefile[i]=numfile[i-y];
	namefile[x+y]='.';
	namefile[x+y+1]='t';
	namefile[x+y+2]='x';
	namefile[x+y+3]='t';
	namefile[x+y+4]='\0';
}

void process_file(FILE* in, int maxtam, int *ncreated, int idxdoc){	
	maxtam=maxtam/2;
	char word[40], numfile[40], namefile[40], basename[40]="./tmp_in/tmp\0";
	*ncreated=*ncreated + 1;
	get_num(*ncreated, numfile);
	gen_namefile(namefile, numfile, basename);
	int freq=1;
	int pos=0;
	//printf("%s\n" , namefile);
	FILE *last= fopen(namefile, "w");
	int tam=0;
	while(fscanf(in, "%s",  word)==1){
		int x=strlen(word);
	//	printf("%s\n" , word);
		if(x+tam+12<=maxtam){
			fprintf(last,"%s %d %d %d\n", word, idxdoc, freq, pos);
			tam+=x+12;
		}
		else{
	//		printf("%d\n", *ncreated);
			*ncreated= *ncreated+1;
			get_num(*ncreated, numfile);
			gen_namefile(namefile, numfile, basename);
			fclose(last);
			last=fopen(namefile,"w");
			fprintf(last,"%s %d %d %d\n", word, idxdoc, freq, pos);
			tam=x+12;
		}
		pos+=x+1;
	}
	fclose(last);
}
