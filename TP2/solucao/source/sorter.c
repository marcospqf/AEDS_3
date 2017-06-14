#include "sorter.h"

int menor( char *s1, char *s2){
	int tam1=strlen(s1);
	int tam2=strlen(s2);
	for(int i=0;i< (tam1<tam2) ? tam1 : tam2; i++) 
		if(s1[i] != s2[i]) return s1[i] - s2[i];
	return tam1-tam2;
}


int igual( char *s1, char *s2){
	int tam1=strlen(s1);
	int tam2=strlen(s2);
	if(tam1!=tam2) return 0;
	for(int i=0;i<tam1;i++) if(s1[i]!=s2[i]) return 0;
	return 1;
}
// menor palavra, menor documento .. menor tudo
int compara_s(const void *p1, const void *p2){
	term *a = (term *)p1;
	term *b = (term *)p2;
	if(!igual(a->word, b->word)) return menor(a->word, b->word);
	if(a->doc!=b->doc) return a->doc- b->doc;
	if(a->freq!=b->freq) return a->freq- b->freq;
	return a->pos - b->pos;
}

void ordena(FILE *in, FILE *out){
	int memo=2;
	int sz=0;
	term *a = malloc(2*memo*sizeof(term));
	char word[40];
	int doc, freq, pos;

	while(fscanf(in,"%s %d %d %d", word, &doc, &freq, &pos)==4){
		if(sz==memo) {
			memo*=2;
			a=realloc(a, memo*sizeof(term));
		}
		strcpy(a[sz].word, word);

		//printf("%s\n", word);
		a[sz].freq=freq;
		a[sz].pos=pos;
		a[sz].doc=doc;
		sz++;
	}
	qsort(a, sz, sizeof(term), compara_s);
	for(int i=0;i<sz;i++){
		fprintf(out,"%s %d %d %d\n", a[i].word, a[i].doc, a[i].freq, a[i].pos);
		//printf("%s \n", a[i].word); 
	}
  free(a);
}

void mistura(FILE *in , FILE *in2, FILE *out){
	term file1, file2;
	int tem1=0; 
	int tem2=0;
	while(1){
		if(!tem1){
			if(fscanf(in,"%s %d %d %d", file1.word, &file1.doc, &file1.freq, &file1.pos)==4 ){
				tem1=1;
			}
		}
		if(!tem2){
			if(fscanf(in2,"%s %d %d %d", file2.word, &file2.doc, &file2.freq, &file2.pos)==4 ){
				tem2=1;
			}
		}
		if(tem1 && tem2){
			if(menort(file1, file2)) {
				fprintf(out, "%s %d %d %d\n", file1.word, file1.doc,file1.freq, file1.pos);
				tem1=0;
			}
			else{
				fprintf(out, "%s %d %d %d\n", file2.word, file2.doc,file2.freq, file2.pos);
				tem2=0;
			}
		}
		else if(tem1){
				fprintf(out, "%s %d %d %d\n", file1.word, file1.doc,file1.freq, file1.pos);
				tem1=0;
		}
		else if(tem2){
				fprintf(out, "%s %d %d %d\n", file2.word, file2.doc,file2.freq, file2.pos);
				tem2=0;
		}
		else{
			break;
		}
	}
}

void merge_file(int node, int b, int e, char *basename, char *in){
	if(b==e){
		FILE *tr;
		FILE *input;
		char namefile_in[40];
		char namefile_tr[40];
		char numfile_in[40];
		char numfile_tr[40];
		get_num(b, numfile_in);
		get_num(node, numfile_tr);

		gen_namefile(namefile_in, numfile_in, in);
		gen_namefile(namefile_tr, numfile_tr, basename);
		//printf("arquivo: %s\n segtree: %s\n", namefile_in, namefile_tr);
		input=fopen(namefile_in, "r");
		tr=fopen(namefile_tr, "w");
		
		char palavra[40];
		int freq, doc, pos;
		while(fscanf(input, "%s %d %d %d", palavra, &doc, &freq, &pos)==4){
			fprintf(tr, "%s %d %d %d\n", palavra, doc,freq, pos);
		}

		fclose(input);
		fclose(tr);
	}
	else{
		int mid=(b+e)/2;
		merge_file(2*node, b, mid, basename, in);
		merge_file(2*node+1, mid+1, e, basename, in);
		char namefile_tr2[40], namefile_tr3[40], namefile_tr[40];
		char numfile_tr2[40], numfile_tr3[40], numfile_tr[40];
		
		get_num(2*node, numfile_tr2);
		get_num(2*node+1, numfile_tr3);
		get_num(node, numfile_tr);
		
		gen_namefile(namefile_tr2, numfile_tr2, basename);		
		gen_namefile(namefile_tr3, numfile_tr3, basename);		
		gen_namefile(namefile_tr, numfile_tr, basename);		
		
		FILE *in1=fopen(namefile_tr2, "r");
		FILE *in2=fopen(namefile_tr3, "r");
		FILE *out=fopen(namefile_tr, "w");
		mistura(in1, in2, out);

		fclose(in1);
		fclose(in2);
		fclose(out);
	}
}


int menort(term a, term b){
	if(!igual(a.word, b.word))
		return menor(a.word,b.word)<0;
	if(a.doc!=b.doc) return a.doc<b.doc;
	if(a.freq!=b.freq) return a.freq<b.freq;
	return a.pos<b.pos;
}



void gera_freq(char *input){
	//printf(" INPUT: %s\n", input);
	FILE *in= fopen(input, "r");
	
	FILE *in2= fopen("./tmp_out/aux.txt","w");
	
	term last,cur;
	last.doc=-1;
	while(fscanf(in,"%s %d %d %d", cur.word, &cur.doc, &cur.freq, &cur.pos)==4){
		if(last.doc==-1) {
			strcpy(last.word, cur.word);
			last.doc=cur.doc;
			last.freq=cur.freq;
			continue;
		}
		if(last.doc!=cur.doc || !igual(last.word, cur.word)){
			fprintf(in2, "%s %d %d\n", last.word, last.doc, last.freq);
			strcpy(last.word, cur.word);
			last.doc=cur.doc;
			last.freq=cur.freq;
		}
		else{
			last.freq++;
		}
	}	
	if(last.doc!=-1)
		fprintf(in2, "%s %d %d\n", last.word, last.doc, last.freq);

	fclose(in);
	fclose(in2);
}


void gera_output(char *input, char *output){
	gera_freq(input);
	FILE *in=  fopen(input, "r");
	FILE *in2= fopen("./tmp_out/aux.txt","r");
	FILE *out= fopen(output, "w");
	term cur, freq;
	freq.doc=-1;
	//printf("%s\n", output);
	while(fscanf(in,"%s %d %d %d", cur.word, &cur.doc, &cur.freq, &cur.pos)==4){
		if(cur.doc!=freq.doc || !igual(cur.word, freq.word)){
			fscanf(in2,"%s %d %d", freq.word, &freq.doc, &freq.freq);
		}
		cur.freq=freq.freq;
		fprintf(out, "%s,%d,%d,%d\n", cur.word, cur.doc, cur.freq, cur.pos);
	}
	fclose(out);
	fclose(in);
	fclose(in2);
}
