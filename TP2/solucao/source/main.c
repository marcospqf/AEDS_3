#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "process.h"
#include "sorter.h"

int main()
{
	char input[400], output[400];

	int d,m;
	scanf("%d %d", &d, &m);
	scanf("%s", input);
	scanf("%s", output);
	
	int tam=strlen(input);
	input[tam+1]='\0';
	File in; 
	init_file(&in);
	int ntmp=0;
	char number[10];
	
	for(int i=1;i<=d;i++){
		get_num(i,number);
		int tamx=strlen(number);
		for(int j=0;j<tamx;j++) input[tam+j]=number[j];
		input[tam+tamx]='\0';
		//printf("%s\n", input);
		push_back_file(&in, (const char*)input,1);
		process_file(back_file(&in), m, &ntmp, i);
	}
	
	//printf("%d\n", ntmp);
	char namefile[40], numfile[40], basenameout[40]="./tmp_out/tmp\0", basenamein[40]="./tmp_in/tmp\0";
	for(int i=1;i<=ntmp;i++){
		 get_num(i, numfile);
		 gen_namefile(namefile, numfile, basenamein);
		
		 FILE *entrada= fopen(namefile, "r");
		
		 //printf("%s\n" , namefile);
		 gen_namefile(namefile, numfile, basenameout);
		 
		 //printf("%s\n" , namefile);
		
			
		 FILE *saida= fopen(namefile, "w");
		 ordena(entrada,saida);

		 fclose(entrada);
		 fclose(saida);
		
	}
	char basenamein2[40]="./tmp_out/tmp_tr\0";
	merge_file(1,1,ntmp, basenamein2, basenameout);

	char basenamein3[40]="./tmp_out/tmp_tr1.txt\0";

	int pqp=strlen(output);
	output[pqp]='1';
	output[pqp+1]='\0';
//	printf("%s\n", basenamein2);
	gera_output(basenamein3, output);
	
	free_file(&in);
	return 0; 
}
