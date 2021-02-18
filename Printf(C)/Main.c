#include "My_printf.c"

int main(void)
{
  my_printf("1 - une chaine\n");
  my_printf("2 - %s\n", "une autre chaine");
  my_printf("3 - %i\n", 42);
  my_printf("4 - %s %d %s%c", "avec", 4, "parametres", '\n');
  my_printf("5 - %o\n", 42); /* unsigned octal */
  my_printf("6 - %u\n", (unsigned int)42000000); /* unsigned decimal */
  my_printf("7 - %x\n", 42); /* unsigned hexadecimal */
  my_printf("8 - %X\n", 42); /* unsigned hexadecimal */
  my_printf("9 - %d%%\n", 42);
  return (0);
}
