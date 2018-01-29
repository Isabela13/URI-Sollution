#include <stdio.h>

//Nome: Conversão de tempo
 
int main() {
 
   	int n,minutos,segundos,horas;
	scanf("%d",&n);
	if (n<60){
		printf("0:0:%d\n",n);
   	}else if(n<3600 && n>=60){
		minutos=n/60;
		segundos=n%60;
		printf("0:%d:%d\n",minutos,segundos);
		
	}else {
		horas=n/3600;
		minutos=(n%3600)/60;
		segundos=n%60;
		printf("%d:%d:%d\n",horas,minutos,segundos);
		
	}
 
    return 0;
}
