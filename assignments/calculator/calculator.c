/*
Class: CSE 130 | programming in C and C++
Language: C
Program discription: A simple command line calculator
Author: Richard Douglas
Start date: 01/21/2024
Last edit: 01/21/2024
NOTES: man, I'm not great working in C. Such a python maniac. It'll get better. 
*/

// Standard imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Operation functions. I know there exist standard functions for all of these.
// I mean- heck -  I could really just use operators and if-else conditional logic... 
// but I wanted to get in a little practice with explicit variable typing, and creating functions in C.


// Addition funciton
float addition(float num1, float num2){
    float sum = num1 + num2;
    return sum;
}

// Subtraction function
float subtraction(float num1, float num2){
    float dif = num1 - num2;
    return dif;
}

// Multiplication funciton
float multiplication(float num1, float num2){
    float product = num1 * num2;
    return product;
}

// Dvision function
float division(float num1, float num2){
    float quotient = num1 / num2;
    return quotient;
}

// Modulo funciton
int modulo(int num1, int num2){
    int mod = num1 % num2;
    return mod;
}

// Primarity function. 
// This is a pretty rudimentary, iterative implementation of primt number checking.
// Fine for this application at least. Not like it's cryptography...
bool primarity(int num1){
    // 0 and 1 are not prime numbers
    if (num1 == 0 || num1 == 1)
        return 0;

    for (int i = 2; i <= num1 / 2; ++i) {
        // if n is divisible by i, then n is not prime
        if (num1 % i == 0) {
        return 0;
        }
    }
    return 1;
}

// power function
float power(float  num1, float num2){
    float result = 1;
    for(int i = 0; i < num2; i++){
        result *= num1;
    }
    return result;
}

// main function
int main(){
    char *intro =   "Hello there! Welcome to the terminal calculator!\n"
                    "Usage: you will be prompted for input three times. Type in an appropriate response when prompted and press enter to send the input.\n\t"
                    "1) Menu selection. Enter the number corresponding to the operation from the menu you would like to perform.\n\t\t\tThe menu will be presented on the following page\n\t"
                    "2) Enter the first number in which you would like to perform the selected operation.\n\t"
                    "3) Enter the second number in which you would like to perform the selected operation.\n\n\t"
                    "Note that order DOES matter. For instance- if performing subtraction, you will subtract the second number from the first.\n\n"
                    "Press enter to begin...\n";

    char *menu =    "Calculator Menu:\n\t"
                    "(1) Addition\n\t"
                    "(2) Subtraction\n\t"
                    "(3) Multiplication\n\t"
                    "(4) Division\n\t"
                    "(5) Modulus (integers only)\n\t"
                    "(6) Test if prime (integers only)\n\t"
                    "(7) Square a number\n\t"
                    "(8) Raise first number by the next\n\t"
                    "(9) Exit\n\n";

    system("clear");
    printf("%s", intro);
    while(1){
        while (getchar() != '\n');
        system("clear");
        printf("%s", menu);
        printf("\nPlease make a menu selection: ");
        int selection;
        if (scanf("%d", &selection) == 0){
            system("clear");
            printf("Invalid input for given menu. Please press enter to try again.\n");
            while(getchar() != '\n');
        }
        else{    
            if(selection == 1){
                float num1;
                float num2;
                printf("\nEnter the first number: ");
                if (scanf("%f", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("\nEnter the second number: ");
                if (scanf("%f", &num2) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                float result = addition(num1, num2);
                printf("\n\nResult: \n\t%f + %f = %f", num1, num2, result);
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
                }
            else if(selection == 2){
                float num1;
                float num2;
                printf("\nEnter the first number: ");
                if (scanf("%f", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("\nEnter the second number: ");
                if (scanf("%f", &num2) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                float result = subtraction(num1, num2);
                printf("\n\nResult: %f - %f = %f", num1, num2, result);
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
                }
            else if(selection == 3){
                float num1;
                float num2;
                printf("\nEnter the first number: ");
                if (scanf("%f", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("\nEnter the second number: ");
                if (scanf("%f", &num2) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                float result = multiplication(num1, num2);
                printf("\n\nResult: %f * %f = %f", num1, num2, result);
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
                }
            else if(selection == 4){
                float num1;
                float num2;
                printf("\nEnter the first number: ");
                if (scanf("%f", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("\nEnter the second number: ");
                if (scanf("%f", &num2) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                if (num2 == 0){
                    system("clear");
                    printf("Cannot divide by zero. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                float result = division(num1, num2);
                printf("\n\nResult: %f / %f = %f", num1, num2, result);
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
            }
            else if(selection == 5){
                int num1;
                int num2;
                printf("\nEnter the first number: ");
                if (scanf("%d", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("\nEnter the second number: ");
                if (scanf("%d", &num2) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                int result = modulo(num1, num2);
                printf("\n\nResult: %d mod %d = %d", num1, num2, result);
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
                }
            else if(selection == 6){
                int num1;
                printf("\nEnter the first number: ");
                if (scanf("%d", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                int result = primarity(num1);
                printf("\n\nResult of %d == prime: %s", num1, result ? "True":"False");
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
            }
            else if(selection == 7){
                float num1;
                printf("\nEnter the first number: ");
                if (scanf("%f", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                float result = num1 * num1;
                printf("\n\nResult of %f^2 == %f", num1, result);
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
            }
            else if(selection == 8){
                float num1;
                float num2;
                printf("\nEnter the first number: ");
                if (scanf("%f", &num1) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("\nEnter the second number: ");
                if (scanf("%f", &num2) == 0){
                    system("clear");
                    printf("Invalid input. Let's try this again...\n\tPress enter.\n");
                    while(getchar() != '\n');
                    continue;
                }
                float result = power(num1, num2);
                printf("\n\nResult: %f^%f = %f", num1, num2, result);
                printf("\n\nPress enter to do another calculation");
                while (getchar() != '\n');
            }
            else if(selection == 9){
                system("clear");
                printf("You've chosen to exit.\n I'll miss you :,(\nGoodbye for now...\n");
                exit(0);
            }
            else{
                system("clear");
                printf("Invalid input for given menu. Please press enter to try again.\n");
                while (getchar() != '\n');
            }
        };
        }
    return 0;
}
