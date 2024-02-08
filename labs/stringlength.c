#include <stdio.h>
#include <string.h>

int main() {
    char str1[8] = "string1"; // create a string
    char str2[8]; // initialize another string variable
    strcpy(str2, str1); // Copies src into dest
    int len = strlen(str1);
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    printf("str2 len = %d\n",len);
}