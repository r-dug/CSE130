#include <stdio.h>
    int myPower(int, int);

    int myPower(int m, int n){
        int result = 1;
        for(int i = 0; i<n; i++){
            result = result * m;
        }
        return result;
    }
    float pi = 3.14;
float cylinderVolume(int h, int r){
	float volume;
	volume = pi*r*r*h;
	return volume;
}
int main(){
    int x = 5;
    int y = -*&x;
    printf("%d\n", y);
    printf("%d\n", 17 / 3 + 6 / 5 % 2 + 8); 
    x = 5;
    y = 5;
    printf("%d\n%d\n", x += 1, ++y);
    int num; 
    printf("Enter an integer: ");
    scanf("%d", &num);
    if(num <= 0)
        printf("This is not a valid input");
    switch((num+5)%5+1){ 
    case 7: printf("\nThe world is flat\n");
                    break; 
                    case 2: printf("\nFlorida is hot in the summer\n");
                    break; 
                    case 3: printf("\nFlorida is warm in the winter\n");
                    break; 
                    default: printf("I have never been to Florida\n");
    } /* end switch */
    int  m, n, pow;
    printf("enter two nums: ");
    scanf("%d %d", &m, &n);
    pow = myPower(m, n);
    printf("%d\n", pow);
    float h, r, volume;
	printf("enter height and width for a cylinder, then press enter: ");
	scanf("%f %f", &h, &r);
	volume = cylinderVolume(h, r);
	printf("“%f”\n", volume);


    return 0;
}