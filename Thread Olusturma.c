#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
// linux çalýþtýrma için gcc "dosyaadý" -lpthread

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
	
	pthread_t t1;// t1 adýnda thread tanýmladýk
	
	              //tread adresi , null , fonksiyon adresi (pointer ile ), null
	pthread_create(&t1,NULL,sira2,NULL);
	
	
	sira1();
	sleep(1);// bir miktar beklemesi icin thread almak için
	
	
	return 0;
}
