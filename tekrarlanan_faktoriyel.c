#include <stdio.h>
int fak(int y){
	if(y<=1)
	return 1;
	else 
	return(y*fak(y-1));
	
}


int main(){
	int a,x;
	printf("bir sayı gir =");
	scanf("%d",&
	x);
if(x<0)
	printf("pozitif bir deger girin");
else
	printf("%d",fak(x));
	
	
}
