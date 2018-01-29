#include <stdio.h>
 #include <string.h>
int main() {
 	int c, b, e,i,imprime,j,tamanho;
	int count,count2,k;
	char str[10000000],inverte[10000000],vazia[10000000];
	scanf("%d",&c);
	for (k=0;k<c;k++){
		i=0;
		j=0;
		tamanho=0;
		strcpy(inverte,vazia);
		count = 0;
		count2 = 0;
		scanf("%d",&b);
		scanf("%d",&e);
		for (i=b;i<=e;i++){
			imprime=b+count;
			 printf("%d",imprime);
			sprintf(str,"%d",imprime);
			strcat(inverte,str);
			count ++;
		}
		//printf("%s",inverte);
		tamanho=strlen(inverte);
		tamanho--;
		for(j=tamanho;j>=0;j--){	
			printf("%c",inverte[j]);
		}

		printf("\n");

	}

    return 0;
}
