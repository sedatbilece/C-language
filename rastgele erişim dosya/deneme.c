#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#define BOYUT 50

int fonk1(void);               /* Menü seçeneði belirleme       */
void fonk2(void);              /* Bilgi giriþi                  */
void fonk3(void);              /* Ýsme göre arama               */
void fonk4(void);              /* Soyadýna göre arama           */
void fonk5(void);              /* Memleketine göre arama        */
void fonk6(int id1, int id2);  /* Bilgileri ekranda gösterme    */
void fonk7(void);              /* Bütün kayýtlarýn listelenmesi */
void fonk8(void);              /* Dosyaya kaydetme              */
void fonk9(void);              /* Dosyadan yükleme              */
void fonk10(void);             /* Bütün kayýtlarýn silinmesi    */

char cgdizi1[BOYUT][15];       /* Ýsim      */
char cgdizi2[BOYUT][15];       /* Soyadý    */
char cgdizi3[BOYUT][15];       /* Memleketi */
char cgdizi4[BOYUT][15];       /* Tahsili   */

int igd = 0;                   /* Son kayýt */

int main(void)
{
  int id;

  fonk9(); /* Dosyadan yükleme */

  do {
     printf("\n");
     id = fonk1();

     switch (id) {
        case 1 : fonk2();  /* Kayýt giriþi */
           break;
        case 2 : fonk3();  /* Ýsme göre arama */
           break;
        case 3 : fonk4();  /* Soyadýna göre arama */
           break;
        case 4 : fonk5();  /* Memleketine göre arama */
           break;
        case 5 : fonk7();  /* Bütün kayýtlarýn listelenmesi */
           break;
        case 6 : fonk10(); /* Dosyadaki bütün kayýtlarýn silinmesi */
           break; 
     }
  } while (id!=7);
}

/* Bir menü seçeneði seçmenizi saðlar. */
int fonk1(void)
{
  int id;

  printf("[1]. Kayýt giriþi\n");
  printf("[2]. Ýsme göre arama\n");
  printf("[3]. Soyadýna göre arama\n");
  printf("[4]. Memleketine göre arama\n");
  printf("[5]. Bütün kayýtlarýn listelenmesi\n");
  printf("[6]. Bütün kayýtlarýn silinmesi\n");
  printf("[7]. Çýkýþ\n");

  do {
     printf("\nSeçeneðinizi giriniz [1-7]: ");
     id = getche()-'0';
     printf("\n");
  } while (id<1 || id>7);

  return id;
}

/* Veritabanýna bilgi giriþi */
void fonk2(void)
{
  int id;

  for (id=igd; id<BOYUT; id++) {
       printf("Ýsmi (Çýkýþ için Enter tuþuna basýnýz):");
       gets(cgdizi1[id]);
       if (!*cgdizi1[id]) break;
       printf("Soyadý: ");
       gets(cgdizi2[id]);
       printf("Memleketi: ");
       gets(cgdizi3[id]);
       printf("Tahsili: ");
       gets(cgdizi4[id]);
  }
  igd = id;
  fonk8();
}

/* Ýsme göre arama */
void fonk3(void)
{
  char cdizi[15];
  int id1, id2;

  printf("Aradýðýnýz þahsýn ismini giriniz: ");
  gets(cdizi);
  id2 = 0;

  for (id1=0; id1<igd; id1++) {
       if (!strcmp (cdizi, cgdizi1[id1])) {
           fonk6(id1, id2);
           id2 = 1;
           printf("\n");
       }
  }
  if (!id2) printf("Bulunamadý!\n");
}

/* Soyadýna göre arama */
void fonk4(void)
{
  char cdizi[15];
  int id1, id2;

  printf("Aradýðýnýz þahsýn soyadýný giriniz: ");
  gets(cdizi);
  id2 = 0;

  for (id1=0; id1<igd; id1++) {
      if (!strcmp (cdizi, cgdizi2[id1])) {
          fonk6 (id1, id2);
          id2 = 1;
          printf("\n");
      }
  }
  if (!id2) printf("Bulunamadý!\n");
}

/* Memleketine göre arama */
void fonk5(void)
{
  char cdizi[15];
  int id1, id2;

  printf("Aradýðýnýz þahsýn memleketini giriniz: ");
  gets(cdizi);
  id2 = 0;

  for (id1=0; id1<igd; id1++) {
       if (!strcmp (cdizi, cgdizi3[id1])) {
           fonk6 (id1, id2);
           id2=1;
           printf("\n");
       }
  }
  if (!id2) printf("Bulunamadý!\n");
}

/* Bilgileri ekranda gösterme */
void fonk6(int id1, int id2)
{
  if (!id2) {
      printf("\n");
      printf("ADI            SOYADI         MEMLEKETÝ      TAHSÝLÝ\n");
  }

  printf("%-15s", cgdizi1[id1]);
  printf("%-15s", cgdizi2[id1]);
  printf("%-15s", cgdizi3[id1]);
  printf("%-15s", cgdizi4[id1]);
}

/* Bütün kayýtlarýn listelenmesi */
void fonk7(void)
{
  int id;

  id = 0;
  printf("\nADI            SOYADI         MEMLEKETÝ      TAHSÝLÝ\n");

  do {
     printf("%-15s", cgdizi1[id]);
     printf("%-15s", cgdizi2[id]);
     printf("%-15s", cgdizi3[id]);
     printf("%-15s", cgdizi4[id]);

     printf("\n");
     id++;
  } while (*cgdizi1[id]);
}

/* Kayýtlarýn dosyaya kaydedilmesi */
void fonk8(void)
{
  FILE *fp;

  if ((fp=fopen ("veri.txt", "w")) == NULL) {
      printf("Dosya açýlamadý!\n");
      exit(1);
  }

  fwrite (&igd, sizeof igd, 1, fp);
  fwrite (cgdizi1, sizeof cgdizi1, 1, fp);
  fwrite (cgdizi2, sizeof cgdizi2, 1, fp);
  fwrite (cgdizi3, sizeof cgdizi3, 1, fp);
  fwrite (cgdizi4, sizeof cgdizi4, 1, fp);

  fclose (fp);
}

/* Kayýtlarýn dosyadan yüklenmesi */
void fonk9(void)
{
  FILE *fp;

  if ((fp=fopen ("veri.txt", "r")) == NULL) {
      printf("Veri dosyasý mevcut deðil!\n");
      return;
  }

  fread (&igd, sizeof igd, 1, fp);
  fread (cgdizi1, sizeof cgdizi1, 1, fp);
  fread (cgdizi2, sizeof cgdizi2, 1, fp);
  fread (cgdizi3, sizeof cgdizi3, 1, fp);
  fread (cgdizi4, sizeof cgdizi4, 1, fp);

  fclose (fp);
}

/* Bütün kayýtlarýn silinmesi */
void fonk10(void)
{
  printf("Bütün kayýtlar silinecek!\n");
  printf("Ýþlem devam etsin mi? (E/H) ");
  if (toupper (getch ()) == 'E') remove ("veri.txt");
  printf("\n");
}
