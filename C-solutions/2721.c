#include <stdlib.h>
#include "stdio.h"
#define size 9

int main(void) {
  int i;
  int ballssum, balls[size];
  
  for(i=0; i<size; i++){
    scanf(" %d", &balls[i]);
  }
  
  ballssum = 0;
  
  for(i=0; i<size; i++)
    ballssum+=balls[i];
  
  switch((ballssum%9)){
      case 1: printf("Dasher\n");break;
      case 2: printf("Dancer\n");break;
      case 3: printf("Prancer\n");break;
      case 4: printf("Vixen\n");break;
      case 5: printf("Comet\n"); break;
      case 6: printf("Cupid\n");break;
      case 7: printf("Donner\n");break;
      case 8: printf("Blitzen\n");break;
      case 0: printf("Rudolph\n");break;
      default: break;
  }
  
  return 0;
}
