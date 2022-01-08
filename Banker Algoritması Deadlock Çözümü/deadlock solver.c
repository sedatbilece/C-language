

  
 // Bu kod deadlocký anýnda kaynak eklemesi yaparak çözer
 
#include <stdio.h>
int main()
{
    
 int temp;
    int n, m, i, j, k;
    n = 5; 
    m = 3; 
    
    //          daðýtýlmýþ kaynaklar
    int alloc[5][3] = { { 0, 1, 0 }, // P0    
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
 
                    //  A  B  C
    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix deðiþtirerek lock kontrolü ve gere
                      { 3, 2, 2 }, // P1
                      { 9, 0, 2 }, // P2
                      { 2, 2, 2 }, // P3
                      { 4, 3, 3 } }; // P4  //p4 C için deadlock olacak  elle alloc tamamlanýrsa düzelir
 
    int avail[3] = { 3, 3, 2 }; // mevcut kaynaklar
 
    int f[n], ans[n], ind = 0;
    
    for (k = 0; k < n; k++) {// deadlock için f dizisine 0 atanýyor
        f[k] = 0;
    }
  
    //need listesi 
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    
    //kontrol iþlemi
    int y = 0;
    for (k = 0; k < 5; k++) {// her bir process için çalýþýr
    	
    	
        for (i = 0; i < n; i++) {// her döngüde 1 process iþler 
        	
            if (f[i] == 0) {//process iþlenmemiþ ise
 
                int flag = 0;
                
                // gereken sayý elimizde varmý kontrolü 
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                    	
                    	temp= i;//****bu hangi processte kalýndýðýný gösterrir break dýþarý çýkarýz
                    	
                        flag = 1;//deaclock kaydý
                        
                       avail[j] += need[temp][j] - avail[j] ;//deadlock'a neden olan kaynak kadar ekleme yapýlýr ve çözülür
                         //break; ile döngüden çýkmaya gerek kalmaz 
                    }
                }
 //iþi biten processdeki deðerleri mevcut deðerler atýyor
                if (flag == 0) {//deadlock yok ise
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
            
        }
    }
    
   
      int flag = 1;
       
      for( i=0;i<n;i++)
    {
      if(f[i]==0)// iþlenmemiþ ise deadlock var demektir
      {
        flag=0;
         /*
         printf(" \n process %d istenileni karsilamýyor \n",temp);
         printf("P%d gereken degeri ==> ",temp);
         for (j=0;j<3;j++){
         	if(j==0){
         		if(need[temp][j] - avail[j] >0  ){//neden 0dan büyük dedik elmizde karþýlayan deðerler negatif çýkacaktý
         		//örneðin elimizde 10 tane olsun gerekli 8 tane 8-10 dan -2 çýkacaktý bize gerekli olanlar lazým sadece
         		
         		printf("A: %d",need[temp][j] - avail[j]);
         		
			 }
			 }
			 if(j==1){
         		if(need[temp][j] - avail[j] >0  ){
         		
         		printf("B: %d",need[temp][j] - avail[j]);
         		
			 }
			 }
			 if(j==2){
         		if(need[temp][j] - avail[j] >0  ){
         		
         		printf("C: %d",need[temp][j] - avail[j]);
         		
			 }
			 }
			
         	
		 }
		 */
        break;
        
        
              }
    }
     
      if(flag==1)// flag==1 ise hiç deadlocka girilmemiþ demektir
    {
      printf("sistem sorunsuz calismakta\n");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }
    
    
    
    //buradaki for lock durumunda hangi processlerin tamamlanamadýðýný gösterir
    printf ("\n ***************** \n ");
    for(i=0;i<5;i++){
    	printf ("%d   ",f[i]);
	}
     
 
    return (0);
 
    
}
