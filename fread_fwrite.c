

#include <stdio.h>


main(){
char *p="sedat bisdfdsfdsfsfdsmüh.";
FILE *fp;
char *p2;
char dizi[50];
int i;
fp=fopen("deneme.txt","w");
fwrite(p,25,1,fp);
fclose(fp);

fp=fopen("deneme.txt","r");
fread(dizi,15,1,fp);
puts(dizi);



}
