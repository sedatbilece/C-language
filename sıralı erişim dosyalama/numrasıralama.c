
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
main(){
srand(time(NULL));
int i,j,k,x;
int num[20];
char name[20][6];
char sesli[5]="aeiuo";
char sessiz[18]="bcdfghjklmnprstvyz";

// rastgele isim ve numara olu�turma
//not: isim 5 harfli numara 3 basamak olu�turulacakt�r
for(i=0;i<20;i++){
	
	
	
	for(j=0;j<6;j++){
		
     if(j%2==0){
     	x=rand()%6;
     	name[i][j]=sesli[x];
	 }
else{
	x=rand()%19;
     	name[i][j]=sessiz[x];
}
		
	}
	
	
	
	
    num[i]=20+rand()%81;//numara atama
}




FILE *fp;//dosyay� tutan pointer

 if ((fp = fopen ("dosya1.txt", "w")) == NULL) {//dosya a��l�yor 
      printf("Dosya a�ma hatas�!");//a��lmazsa hata verir
     
  }
 
 
 int sakla;
  	for(i=0;i<20;i++ ){
  		
		  for(j=0;j<20;j++){
  			
			  if(num[j]>num[j+1]){
  				
				  sakla=num[j];
  				
				  num[j]=num[j+1];
  			
			  	num[j+1]=sakla;
			  }
		  }
	  }
 
 for(j=0;j<20;j++){
 	
 	
 		
  fprintf(fp,"%d",num[j]);//yan�na numara yaz�l�yor
  fprintf(fp," ");
  
 	  for(i=0;i<5;i++){//isim yaz�l�yor
	fputc(name[j][i],fp);
             
			 }

  fprintf(fp,"\n");//alt sat�ra ge�iliyor
 	
 }

	fclose(fp);
}
