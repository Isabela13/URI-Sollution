#include <stdio.h>


int max(int a,int b){
  if(a>b){
    return a;
  }
  else {
    return b;
  }
}

int mochila(int capacidade_max, int *peso, int *val, int n){
  int i, j;
  int capacidade_mochila[n+1][capacidade_max+1];
 
  for (i = 0; i <= n; i++){
      for (j = 0; j <= capacidade_max; j++){
          if (i==0 || j==0)
            capacidade_mochila[i][j] = 0;
          else if (peso[i-1] <= j){
              capacidade_mochila[i][j] = max(val[i-1] + capacidade_mochila[i-1][j-peso[i-1]],capacidade_mochila[i-1][j]);
          }
          else{
            capacidade_mochila[i][j] = capacidade_mochila[i-1][j];
          }
       }
   }
 
   return capacidade_mochila[n][capacidade_max];
}

//recursivo nao esta passando

/*int mochila(int capacidade_max, int *peso, int *val, int qtd_elementos){
  
  if (qtd_elementos == 0 || capacidade_max == 0){ // caso base e teste de sanidade
       return 0;
  }

  if (peso[qtd_elementos-1] > capacidade_max){ // se o peso for maior que a capacidade da mochila aquele item nao pode ser inserido
       return mochila(capacidade_max, peso, val, qtd_elementos-1); // chama a funcao pra 1 elemento a menos
  }

  else { // calcula o max para o enesimo intem includo e para o item nao incluido
    //int a =  val[qtd_elementos-1] + mochila(capacidade_max-peso[qtd_elementos-1], peso, val, qtd_elementos-1);
    return max(val[qtd_elementos-1] + mochila(capacidade_max-peso[qtd_elementos-1], peso, val, qtd_elementos-1),mochila(capacidade_max, peso, val, qtd_elementos-1));
  }

}*/

int main(){
    int casos_testes;
    scanf("%d",&casos_testes);
    while(casos_testes>0){
      int n=0,k=0,r=0,i,x,y,capacidade;
      scanf("%d",&n);
      int vet_poder[n+1], vet_peso[n+1];
      for ( i = 0; i < n; i++ ){
        scanf("%d %d", &x,&y);
        vet_poder[i]=x;
        vet_peso[i]=y;
      }

      scanf("%d",&k);
      scanf("%d",&r);

      capacidade= mochila(k, vet_peso, vet_poder, n);
      if (capacidade >= r ){
        printf("Missao completada com sucesso\n");
      }else
      {
        printf("Falha na missao\n");
      }
      casos_testes--;
    }
    return 0;
}