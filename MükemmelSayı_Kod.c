#include <stdio.h>

       int main() {
    int sayi,bol,top;
    
    sayi = 1;//atama yap�ld�
    top = 0;//atama
    for (sayi = 1; sayi <= 15000; sayi++) {// sayi de�erini artt�rmak i�in 
        
    for (bol = 1; bol <= sayi - 1; bol++) {//b�leni(b�l)yi artt�rmak i�in  
            
        if (sayi % bol == 0) {//tam b�len bulmak i�in
        top +=  bol;//e�er say�n� b�leni ise toplama ekler
                
        }
        }
        if (top == sayi) {//toplam say�ya e�it ise m�kemme say�d�r
            
            
        printf("==> %d <==\n",sayi);//yazd�r�l�r
        }
        top = 0;//toplam yeni say� i�in s�f�rlan�r
        
        }
    
}
