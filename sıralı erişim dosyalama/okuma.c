#include <stdio.h>

main(){


 char ch;

FILE *fp;//dosyayý tutan pointer

 if ((fp = fopen ("dosya1.txt", "r")) == NULL) {//dosya açýlýyor 
      printf("Dosya açma hatasý!");//açýlmazsa hata verir
     
  }
  
 
  
    while((ch = fgetc(fp)) != EOF )//dosya bitimi olana kadar satýr satýr okur
       {                           //fgetc satýr satýr alýr
           printf("%c", ch);       //EOF dosya bitimini gösterir
       }
       

	fclose(fp);
}


