//chamadas de fibonacci
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1029

#include <stdio.h>
#include <stdlib.h>
 
int calls;
 
int fib(int n){
    calls++;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return (fib(n-1)+fib(n-2));
}
 
 
int main(){
    int i, quant_test, n, num;
 
    scanf("%d\n", &quant_test);
     
    for(i=0; i<quant_test; i++){
        scanf("%d", &n);
        calls=0;
        num = fib(n);
 
        printf("fib(%d) = %d calls = %d\n", n, calls-1, num); 
    }
 
    return 0;
}
