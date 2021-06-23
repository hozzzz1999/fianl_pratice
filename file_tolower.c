#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	FILE *fp;
	char c;
	char word[2048] = {'\0'};
	int cnt = 0;

	if((fp = fopen(argv[1], "r")) == NULL){
		printf("open file error!\n");
		exit(0);
	}
	while((c = getc(fp)) != EOF){
		if(c >= 'A' && c <= 'Z'){
			c += 32;
			word[cnt++] = c;
		}
		else 
            word[cnt++] = c;
	}
	word[cnt] = '\0';
	fclose(fp);
	
	fp = fopen(argv[1], "w");
	fprintf(fp, "%s", word);
	fclose(fp);
}