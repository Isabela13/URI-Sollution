#include <stdio.h>
 #include <string.h>

//Nome: Árvore de natal
int main() {
	
	int base,i,j,k,l,d,count;
	i=0;
	while(scanf("%d",&base)!=EOF){
		i=1;
		j=0;
		k=0;
		while(i<=base){
			k=0;
			k=(base-i)/2;
			l=0;
			for (l = 0; l < k; l++)
			{
				printf(" ");
			}
			for ( j = 0; j < i; j++){
				printf("*");
			}
			printf("\n");
			i=i+2;
		}
				d=0;
		d=(base-1)/2;
		for (count = 0; count < d; count++){
			printf(" ");
		}
		printf("*");
		printf("\n");
		d=0;
		d=(base-3)/2;
		for (count = 0; count < d; count++){
			printf(" ");
		}
		printf("***");
		printf("\n\n");
	}


    return 0;
}
