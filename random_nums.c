#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int main(){
	srand(time(NULL)); // Seed the random number generator
	while(1){
		int random_number = rand() % 10 + 1; // Random number between 1 and 10
		printf("%d",random_number);
	}
	return 0;
}
