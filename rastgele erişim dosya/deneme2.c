#include <stdio.h>

typedef struct{
	int hesapno;
	char *isim;
	float bakiye;
}sthesap;

 int i;
 long uz;
 char ch;
main(){
	char dizi[20]="sedat bilece 1024";
	char dizitut[20];
	sthesap hesap1;
	FILE *fp;
	 if ((fp = fopen ("dosya1.txt", "w")) == NULL) {//dosya açýlýyor 
      printf("Dosya açma hatasý!");//açýlmazsa hata verir
     
  }
  ///////////
 fwrite(dizi,sizeof(dizi),1,fp);
  fclose(fp);
  
   if ((fp = fopen ("dosya1.txt", "r")) == NULL) {//dosya açýlýyor 
      printf("Dosya açma hatasý!");//açýlmazsa hata verir
     
  }
  else{
  	uz=fseek(fp,0,SEEK_END);
 for(i=uz;i>0;i--){
 ch=	fgetc(fp);
 printf("%c ",ch);
 }
  }
 
 
  /////////
fclose(fp);
return 0;
}
