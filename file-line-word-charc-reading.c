#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

   FILE *fp;
   
   int i;
    int argcnt=0;

int yazdir(int argc,char **argv,char *dosya){
int satir=0;
int ch=0;
int kelime=0;
char cold='x';
int c;
int key=0;

 if(argc>1){//dosya oku 
 
 fp = fopen(dosya,"r");
   if(fp == NULL) {//dosya acilamaz ise
      printf("\nHATA: %s dosyasi acilamiyor !",dosya);
      printf("\nDüzgün  kullanım için\n>./ks -help yaziniz.");
      return(-1);
   }
   
   
    
 
 }//dosya oku son
 else{//stdinden oku
 key=1;
 fp = stdin;
   if(fp == NULL) {//dosya acilamaz ise
      printf("\nHATA: stdin okunamıyor !");
      return(-1);
   }
 
 
 }//stdin end
 
 
 
 do {//DO
    	
      c = fgetc(fp);
      //printf("%c", c);
      
      
      if(c=='\n'){//Satir okuma
      	satir+=1;
	  }
	  
	  
	  if(isspace(c)){// iki boşluk arka arkaya ise veya tabdan sonra boşluk varsa kelime olarak saymayız
	  	if(!isspace(cold)){
	  		kelime+=1;
		  }
	  }
	  
	  
	cold=c;
   ch+=1;   
   } while(!feof(fp));

if(key==0){
printf("\n %s ",dosya);
}
if(argcnt==0){
printf("%d %d %d ",satir+1,kelime,ch);

}
else{
for(i=0;i<argc;i++){// arg�man kontrol�


if(strcmp(argv[i],"-l")==0){

printf("%d ",satir+1);// Satir Yazdirma
}
if(strcmp(argv[i],"-w")==0){

printf("%d ",kelime);// Kelime Yazdirma
}
if(strcmp(argv[i],"-c")==0){

printf("%d ",ch);// Karakter Yazdirma
}

}

}//else end
fclose(fp);
 
 

}//yazdir end

int main (int argc,char **argv) {
	
   
   


for(i=0;i<argc;i++){// fazla argüman verilmiş diye kontrol


if(strcmp(argv[i],"-help")==0){// .ks -help i�in

printf("Programı ./ks 'dosyaadi' seklinde cagirabilirsiniz yada assagidaki parametreleri kullanabilirsiniz \n");
printf("> -l : sadece satir sayisini yazdirir\n> -w : sadece kelime sayisini yazdirir\n> -c : sadece harf sayisini yazdirir\n");
printf("Yukaridaki parametreler ortak şekilde kullanılabilir örn :\n./ks -w 'dosyaadi'\n./ks -w -l 'dosyaadi'\n./ks -w -l -c 'dosyaadi' şeklinde olabilir");
return -1;
}

if(strcmp(argv[i],"-l")==0){

argcnt+=1;
}
if(strcmp(argv[i],"-w")==0){

argcnt+=1;
}
if(strcmp(argv[i],"-c")==0){

argcnt+=1;
}

}


for(i=1;i<=argcnt;i++){

if(   !(strcmp(argv[i],"-l")==0 || strcmp(argv[i],"-w")==0 || strcmp(argv[i],"-c")==0)  ){
printf("HATA: farklı parametre verildi !");
printf("\nDüzgün parametre kullanımı için\n>./ks -help yaziniz.");
return -1;

}


}



if( (argc-argcnt)==2  ){
    yazdir(argc,argv,argv[argcnt+1]);
}
else if((argc-argcnt)==3 ){
   yazdir(argc,argv,argv[argcnt+1]);
   yazdir(argc,argv,argv[argc-1]);
}
else if(argc==1){
yazdir(argc,argv,argv[argcnt+1]);
}




   return(0);
}
