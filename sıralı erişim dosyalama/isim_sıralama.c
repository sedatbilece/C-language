#include <stdio.h>

main(){
srand(time(NULL));
int i,j,k;
int num[20];
int name[20][5];

// rastgele isim ve numara olu�turma
//not: isim 5 harfli numara 3 basamak olu�turulacakt�r
for(i=0;i<20;i++){
	
	for(j=0;j<5;j++){
		name[i][j]=98+rand()%24;//isim atama
	}
    num[i]=100+rand()%900;//numara atama
}


FILE *fp;//dosyay� tutan pointer

 if ((fp = fopen ("dosya1.txt", "w")) == NULL) {//dosya a��l�yor 
      printf("Dosya a�ma hatas�!");//a��lmazsa hata verir
     
  }
 
 
 int sakla;
  	for(i=0;i<20;i++ ){
  		
		  for(j=0;j<20;j++){
  			
			  if(name[j]>name[j+1]){
  				
				  sakla=name[j];
  				
				  name[j]=name[j+1];
  			
			  	name[j+1]=sakla;
			  }
		  }
	  }
 
 for(j=0;j<20;j++){
 	
 	  for(i=0;i<5;i++){//isim yaz�l�yor
	fputc(name[j][i],fp);
             
			 }
  fprintf(fp,"%d",num[j]);//yan�na numara yaz�l�yor
  
  fprintf(fp,"\n");//alt sat�ra ge�iliyor
 	
 }

	fclose(fp);
}
