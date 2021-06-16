#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#define BOYUT 50

int fonk1(void);               /* Men� se�ene�i belirleme       */
void fonk2(void);              /* Bilgi giri�i                  */
void fonk3(void);              /* �sme g�re arama               */
void fonk4(void);              /* Soyad�na g�re arama           */
void fonk5(void);              /* Memleketine g�re arama        */
void fonk6(int id1, int id2);  /* Bilgileri ekranda g�sterme    */
void fonk7(void);              /* B�t�n kay�tlar�n listelenmesi */
void fonk8(void);              /* Dosyaya kaydetme              */
void fonk9(void);              /* Dosyadan y�kleme              */
void fonk10(void);             /* B�t�n kay�tlar�n silinmesi    */

char cgdizi1[BOYUT][15];       /* �sim      */
char cgdizi2[BOYUT][15];       /* Soyad�    */
char cgdizi3[BOYUT][15];       /* Memleketi */
char cgdizi4[BOYUT][15];       /* Tahsili   */

int igd = 0;                   /* Son kay�t */

int main(void)
{
  int id;

  fonk9(); /* Dosyadan y�kleme */

  do {
     printf("\n");
     id = fonk1();

     switch (id) {
        case 1 : fonk2();  /* Kay�t giri�i */
           break;
        case 2 : fonk3();  /* �sme g�re arama */
           break;
        case 3 : fonk4();  /* Soyad�na g�re arama */
           break;
        case 4 : fonk5();  /* Memleketine g�re arama */
           break;
        case 5 : fonk7();  /* B�t�n kay�tlar�n listelenmesi */
           break;
        case 6 : fonk10(); /* Dosyadaki b�t�n kay�tlar�n silinmesi */
           break; 
     }
  } while (id!=7);
}

/* Bir men� se�ene�i se�menizi sa�lar. */
int fonk1(void)
{
  int id;

  printf("[1]. Kay�t giri�i\n");
  printf("[2]. �sme g�re arama\n");
  printf("[3]. Soyad�na g�re arama\n");
  printf("[4]. Memleketine g�re arama\n");
  printf("[5]. B�t�n kay�tlar�n listelenmesi\n");
  printf("[6]. B�t�n kay�tlar�n silinmesi\n");
  printf("[7]. ��k��\n");

  do {
     printf("\nSe�ene�inizi giriniz [1-7]: ");
     id = getche()-'0';
     printf("\n");
  } while (id<1 || id>7);

  return id;
}

/* Veritaban�na bilgi giri�i */
void fonk2(void)
{
  int id;

  for (id=igd; id<BOYUT; id++) {
       printf("�smi (��k�� i�in Enter tu�una bas�n�z):");
       gets(cgdizi1[id]);
       if (!*cgdizi1[id]) break;
       printf("Soyad�: ");
       gets(cgdizi2[id]);
       printf("Memleketi: ");
       gets(cgdizi3[id]);
       printf("Tahsili: ");
       gets(cgdizi4[id]);
  }
  igd = id;
  fonk8();
}

/* �sme g�re arama */
void fonk3(void)
{
  char cdizi[15];
  int id1, id2;

  printf("Arad���n�z �ahs�n ismini giriniz: ");
  gets(cdizi);
  id2 = 0;

  for (id1=0; id1<igd; id1++) {
       if (!strcmp (cdizi, cgdizi1[id1])) {
           fonk6(id1, id2);
           id2 = 1;
           printf("\n");
       }
  }
  if (!id2) printf("Bulunamad�!\n");
}

/* Soyad�na g�re arama */
void fonk4(void)
{
  char cdizi[15];
  int id1, id2;

  printf("Arad���n�z �ahs�n soyad�n� giriniz: ");
  gets(cdizi);
  id2 = 0;

  for (id1=0; id1<igd; id1++) {
      if (!strcmp (cdizi, cgdizi2[id1])) {
          fonk6 (id1, id2);
          id2 = 1;
          printf("\n");
      }
  }
  if (!id2) printf("Bulunamad�!\n");
}

/* Memleketine g�re arama */
void fonk5(void)
{
  char cdizi[15];
  int id1, id2;

  printf("Arad���n�z �ahs�n memleketini giriniz: ");
  gets(cdizi);
  id2 = 0;

  for (id1=0; id1<igd; id1++) {
       if (!strcmp (cdizi, cgdizi3[id1])) {
           fonk6 (id1, id2);
           id2=1;
           printf("\n");
       }
  }
  if (!id2) printf("Bulunamad�!\n");
}

/* Bilgileri ekranda g�sterme */
void fonk6(int id1, int id2)
{
  if (!id2) {
      printf("\n");
      printf("ADI            SOYADI         MEMLEKET�      TAHS�L�\n");
  }

  printf("%-15s", cgdizi1[id1]);
  printf("%-15s", cgdizi2[id1]);
  printf("%-15s", cgdizi3[id1]);
  printf("%-15s", cgdizi4[id1]);
}

/* B�t�n kay�tlar�n listelenmesi */
void fonk7(void)
{
  int id;

  id = 0;
  printf("\nADI            SOYADI         MEMLEKET�      TAHS�L�\n");

  do {
     printf("%-15s", cgdizi1[id]);
     printf("%-15s", cgdizi2[id]);
     printf("%-15s", cgdizi3[id]);
     printf("%-15s", cgdizi4[id]);

     printf("\n");
     id++;
  } while (*cgdizi1[id]);
}

/* Kay�tlar�n dosyaya kaydedilmesi */
void fonk8(void)
{
  FILE *fp;

  if ((fp=fopen ("veri.txt", "w")) == NULL) {
      printf("Dosya a��lamad�!\n");
      exit(1);
  }

  fwrite (&igd, sizeof igd, 1, fp);
  fwrite (cgdizi1, sizeof cgdizi1, 1, fp);
  fwrite (cgdizi2, sizeof cgdizi2, 1, fp);
  fwrite (cgdizi3, sizeof cgdizi3, 1, fp);
  fwrite (cgdizi4, sizeof cgdizi4, 1, fp);

  fclose (fp);
}

/* Kay�tlar�n dosyadan y�klenmesi */
void fonk9(void)
{
  FILE *fp;

  if ((fp=fopen ("veri.txt", "r")) == NULL) {
      printf("Veri dosyas� mevcut de�il!\n");
      return;
  }

  fread (&igd, sizeof igd, 1, fp);
  fread (cgdizi1, sizeof cgdizi1, 1, fp);
  fread (cgdizi2, sizeof cgdizi2, 1, fp);
  fread (cgdizi3, sizeof cgdizi3, 1, fp);
  fread (cgdizi4, sizeof cgdizi4, 1, fp);

  fclose (fp);
}

/* B�t�n kay�tlar�n silinmesi */
void fonk10(void)
{
  printf("B�t�n kay�tlar silinecek!\n");
  printf("��lem devam etsin mi? (E/H) ");
  if (toupper (getch ()) == 'E') remove ("veri.txt");
  printf("\n");
}
