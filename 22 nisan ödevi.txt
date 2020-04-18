#include <stdio.h>

struct student{
	char isim[5][20];
int uzunluk;
int eluz[5];
int sessiz[5];
int seslis[5];

	
};
int i,j,k,h;
int a;
char sesli[8]="aeıiuüoö";
int kar,benzer=0,temp=0;
int x,y;

void degerata(struct student  *ptr){//struct daki isimlere deger atandı
	for(i=0;i<5;i++){
		gets((ptr->isim[i]));
	}

}




void hesapla(struct student *ptr){// isimlerin uzunluk ve sesli harf deegreleri hesaplanıp struct dizilerine atandı
	
	
	for(i=0;i<5;i++){//uzunluk  bulucu
	(ptr->eluz[i])=strlen((ptr->isim[i]));
	
}



for(i=0;i<5;i++){//sesli harft bulucu
	a=0;
	for(j=0;j<ptr->eluz[i];j++){
		for(k=0;k<8;k++){
			if(ptr->isim[i][j]==sesli[k]){
				a+=1;
			}
		}
	}
	ptr->seslis[i]=a;
	ptr->sessiz[i]=ptr->eluz[i]-ptr->seslis[i];
}


for(i=0;i<5;i++){
	for(j=0;j<5;j++){
		if(ptr->eluz[i]>ptr->eluz[j]){
			kar=ptr->eluz[j];
		}
		for(k=0;k<kar;k++){
			if(ptr->isim[i][k]==ptr->isim[j][k]){
				benzer+=1;
			}
		}
		
		if(benzer>temp){
	if(benzer!=kar){
			temp=benzer;
		x=i;
		y=j;
	    }
	}
	benzer=0;
	
	}
	
} 


	
}





void show(struct student *ptr){
		printf("\n");
	for(i=0;i<5;i++){
		puts(ptr->isim[i]);
		printf("%d. kelimenin uzunlugu %d \n",i+1,ptr->eluz[i]);// kelime uzunlukları
		printf("%d. kelimedeki sesli  %d sessiz %d\n",i+1,ptr->seslis[i],ptr->sessiz[i]);
		printf("\n");
		
		
	}
	
	printf("en cok benzeyen kelimeler");
	printf("\n");
puts(ptr->isim[x]);
puts(ptr->isim[y]);

	
}




int main (){
struct student *sedatptr,sedat;
sedatptr=&sedat;



degerata(sedatptr);

hesapla(sedatptr);

show(sedatptr);




}
