#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int main (){

int val;
int i=0;
int j;
printf("ka� i�lem olacak => \n");
		scanf("%d",&val);//ka� process olaca��
		
		
int list[val][3];
int temp[3]	;
int wt[val];
int at;
int pt;
int bt;
int wtt=0;
		//i�lemlerin de�er al�mlar�
		for (i=0;i<val;i++){
			printf("s�rayla i�lem numaras� , var�� zaman� , i�lem s�resi giriniz \n");
			for (j=0;j<3;j++){
				scanf("%d",&list[i][j]);
			}
			
		}
//i�lemlerin geli� zaman�na g�re
for (i=0;i<val-1;i++){
	for(j=0;j<3;j++){
		
		if(list[i][2]>list[i+1][2]){
			temp[0]=list[i+1][0];
			temp[1]=list[i+1][1];
			temp[2]=list[i+1][2];
			
			list[i+1][0]=list[i][0];
			list[i+1][1]=list[i][1];
			list[i+1][2]=list[i][2];
			
			list[i][0]=temp[0];
			list[i][1]=temp[1];
			list[i][2]=temp[2];
			
		}
	}
	
	
	
}
// s�ral� liste
for (i=0;i<val;i++){
	for(j=0;j<3;j++){
		
	printf("%d",list[i][j]);
	}
	printf("\n*****\n");
	
	
	
}
pt=0;

// waiting time hesab�
for(i=0;i<val;i++){
	bt=list[i][2];
	at=list[i][1];
	pt=pt+bt;
	
	wtt=pt-at;
	
	if(bt==pt){
		wtt=0;
	}
	wt[i]=wtt;
	
	
	
}
//waiting time yazd�rma
for(i=0;i<val;i++){
	
printf("%d \n",wt[i]);
		
}



	
}

/*


*/
