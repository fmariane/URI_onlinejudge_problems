// 1209 - FESTAS DE SAO PETESBURGO

#include <stdio.h>
#include <stdlib.h>
#define T 1005

void init(int v[]){
  int i;
  for(i=0; i<T;i++){
    v[i]=0;
  }
}

void initRede(int v[][T]){
  int i,j;
  for(i=0;i<T;i++){
    for(j=0;j<T;j++){
      v[i][j]=0;
    }
  }
}

//escolhe um possivel convidado para excluir da lista
//convidados com -1 ja estao excluidos
int escolheEexclui(int c[], int conv, int min){
  int i;
  
  for(i=1; i<=conv; i++){
    if(c[i]>=0 && c[i]<min){
      c[i] = -1;
      return i;
    }
  }
}

//apos excluir um convidado, deve-se decrementar o 
//numero de amigos dos seus adjacentes
int decrementa(int rede[][T], int c[], int alvo, int conv){
  int i;
  for(i=1; i<=conv;i++){
    if(rede[alvo][i] == 1 ){
      c[i] = c[i]-1;
    }
  }
}

int testa(int c[], int conv, int min){
  int i;
  int terminou = 0;
  
  for(i=1; i<=conv; i++){
    if(c[i]>=0 && c[i]<min){
      terminou = 0;
      return terminou;
    }
  }
  
  terminou = 1;
  return terminou;
}

void imprime(int c[], int conv){
  int i, vazio=1, primeiro;
  for(i=1; i<=conv; i++){
    if(c[i] > 0){
      vazio = 0;
      break;
    }
  }
  
  if(vazio == 1){
    printf("0");
  }
  
  else{
    primeiro = 1;
    for(i=1; i<=conv; i++){
      if(c[i]>=0){
        
        if(primeiro){//para nao imprimir espaco no fim
          primeiro = 0;
          printf("%d", i);
        }
        else{
          printf(" %d", i);
        }
      
      }
    } 
  }
  printf("\n");
}

void printTeste(int c[], int conv){
  int i;
  for(i=0;i<conv;i++)
    printf("%d ", i);
  
  printf("\n");
}

int main(){
  int i, j, terminou;
  int nPessoas, nConexoes, conexMin;
  int amigo1, amigo2, remova;
  int rede[T][T];
  int convidados[T];

  while(1){

    scanf("%d%d%d\n", &nPessoas, &nConexoes, &conexMin);

    init(convidados);
    initRede(rede);
     
    for(i=0; i<nConexoes; i++){
      scanf(" %d%d\n", &amigo1, &amigo2);

      rede[amigo1][amigo2]= 1;
      rede[amigo2][amigo1]= 1;
      convidados[amigo1]++;
      convidados[amigo2]++;
      
    }
    
    terminou = testa(convidados, nPessoas, conexMin);
    //printf("Terminou %d\n", terminou);
    while(terminou == 0){
      remova = escolheEexclui(convidados, nPessoas, conexMin);
      decrementa(rede, convidados, remova, nPessoas);

      terminou = testa(convidados, nPessoas, conexMin);

      //printf("testando \n");   
    }
    
    //printf("Terminou de testar\n");
    imprime(convidados, nPessoas);
    
    if(feof(stdin)){
      break;
    }

  }
  
  return 0;
}