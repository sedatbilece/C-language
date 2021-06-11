#include <stdio.h>

main(){
srand(time(NULL));
int i,j,k;
int num[20];
int name[20][5];

// rastgele isim ve numara oluþturma
//not: isim 5 harfli numara 3 basamak oluþturulacaktýr
for(i=0;i<20;i++){
	
	for(j=0;j<5;j++){
		name[i][j]=98+rand()%24;//isim atama
	}
    num[i]=100+rand()%900;//numara atama
}


FILE *fp;//dosyayý tutan pointer

 if ((fp = fopen ("dosya1.txt", "w")) == NULL) {//dosya açýlýyor 
      printf("Dosya açma hatasý!");//açýlmazsa hata verir
     
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
 	
 	  for(i=0;i<5;i++){//isim yazýlýyor
	fputc(name[j][i],fp);
             
			 }
  fprintf(fp,"%d",num[j]);//yanýna numara yazýlýyor
  
  fprintf(fp,"\n");//alt satýra geçiliyor
 	
 }

	fclose(fp);
}
