#include <stdio.h>

main(){


 char ch;

FILE *fp;//dosyay� tutan pointer

 if ((fp = fopen ("dosya1.txt", "r")) == NULL) {//dosya a��l�yor 
      printf("Dosya a�ma hatas�!");//a��lmazsa hata verir
     
  }
  
 
  
    while((ch = fgetc(fp)) != EOF )//dosya bitimi olana kadar sat�r sat�r okur
       {                           //fgetc sat�r sat�r al�r
           printf("%c", ch);       //EOF dosya bitimini g�sterir
       }
       

	fclose(fp);
}


