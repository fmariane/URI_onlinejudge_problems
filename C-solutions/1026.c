#include <stdio.h>
#include <stdlib.h>

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1026

int main(){
	unsigned int a, b;
	int count = 0;

	while(scanf("%u%u", &a, &b)!= EOF){
		printf("%u\n", a^b);
		count++;
	}
	return 0;
}
