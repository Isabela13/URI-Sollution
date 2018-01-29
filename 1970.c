#include <stdio.h>
#include <stdlib.h>

//Nome: Primeiro Contato

int valormaior(int aux, int soma_dos_n) {
	if (aux > soma_dos_n){
		return aux;
	}
	else return soma_dos_n;
}

int main(int argc, char const *argv[])
{
	int n,k;
	int i,j;
	scanf("%d",&n);
	scanf("%d",&k);
	int vetTempo[n];
	int vetCart[k];
	for (i = 0; i < n; i++)
	{
		scanf("%d",&vetTempo[i]);
		//printf("%d\n",vetTempo[i]);
	}
	//int soma=0;
	for (j = 0; j < k; j++)
	{
		scanf("%d",&vetCart[j]);
		//soma=soma+vetCart[j];
		//printf("%d\n",vetCart[j]);
	}
	//ordenaVet(vetTempo,0,n);
	int printa,count_musica;
	//printf("%d\n",soma );
	/*for (printa=0;printa<n;printa++){
		printf("%d\n",vetTempo[printa] );
	}*/
	int aux=0;
	//printf("%d\n", k);
	if (k == 1){
		int matriz[52];
		matriz[0]=1;
		count_musica =0;
		while (count_musica < n){//esse count vai ir ate o final n, numeros de musicas
			for (i = vetCart[0]; i >= 0; i--){
						//printf("Entr");
						//nao pode ser negativa se nao for sai direto 
						if( ((i-vetTempo[count_musica]) >= 0) && (matriz[i-vetTempo[count_musica]] == 1)) {
							matriz[i]=1;
						//printf("Entr");
						
						aux=valormaior(aux,i);

						}
			}
			count_musica++;
		}	
	}else if (k==2){
		int matriz[52][52];
		matriz[0][0]=1;
		count_musica =0;
		while (count_musica < n){//esse count vai ir ate o final n, numeros de musicas
			for (i = vetCart[1]; i >= 0; i--){
				//printf("Entr");
				for(j= vetCart[0]; j>= 0 ;j--){
						//printf("Entr");
						//nao pode ser negativa se nao for sai direto 
						if(  (matriz[i-vetTempo[count_musica]][j] == 1) && ((i-vetTempo[count_musica]) >= 0)  || (matriz[i][j-vetTempo[count_musica]] ==1) && ((j-vetTempo[count_musica]) >= 0) ){
							matriz[i][j]=1;
							//printf("Entr");
							aux=valormaior(aux,(i+j));
						}
				}
			}
			count_musica ++;
		}
	}else if (k==3){
	int matriz[52][52][52]; 
	matriz[0][0][0]=1;
	count_musica =0;
		while (count_musica < n){ //esse count vai ir ate o final n, numeros de musicas
			for (i = vetCart[2]; i >= 0; i--){
				//printf("Entr");
				for (j= vetCart[1]; j>= 0 ;j--){
					//printf("Entr");
					for (k = vetCart[0]; k >= 0; k--){
						//printf("Entr");
						//nao pode ser negativa se nao for sai direto 
						if(  ((i-vetTempo[count_musica]) >= 0) && (matriz[i-vetTempo[count_musica]][j][k] == 1)  || ((j-vetTempo[count_musica]) >= 0) && (matriz[i][j-vetTempo[count_musica]][k] ==1) || ((k-vetTempo[count_musica]) >= 0) && (matriz[i][j][k-vetTempo[count_musica]] ==1) ){
							matriz[i][j][k]=1;
						//printf("Entr");
						aux=valormaior(aux,(i+j+k));

						}

					}
				}
			}
			count_musica ++;
		}
	}
	printf("%d\n",aux );


	return 0;
}
