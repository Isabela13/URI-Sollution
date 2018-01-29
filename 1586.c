#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Nome: Cabo de Guerra

int main(int argc, char const *argv[])
{
	int n, i , count,tam,entrou, forcanome,j,forcaAT,forcaA,forcaB,forcaBT,k;
	char nome[100002][15];
	scanf("%d",&n);
	while(n !=0){
		int forca[n];
		int k=1;
		for (i = 1; i <= n; i++)
		{
			count =0;
			forcanome=0;
			scanf("%s",nome[i]);
			tam = strlen(nome[i]);
			while(count<tam){
				 forcanome += 0+ nome[i][count];
				 count ++;
			}
			//printf("%d\n",forcanome);
			forca[i]=forcanome;
	 		forcaA = forcaA + forca[i];
	 		forcaAT = forcaAT + (forca[i]*i);
		}
	 
		entrou = -1;
		forcaBT = 0;
		forcaB = 0;
		k=1;
	 	while(k <= n){
	 		//printf("Entrou\n");
			forcaAT = forcaAT - forcaA;
			//printf("%d\n",forcaA);
			forcaA = forcaA - forca[k];
			forcaB = forcaB + forca[k];
			//printf("%d\n",forcaB);
			forcaBT = forcaBT + forcaB;
			if(forcaBT == forcaAT){
				//printf("Achou");
				printf("%s\n",nome[k]);
				  entrou=1;
			}
			if( forcaBT > forcaAT ){
				//printf("sem soluçao");
			}
			k++;
		}
	if(entrou!=1){
		printf("Impossibilidade de empate.\n");
	}

	scanf("%d",&n);		
	}

	return 0;
}
