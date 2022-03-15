#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){


  
    int c=0;
    int k;
	int j=0;
	int i;
    char *code = malloc(40 * sizeof(char));
    int cnt=0;
FILE *fp;//dosyayý tutan pointer


if(argc>2){
printf("HATALI PARAMETRE: Program isminden sonra istenen text pathi verilmelidir !\n");
return 0;
}
else{

 if ((fp = fopen (argv[1], "r")) == NULL) {//dosya açýlýyor 
      printf("DOSYA AÇILAMADI:Okunacak dosya yolu hatalý !");//açýlmazsa hata verir
      return 0;
     
  }
// her seferinde 40 bayt ve tersten ( boþluklar dahil )
//0123456789012345678901234567890123456789

// etelpmoc ruo dnif lliw uoy egap siht nO
  
    while( ( *(code+j)   = fgetc(fp) )  !=  EOF )// karakter karakter dosya sonuna kadar okur
       {                            
           j++; 
      if(j%40 ==0){   // her kýrk bayt olunca for çaðrýlýr
      
      	
		  if(c==0){
		  	
		  	
		 	for(i=0;i<40;i++){ // *(code+j) son okunan karakter burdan geriye doðru gidilir
      			
      		printf("%c",*(code+i));
      		
		  }
		  	
		  }
		  else{
		  		for(i=1;i<=40;i++){ // *(code+j) son okunan karakter burdan geriye doðru gidilir
      			
      		printf("%c",*(code+j-i));
		  }
		  
		  	
		  }
		  
		  
		  	
		  
		  
		  
		 printf("\n ********************* \n");
		 
		 
		  
		 j=0 ; // 40 bayt dizimizi tekrar kullanabilmek için
		 c=1;
		  
      	
	  }   
         
       }


}


       

	fclose(fp);// dosya kapatýlmalý
	free(code); //bellek alaný serbest býrakýldý
	return 1;
}

