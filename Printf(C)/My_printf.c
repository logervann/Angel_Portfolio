#include <unistd.h> //
#include <stdio.h> //
#include <stdarg.h> //
#include <string.h> //Pour l'affichage de
#include <ctype.h> //Pour l'affichage de caractère

void my_putchar(char c) {
  write(1, &c, 1);
}

void my_putstr(char *s) {
    int i = 0;
    while (s[i]) {
        my_putchar(s[i]);
        i++;
    }
}


void *my_strcpy(char *dest, char *src)
{
int i;

i = 0;
while (src[i])
{
  dest[i] = src[i++];
}
dest[i] = '\0';
return (dest);
}


size_t my_strlen(const char* s)
{
    size_t i;

    for(i = 0 ; s[i] ; i++);

    return i;
}

char* convertion(const int x,const unsigned short base, char* resultat) {
  char HEX[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
  int i, j, cpt, reste;
  char chaine[34];
  int quotient = x;

  if ((base<2)||(16<base)) {
    my_putstr("base non valide \n");
    return NULL;
  }

  if (quotient<0) {
    quotient = -quotient;
  }
  cpt = 0;

  while (quotient!=0) {
    reste = quotient % base ;
    quotient = (int) quotient/base;
    chaine[cpt]=HEX[reste];
    cpt++;
  }

  if (x<0) {
    chaine[cpt]='-';
    cpt++;
  }
  for(i = 0, j=cpt-1 ; i< cpt ;i++, j--) {
    resultat[j]=chaine[i];
  }
  resultat[cpt]=0;
  return resultat;
}

int my_printf(char *p,...)
{
  int i=0,j=0;

  va_list ap;
  va_start(ap, p);
  char v[30];

  unsigned s;
  int resultat;

  while(*(p+i)!='\0') {
    switch(*(p+i)) {
      case '%': {

        i++;

        if(*(p+i)=='c') {
          fputc(va_arg(ap,int),stdout); }

        if(*(p+i)=='d' || (*(p+i)=='i')) {
          s = va_arg(ap,int);
          convertion(s,10,v);
          for(j=0;j<my_strlen(v);j++)
          fputc(v[j],stdout); }

          if(*(p+i)=='d' + '%') {
            s = va_arg(ap,int);
            convertion(s,10,v);
            for(j=0;j<my_strlen(v);j++)
            fputc(v[j +'%'],stdout);}

        if(*(p+i)=='s') {
          strcpy(v,va_arg(ap,char *));
          for(j=0;j<strlen(v);j++)
          fputc(v[j],stdout); }

        if(*(p+i)=='o') {
          s = va_arg(ap, int);
          convertion(s, 8, v);
          for(j=0; j<my_strlen(v);j++)
          fputc(v[j], stdout); }

          if(*(p+i)=='u') {
            s = va_arg(ap, unsigned int);
            convertion(s, 10, v);
            for(j=0; j<my_strlen(v);j++)
            fputc(v[j], stdout); }

          if(*(p+i)=='x') {
            s = va_arg(ap, unsigned int);
            convertion(s, 16, v);
            for(j=0; j<my_strlen(v);j++)
            fputc(tolower(v[j]), stdout);
          }

        if(*(p+i)=='X') {
          s = va_arg(ap, unsigned int);
          convertion(s, 16, v);
          for(j=0; j<my_strlen(v);j++)
          fputc(v[j], stdout);
         }
        }
      break;

      default :fputc(*(p+i),stdout); break; }

    i++; }

  va_end(ap); }
