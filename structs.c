#include <stdio.h>

struct student{
	char isim[15];
	int numara;
	int yas;
	
	
	
	
};

void goster(struct student a){
	printf("%d",a.yas);
	a.yas=30;
	
}


int main (){
struct student sedat={"sedat", 170419038, 19};
printf("%d   ",sedat.yas);
sedat.yas=20;

printf("%d",sedat.yas);

goster(sedat);
printf("\n");
printf(sedat.isim[1]);



}
