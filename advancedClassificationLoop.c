#include "NumClass.h"
#include "NumClass.h"


int power(int, int);

int isArmstrong(int num) {
    int x, remainder, numOfDigits = 0, result = 0;

    x = num;

    while (x != 0) {
        x /= 10;
        ++numOfDigits;
    }

    x = num;

    while (x != 0) {
        remainder = x % 10;
        result += power(remainder, numOfDigits);
        x /= 10;
    }

    return (result == num);
}


int isPalindrome(int num){
    if (num <10 && num >= 0)
    {
        return 1;
    }
    
    int original = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return (original == reversedNum);
}

int power(int base, int exponent) {
    int result = 1;
    
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}
