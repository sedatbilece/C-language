#include<stdio.h>


int i,pc,min,k=1,btime=0; //pc: progresss count
int burst[10],temp,j,arrvt[10],wait[10];

int p[10];

float waitort=0,waittop=0;//bekleme ortalamas� ve bekleme toplam�

main(){

for (i=1;i<11;i++){
	p[i-1]=i;

}

printf("\n prrcess say�s� giriniz :");
scanf("%d",&pc);
 
for(i=0;i<pc;i++)
{
printf("\t %d. islem burst time :",i+1);
scanf(" %d",&burst[i]);
printf("\t  %d. islem gelis s�resi :",i+1);
scanf(" %d",&arrvt[i]);
}
 

 //buble sort arrival timea g�re s�ralama i�lemi
for(i=0;i<pc;i++){

    for(j=0;j<pc;j++){
    	
        if(arrvt[i]<arrvt[j]){
        	
            temp=p[j];
            p[j]=p[i];
            p[i]=temp;
            
            temp=arrvt[j];
            arrvt[j]=arrvt[i];
            arrvt[i]=temp;
            
            temp=burst[j];
            burst[j]=burst[i];
            burst[i]=temp;
			            
						}
            }
}
 

for(j=0;j<pc;j++){
	
btime=btime+burst[j];

min=burst[k];

        for(i=k;i<pc;i++){
        	
        	//arrival time ve burst time ikiside i�lem i�in haz�r m�
             if (btime>=arrvt[i] && burst[i]<min){
             	
             	temp=p[k];
             	p[k]=p[i];
             	p[i]=temp;
             	
             	temp=arrvt[k];
             	arrvt[k]=arrvt[i];
             	arrvt[i]=temp;
             	
             	temp=burst[k];
             	burst[k]=burst[i];
             	burst[i]=temp;
				            
							 
							  
							    }
												 
                }
k++;

}

wait[0]=0;
int sum=0;
// waiting time= ( wt +bt) - arrt  i�lemi 
for(i=1;i<pc;i++){
sum=sum+burst[i-1];
wait[i]=sum-arrvt[i];
waittop=waittop+wait[i];
}
 
waitort=(waittop/pc);
 
printf("\n ortalama waiting time : %.2f", waitort);


}
