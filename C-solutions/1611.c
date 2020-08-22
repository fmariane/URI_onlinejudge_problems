#include <stdio.h>
#include <stdlib.h>

//1611 - ELEVADOR LOTADO

int compare (const void * a, const void * b){
  return ( *(int*)b - *(int*)a );
}

void main(){
	int n_testes, count;
	int n_andares, capacidade, quant_pessoas;
	int energia_total;

	scanf("%d", &n_testes);

	for(count = 0; count<n_testes; count++){
		scanf("%d%d%d", &n_andares, &capacidade, &quant_pessoas);

		int v[quant_pessoas];

		int i;
		int andar;
		for(i = 0; i<quant_pessoas; i++){
			scanf("%d", &andar);
			v[i] = andar;
		}

		/*TESTE IMPRESSAO

		for(i=0; i<quant_pessoas; i++){
			printf("%d ", v[i]);
		}
		*/

		qsort (v, quant_pessoas, sizeof(int), compare);

		/* TESTE ORDENACAO
		for(i=0; i<quant_pessoas; i++){
			printf("%d ", v[i]);
		}

		printf("\n");
		*/

		
		int ocupou;
		energia_total = 0;
		i = 0;
		while(i < quant_pessoas){
			ocupou = 1; //elevador vazio
			while(ocupou <= capacidade){
				if(ocupou == 1){ //calcula a energia gasta na subida e descida daquela viagem
					energia_total = energia_total + (v[i]*2); //ida+volta ao andar mais alto visitado
				}
				ocupou++;
				i++;
			}
		}

		printf("%d\n", energia_total);
	}

}