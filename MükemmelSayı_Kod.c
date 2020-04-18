#include <stdio.h>

       int main() {
    int sayi,bol,top;
    
    sayi = 1;//atama yapýldý
    top = 0;//atama
    for (sayi = 1; sayi <= 15000; sayi++) {// sayi deðerini arttýrmak için 
        
    for (bol = 1; bol <= sayi - 1; bol++) {//böleni(böl)yi arttýrmak için  
            
        if (sayi % bol == 0) {//tam bölen bulmak için
        top +=  bol;//eðer sayýný böleni ise toplama ekler
                
        }
        }
        if (top == sayi) {//toplam sayýya eþit ise mükemme sayýdýr
            
            
        printf("==> %d <==\n",sayi);//yazdýrýlýr
        }
        top = 0;//toplam yeni sayý için sýfýrlanýr
        
        }
    
}
