#include <stdio.h>




int main(){
	
int i;
            //0, 1, 2   dizide 0.indis x1 1.indis x2 2.indis target(t) veya y yi temsil eder
int d[4][3]={{1,1,-1},
             {1,-1,1},
			 {-1,1,-1},
			 {-1,-1,-1}
			};



float x=0.2;//learning rate değerimiz

//ağırlıklar
float w1=0.48;
float w2=-0.24;

//bias değeri
float b=-0.27;


float e=0;// hata miktarı


float yin=0;//çarpımlar toplamı


//her iterasyon kendinden önceki w1,w2 ve bias değerlerini miras alır

for (i=0;i<4;i++){
	
 //yin = w1 *x1i +   w2 * x2i
	yin= w1*d[i][0] + w2* d[i][1] + b;
	
	e= d[i][2] - yin;
	
//delta rule = x*e*xi
//w(new)=w(old)+delta_rule
	w1=w1+ x * e * d[i][0];
	w2=w2+ x * e * d[i][1];
	
	b =b * x *e;
	
	printf("iteration : %d \n",i+1);
	
	printf("yin: %f    e: %f   w1: %f   w2: %f b: %f",yin,e,w1,w2,b);
	
	printf("\n *************** \n");
	
	
	
}

}
