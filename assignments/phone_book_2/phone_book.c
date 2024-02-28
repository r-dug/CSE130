/*
Class: CSE 130 | programming in C and C++
Language: C
Program discription: 
This program should compile into a phonebook executable. 

The educational goals are to help up learn to use structs. 

A user should be able to use a few functions:
1) add an entry
2) delete an entry
3) show the phonebook

Phonebook entries stored in an array of structs.

Phonebook entry struct elements:
- first name
- last name
- phone number

On this assignment... 
Let's not get carried away. 
Let's just stick to the task assigned to us.

Author: Richard Douglas
Start date: 02/18/2024
Last edit: 02/18/2024

*/

// imports
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <time.h>
// custom struct for phonebook entries
struct PhonebookEntry{
    int id;
    char first_name[15];
    char last_name[15];
    char phone_number[11]; 
};
struct PhonebookEntry *phonebook = NULL;
void resizePhonebook(struct PhonebookEntry **phonebook, int *capacity, int newcapacity){
    *capacity = newcapacity;
    *phonebook = (struct PhonebookEntry *)realloc(*phonebook, *capacity * sizeof(struct PhonebookEntry));
    if (phonebook == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void addEntry(struct PhonebookEntry **phonebook, int *size, int *capacity, char first_name[], char last_name[], char phone_number[]){
    if (*size >= *capacity){
        resizePhonebook(phonebook, capacity, *capacity * 2);
    }

    (*phonebook)[*size].id = *size;
    strcpy((*phonebook)[*size].first_name, first_name);
    strcpy((*phonebook)[*size].last_name, last_name);
    strcpy((*phonebook)[*size].phone_number, phone_number);
    ++(*size);
}

void resetEntry(struct PhonebookEntry *entry, int *size){
    memset(entry, 0, sizeof(struct PhonebookEntry));
    --*size;
}
void resetEntryByIndex(struct PhonebookEntry **phonebook, int *index, int *size) {
    if (*index >= 0 && *index < *size) {
        (*phonebook)[*index] = (*phonebook)[*size-1];
        (*phonebook)[*index].id = *index;
        --*size;
    }else{
        printf("\nCannot delete. Index is out of bounds.\n\n");
    }
}
void sortPhonebook(struct PhonebookEntry **phonebook, int *size){
}
void searchPhonebook(struct PhonebookEntry **phonebook, int *size, char search_term[]){
    int i = 0;
    printf("SEARCH RESULTS:\n\n");
    // the list may not be sorted, so we are searching each term... 
    // I guess this would be lower time complexity if we sort,
    // then run binary search... but I probably won't come back to this...
    for(i;i<(*size);i++){
        if (strstr( search_term, (*phonebook)[i].first_name ) != NULL || strstr( search_term, (*phonebook)[i].last_name)  != NULL ){
            printf("Entry %d\n\
            First name: %s\n\
            Last name: %s\n\
            Phone number: %s\n\n",
            (*phonebook)[i].id,
            (*phonebook)[i].first_name,
            (*phonebook)[i].last_name,
            (*phonebook)[i].phone_number);
        } 

    }
}
void randomSelection(struct PhonebookEntry **phonebook, int *size){
    srand(time(NULL));
    int i = rand() % *size;
    system("clear");
    printf("Call THIS random person:\n\
    Entry %d\n\
            First name: %s\n\
            Last name: %s\n\
            Phone number: %s\n\n",
            (*phonebook)[i].id,
            (*phonebook)[i].first_name,
            (*phonebook)[i].last_name,
            (*phonebook)[i].phone_number);
}
void printPhonebook(struct PhonebookEntry **phonebook, int *size){
    if (*size == 0){
        printf("PHONEBOOK EMPTY\n\n");
    }
    int i = 0;
    for(i;i<(*size);i++){
        printf("Entry %d\n\
        First name: %s\n\
        Last name: %s\n\
        Phone number: %s\n\n",
        (*phonebook)[i].id,
        (*phonebook)[i].first_name,
        (*phonebook)[i].last_name,
        (*phonebook)[i].phone_number);
    }
}

int countDigits(char num[11]) {

    int count = 0;
    for (int i = 0; num[i] != '\0'; ++i) {
        if (isdigit(num[i]) == 0) {
            return 0;
        }
    }

    return 1;
}
void sigint_handler(int signal) {
    printf("\n\nKeyboard interrupt received. \nFreeing memory... You fool!\n\n");
    
    if (phonebook != NULL) {
        free(phonebook);
        phonebook = NULL;
    }
    
    exit(signal);
}
int main(){
    signal(SIGINT, sigint_handler);
    system("clear");
    // an integer value marking the current number of entries in the phonebook and index to be assigned a value next
    int size = 0;

    // initial size allocated for phonebook
    int capacity = 10;

    // Menu selection integer for switch case
    int selection;

    // valiables for entry
    char add_first_name[15];
    char add_last_name[15];
    char add_phone_number[11];

    // other variables
    int deletion_idx;
    int result;
    char proceed;
    int count;
    char search_term[15];

    // initialize list of phonebook entryies (i.e. the phonebook)
    struct PhonebookEntry *phonebook = (struct PhonebookEntry *)malloc(capacity * sizeof(struct PhonebookEntry));

    if (phonebook == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    while(1){
        printf("Welcome to your phonebook!\n\
        press enter to proceed...");

        while(getchar() != '\n');

        system("clear");
        printf("Choose a menu option by entering the corresponding integer value\n\
        1) add an entry\n\
        2) delete an entry\n\
        3) show the phonebook\n\
        4) Sort phonebook\n\
        5) Search\n\
        6) Randomly select someone to call\n\
        7) Clear phonebook\n\
        8) EXIT \n\n");
        
        result = scanf("%d", &selection);

        if(result != 1 || selection < 1 || selection > 8){
            printf("\nOH NO!! Something went wrong!!\n\n");
            getchar();
            continue;
        }
        result = 0;
        switch(selection){
            case 1:
                system("clear");
                printf("Ok! You've elected to add a phone book entry. Wonderful!\n");
                printf("\tFirst name: ");
                scanf("%s", add_first_name);

                result = 0;
                printf("\tLast name: ");
                scanf("%s", add_last_name);

                result = 0;
                printf("\t10 digit Phone number: ");
                result = scanf("%s", add_phone_number);
                // check if positive 10 digit integer
                int isDigits = countDigits(add_phone_number);
                if (strlen(add_phone_number) != 10 || isDigits == 0){
                    printf("Invalid phone number. \nSimply enter a 10 digit number with no characters...\n\n");
                    break;
                }
                
                addEntry(&phonebook, &size, &capacity, add_first_name, add_last_name, add_phone_number);
                getchar();
                system("clear");
                break;
            case 2:
                system("clear");
                printPhonebook(&phonebook, &size);
                printf("\n\nSelect an entry to delete by index: ");
                scanf("%d", &deletion_idx);
                resetEntryByIndex(&phonebook, &deletion_idx, &size);
                printf("press ENTER to return to main menu\n");
                getchar();
                while(getchar() != '\n');
                system("clear");
                break;
            case 3:
                getchar();
                system("clear");
                printPhonebook(&phonebook, &size);
                printf("press ENTER to return to main menu\n");
                while(getchar() != '\n');
                system("clear");
                break;
            case 4:
                getchar();
                system("clear");
                break;
            case 5:
                system("clear");
                printf("\nEnter a first or last name to search by: ");
                scanf("%s",search_term);
                printf("\n");
                searchPhonebook(&phonebook, &size, search_term);
                printf("press ENTER to return to main menu\n");
                getchar();
                while(getchar() != '\n');
                system("clear");
                break;
            case 6:
                randomSelection(&phonebook, &size);
                printf("press ENTER to return to main menu\n");
                getchar();
                while(getchar() != '\n');
                system("clear");
                break;

            case 7:
                size = 0;
                system("clear");
                printf("PHONEBOOK EMPTIED\n\n");
                printf("press ENTER to return to main menu\n");
                getchar();
                while(getchar() != '\n');
                system("clear");
                break;
            case 8:
                free(phonebook);
                printf("\n\nYou've chosen to exit the phonebook... You FOOL! Freeing memory...\n\n");
                exit(0);
        }
    }
    // idk... just in case... I feel like this is unnecessary. you can tell me in the comments, but maybe it isn't worth deducting points?
    free(phonebook);
    return 0;
}