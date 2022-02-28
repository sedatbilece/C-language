## C Programming Language BRIAN W KERNIGHAN DENNIS M. RITCHIE 2th edition Chapter 1 özeti

    *Sedat Bilece*

C nispeten düşük seviyeleli bir dildir . Stringler ,kümeler ve listeler gibi yapılar içermez fakat bu yapıları oluşturmak ve işlem yapmak mümkündür.
Değişkenlerin tip tanımlamalarında hassastır bu işlemleri kullanıcıya bırakır . Hata durumunda compiler  derlemede tip hatası verir .

## C'de kodlama işlemine başlamak

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

## Programımızı çalıştıralım
Yukarıdaki kodu yazdıktan sonra .c uzantılı şekilde kaydedip
`cc hello.c`  ile derliyoruz bu sayede bize çalıştırılabilir bir 
`a.out` adında bir dosya çıkaracaktır. Bu dosyayı çalıştırdığımızda 
 `hello , world`yazısı ekrana bastırılacaktır . 
 
 ## Değişkenler ve Atamalar

bu alıştırmada sadece int(Integer) tipde değer görüyoruz fakat değişken tiplerimiz sadece bunlarla sınırlı değil.

 - char karakter - tek byte  `char c='h';`
 - short kısa tamsayı (integer) `short s=5;`
 - long uzun tamsayı (integer) `long int li=123213213;`
 - double 64-bit (double precision) `double int di= 24.8488;`
 - float (ondalıklı ) `float f=27.7;`

bu bölümde ise Fahrenhayt dereceleri ve onların Selsiyus (Santigrat) eşitliklerini gösteren tabloyu bastırmak için bir alıştırma yapalım
    
    #include <stdio.h>
    /* Fahrenhayt-Selsiyus tablosunu 
    bastır fahr = 0, 20, ... 300 için */
         main() {
    float fahr, celsius;
    int lower, upper, step;
    lower = 0; /* ısı tablosunun en düsük degeri */
    upper = 300; /* ısı tablosunun en yüksek degeri */
    step = 20; /* adım de˘geri */
    fahr = lower;
          while (fahr <= upper)  {
               celsius = (5.0/9.0) * (fahr-32.0);
               printf("%3.0f\t%6.1f\n", fahr, celsius);
               fahr = fahr + step;
               
                     }
    }
yukarıda virgüllü değerler önemli olduğu için float değerde değişkenler tanımladık. Peki printf içindeki 3.0f veya 6.1f nedir ve ne işe yarar?

    printf(" %a.bf");
diye bir kodumuz olsun burada a ve b rakam a float değerimizin en az basamak miktarını b ise noktadan sonraki ondalık basamağı temsil eder
`%6.1f`  için float sayımız en az 6 basamak ve virgülden sonra 1 hane olabilir örneğin `12345.8` .
## For Döngüsü

Yukarıdaki kodda while döngüsü yerine for kullanılabilirdi ama nasıl olacak 
kodda

     while (fahr <= upper)  {// kontrol 
     //işlem
     fahr = fahr + step; //arttırma işlemi
     }
fahr üst değerden küçükmü diye bir kontrol var 
ve altta el ile bir arttırma işlemi var demekki bize bir döngü oluşturmak için gerekli 3 şey lazım :

 - değişken
 - sınır (aralık)
 - arttırma veya azaltma (atlama) miktarı 

for döngüsü için ise şu şekilde:

    for(değişken ; sınır ; atlama){
    //code 
    }
yukarıdaki örnek için ise 

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
## Sembolik Sabitler
Okunurluk ve karışıklığı önlemek amacı ile program çalışması esnasında değişmeyecek sayıları main üstünde tanımlasak işlerimiz kolaylaşabilir.

    #define isim deger
    
    #define LOWER 0
    #define STEP 20
    #define UPPER 300
    
    for(fahr = LOWER; fahr <= UPPER; fahr += STEP)

şeklindende kullanılabilir.
## Karakter işlemleri

C'de karakterler işlenirken belirli işaretler ile okuma ve yazma işlemleri için standartlar oluşturulmuştur.

    Hello , World
    this is a example
    thnx for reading
Yukarıdaki metin c ile text dosyasına yazdırılırken alt alta olması için her satır sonuna `'\n '` işareti konur .
Başka bir işlem ise dosya sonuna `\0` konur bu ise textin sonuna gelindiğini gösterir .

    while(c!='\0'){
    c=getchar()// karakter okuma
    if(c=='\n'){
    count++ }
    }
Yukarıdaki kodda iki örnekte bulunmaktadır burada text bitene kadar döngü devam eder her satır sonunda count arttırılır.
`c!='\0'` yerine `c!=EOF ` kullanılabilmektedir.

## Diziler

Dizi tanımlarken 2 farklı şekilde tanımlayabiliriz . Dizinin değerleri tanımlama esnasında verilebilir:

    int dizi[5]={6,89,3,5,677};
veya 

    int dizi[5];
    for(i=0;i<5;i++){
    dizi[i]=i*5; }
diyerek dizimizi tanımlayabiliriz her iki durumdada dizi boyutu önceden verilmeli ve aşılmamalıdır eğer aşılırsa derleme esnasında hata verecektir. Yukarıdaki işlemler diğer veri tipleri içinde geçerlidir.
Dizi elemanlarına erişim için ise 0'dan başlayarak [] arasına istenen değerin indisi girilmelidir

    int dizi[5]={6,89,3,5,677};//dizimiz
    printf("%d" ,dizi[2]);
    //çıktı 2.indisteki değer 3 olur
    
## Fonksiyonlar
Fonksiyonlar Kod karmaşıklığı ve kullanılabilirliğini arttıran yapılardır . Tekrar tekrar çağrılabilirler . En başta main fonksiyonundan bahsederken değinmiştik her fonksiyonun adı, dönüş tipi ve parametreleri bulunur fakat adı hariç diğer iki parametre yazılmasada olabilir .

    dönüş_tipi fonk_adı (parametreler ){
    //işlem
    return dönüş_Değeri
    }
şeklinde fonksiyonumuzu tanımlayabiliriz. 

    




    
   
