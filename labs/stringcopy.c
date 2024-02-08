#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// this is weird... if the result is negative (i.e. b is bigger than a ) the return is a, b
// if the result is positive (i.e. a is bigger than b) the return is b, a
// how might you reverse the order of sorting?
int cmpfunc(const void *a, const void *b){

    const char *char_a = (const char *)a;
    const char *char_b = (const char *)b;
    return *char_a - *char_b;

}

int main() {
    char str0[8] = "string0"; // create a string
    char str1[8] = "string1"; // create a string
    char str2[8]; // initialize another string variable
    char str3[8] = "String0"; // create a string
    strcpy(str2, str1); // Copies src into dest
    int len = strlen(str1);
    printf("str0 = %s\n",str0);
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    printf("str1 = %s\n\n",str3);
    printf("str2 len = %d\n\n",len);
    printf("strcmp(%s,%s) = %2d\n","str1","str2",strcmp(str1,str2));
    printf("strcmp(%s,%s) = %2d\n","str0","str2",strcmp(str0,str2));
    printf("strcmp(%s,%s) = %2d\n","str2","str0",strcmp(str2,str0));
    printf("strcmp(%s,%s) = %2d\n","str0","str3",strcmp(str0,str3));
    printf("strcmp(%s,%s) = %2d\n\n","str3","str0",strcmp(str3,str0));
    printf("cool! what else can we do?\n\n");

    // try implementing some of the functions mentioned in <stdlib.h>. For example:
    // atof function for double
    printf("woring with atof() ...\n");
    double dub = atof("88.0");
    printf("The string \"88.0\" converted to a double is %f\n\n", dub);
    printf("But what if we try something that isn't a float...\n");
    double cars = atof("cars");
    printf("The string \"cars\" converted to a double is %f\n\n", cars);
    printf("But what if both numbers and non numbers are present...\n");
    double boats = atof("2boats");
    printf("The string \"2boats\" converted to a double is %f\n", boats);

    // atoi function for int

    // atol function for long int

    // strtod function for double

    // strtol function for long

    // strtoul function for unsigned long (not negative or positive)

    // qsort sorts an array   void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
    char random_string [] = "breads and bananas";
    int rs_len = strlen(random_string);
    printf("random string before sorting: %s\n", random_string);
    qsort(random_string, rs_len, sizeof(char), cmpfunc );
    printf("random string after sorting: %s\n", random_string);

    // try implementing some of the functions mentioned in <stdlib.h>
    // getchar inputs next char from standard input and returns it as integer

    // putchar prints char equiv of integer

    // puts automatic newline

    // sprintf to store char type variables

    // sscanf to store input

    // gets is deprecated because it is vulnerable to buffer overflow. use fgets instead.


    // try implementing some of the functions mentioned in <ctype.h>
    // isalnum check char is alphanumeric

    // isalpha check cah is alphabetic

    // iscntrl check char is control char

    // isdigit check char is decimal digit

    // isgraph check char has graphical representation 

    // islower check char is lowercase

    // isprint check char is printable
    // what ISN't printable??

    // ispunct check char is a punctuation char

    // isspace check is a space

    // isupper check char is uppercase

    // isxdigit check char is hexadecimal

}