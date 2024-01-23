#include "NumClass.h"

int factorial(int);

int isPrime(int num){
    if (num <= 1) {
        return 0; 
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  
        }
    }

    return 1;
}

int isStrong(int num){
    int x, remainder, result = 0;

    x = num;

    while (x != 0) {
        remainder = x % 10;
        result += factorial(remainder);
        x /= 10;
    }

    return (result == num);
}

int factorial(int num){
    if (num == 0) {
        return 1;
    } else {
        
        return num * factorial(num - 1);
    }
}