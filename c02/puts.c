#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];

   strcpy(str1, "foo");
   strcpy(str2, "baz");

   puts(str1);
   puts(str2);
   
   return(0);
}
