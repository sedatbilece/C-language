#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// linux �al��t�rma i�in gcc "dosyaad�" -lpthread

void sira1(){
	
	while(1){
		printf("sira1\n");
		sleep(1);
	}
}

void* sira2(){
	
	while(1){
		printf("sira2\n");
		sleep(1);
	}
	return NULL;
}


main(){
	
	pthread_t t1;// t1 ad�nda thread tan�mlad�k
	
	              //tread adresi , null , fonksiyon adresi (pointer ile ), null
	pthread_create(&t1,NULL,sira2,NULL);
	
	
	sira1();
	sleep(1);// bir miktar beklemesi icin thread almak i�in
	
	
	return 0;
}
