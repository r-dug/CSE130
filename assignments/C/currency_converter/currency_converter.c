/*
program description:
This C program is designed to show a user how their currency will convert into others.
A user is solicited to input an amount into the terminal.
This input amount is then converted into various currencies and
the conversions are displayed to the user.

author information: Richard Douglas

lab section: User input

date: Jan 15, 2024

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*
example output:
        USD         Eur         GBP         INR         AUD         CAD
    ________________________________________________________________________
USD |    1.00   |    X.XX   |    X.XX   |   X.XX    |   X.XX    |   X.XX   |
    ------------------------------------------------------------------------
Eur |    X.XX   |    1.00   |    X.XX   |   X.XX    |   X.XX    |   X.XX   |
    ------------------------------------------------------------------------
GBP |    X.XX   |    X.XX   |    1.00   |   X.XX    |   X.XX    |   X.XX   |
    ------------------------------------------------------------------------
INR |    X.XX   |    X.XX   |    X.XX   |   1.00    |   X.XX    |   X.XX   |
    ------------------------------------------------------------------------
AUD |    X.XX   |    X.XX   |    X.XX   |   X.XX    |   1.11    |   X.XX   |
    ------------------------------------------------------------------------
CAD |    X.XX   |    X.XX   |    X.XX   |   X.XX    |   X.XX    |   1.00   |
    ------------------------------------------------------------------------
*/                                                                                 
int main(){
    // borders
    char hyphens[97];
    char *p2 = hyphens;
    memset(p2, 0x2D, 97);
    hyphens[97] = '\0';

    // WELCOME MESSAGE
    system("clear");
    printf("Hello there! Welcome to the currency converter!\n"
            "Each row represents conversions between currencies.\n"
            "For instance, if you entered '7.50', and want to convert from US Dollars, \n\t" 
            "examine the 'USD' row for conversions from '7.50'.\n"
            "Other values in that row represent the conversion to the currency in which column they correspond.\n");
    float input; 
    
    float usd = 1.00;
    float eur = 0.91;
    float gbp = 0.79;
    float inr = 82.88;
    float aud = 1.50;
    float cad = 1.34;
    


    while (1){ 
        scanf("%f",&input);
        while (getchar() != '\n');
        system("clear");
        printf("\t\tUSD\t\tEUR\t\tGBP\t\tINR\t\tAUD\t\tCAD\n");
        printf("\t%s\n", hyphens);
        printf("USD\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\n", 
            usd/usd*input, eur/usd*input, gbp/usd*input, inr/usd*input, aud/usd*input, cad/usd*input);
        printf("\t%s\n", hyphens);
        printf("EUR\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\n", 
            usd/eur*input, eur/eur*input, gbp/eur*input, inr/eur*input, aud/eur*input, cad/eur*input);
        printf("\t%s\n", hyphens);
        printf("GBP\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\n", 
            usd/gbp*input, eur/gbp*input, gbp/gbp*input, inr/gbp*input, aud/gbp*input, cad/gbp*input);
        printf("\t%s\n", hyphens);
        printf("INR\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\n", 
            usd/inr*input, eur/inr*input, gbp/inr*input, inr/inr*input, aud/inr*input, cad/inr*input);
        printf("\t%s\n", hyphens);
        printf("AUD\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\n", 
            usd/aud*input, eur/aud*input, gbp/aud*input, inr/aud*input, aud/aud*input, cad/aud*input);
        printf("\t%s\n", hyphens);
        printf("CAD\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\t%0.2f\t|\n", 
            usd/cad*input, eur/cad*input, gbp/cad*input, inr/cad*input, aud/cad*input, cad/cad*input);
        printf("\t%s\n", hyphens);
        printf("KEY\n"
                "USD = US Dollars\n"
                "EUR = Euros\n"
                "GBP = British Pounds\n"
                "INR = Indian Rupees\n"
                "AUD = Australian Dollars\n"
                "CAD = Canadian Dollars\n\n");
        printf("REMEMBER:\n"
                "Each row represents conversions between currencies.\n"
                "For instance, if you entered '7.50', and want to convert from US Dollars,\n\t"
                "examine the 'USD' row for conversions from '7.50'.\n"
                "Other values in that row represent the conversion to the currency in which column they correspond.\n\n");
        printf("\nYou may enter another amount to convert at any time.\n");
    }

    return 0;
}
