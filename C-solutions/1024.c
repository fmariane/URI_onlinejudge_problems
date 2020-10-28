//https://www.urionlinejudge.com.br/judge/pt/problems/view/1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1010

void rev(char v[], int i, int j){
    int aux;
    int begin=i-1, end=j-1;
    while(begin<=end){
        aux=v[begin];
        v[begin]=v[end];
        v[end]=aux;
 
        begin++;
        end--;
    }
}

//ascii maiusculas 65 - 90
//ascii minusculas 97 - 122

void shift3right(char str[], int n){
	int i, c;
	for(i=0; i<n; i++){
		c = str[i];
		
		if((c>= 65 && c<=90) || (c>= 97 && c<=122)){
			c = str[i];
			c = c +3;
			str[i]= c;
		}
	}
}

void halfshift1left(char str[], int n){
	int i;
	for(i=(n/2); i<n; i++){
		str[i]=str[i]-1;
	}
}

int main(){
	int i, j, num_test;
	char frase[MAX];

	scanf("%d\n", &num_test);
	
	for(i=0; i<num_test; i++){	
		memset(frase, 0	, MAX);
		
		gets(frase);

		//printf("%s\n", frase);
		shift3right(frase, strlen(frase));
		rev(frase, 0, strlen(frase)+1); 
		//printf("%s\n", frase);
		halfshift1left(frase, strlen(frase));

		printf("%s\n", frase);	

	}
	
	return 0;

}
