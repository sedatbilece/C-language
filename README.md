**C Programming Language BRIAN W KERNIGHAN
DENNIS M. RITCHIE 2th edition Chapter 1 özeti**
*Sedat Bilece*
C nispeten düşük seviyeleli bir dildir . Stringler ,kümeler ve listeler gibi yapılar içermez fakat bu yapıları oluşturmak ve işlem yapmak mümkündür.
Değişkenlerin tip tanımlamalarında hassastır bu işlemleri kullanıcıya bırakır . Hata durumunda compiler  derlemede tip hatası verir .

**C'de kodlama işlemine başlamak**

    #include <stdio.h>
    main(){
    printf("hello, world\n");
    }
    
   buradaki kodumuzu baştan inceleyelim 
   

    #include <stdio.h>
include bir library dahil edeceğimizi bildiriyoruz , ardından library ismini <> taglari arasına yazıyoruz kütüphanemiz ise stdio.h 
standart giriş çıkış (standart input/output) kütüphanesi 
.h uzantısı ise header yani kütüphane tarzındaki temel işlemlerin bulunduğu dosya tipidir

    main(){ 
    //some code
     }
   main fonksiyonumuz program derlendikten sonra dosyada çalıştırılan fonksiyonumuzdur tanımlamalar ve bazı fonksiyonlar main dışında yazılabilir yapılacak işlemler main fonksiyonu üzerinde yapılır. Bir fonksiyon olduğu için dönüş tipi ve parametre alabilir  .
   

    printf("hello, world\n");
   printf() fonksiyonu stdio içerisinde bulunan ekrana konsol ekranı üzerinden çıktı vermemizi sağlayan fonksiyondur.

**Programımızı çalıştıralım**
Yukarıdaki kodu yazdıktan sonra .c uzantılı şekilde kaydedip
`cc hello.c`  ile derliyoruz bu sayede bize çalıştırılabilir bir 
`a.out` adında bir dosya çıkaracaktır. Bu dosyayı çalıştırdığımızda 
 `hello , world`yazısı ekrana bastırılacaktır . 
 
 

   

   




