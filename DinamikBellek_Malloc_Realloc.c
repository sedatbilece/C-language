#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	
	int *p;
	int secim=1, say=0;
	p=malloc(sizeof(int));
	printf("giri�i bitirmek i�in 0 'a  bas�n \n");
	while(secim!=0){
			printf("Bir deger giriniz:"); scanf("%d",&secim);
			p[say]=secim;
			say+=1;
			p=realloc(p,sizeof(int));
			
	}
	int i;
		for(i=0;i<	say;i++){
		printf("%d\n",p[i]);
	}
	
	
	
	free(p);
}
