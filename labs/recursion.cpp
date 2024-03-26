#include <iostream>
using namespace std;

int fact_for(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact_for(n - 1);
    }
}

int fib(int n){
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }

}


int main() {
    cout << "factorial of 4: " << fact_for(4) << endl;
    cout << "10th fibonacci number: " << fib(10) << endl;
    return 0;
}