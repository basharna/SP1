#include <stdio.h>
#include "NumClass.h"


int power(int base, int exponent) {
    int result = 1;
    
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int findLength(int num){
    int n = 0;
    while (num != 0) {
        num /= 10;
        ++n;
    }
    return n;
}

int isPalindromeRecursive(int num, int length){
    if (length <= 1) {
        return 1;
    }

    int firstDigit = num / power(10, length - 1);
    int lastDigit = num % 10;

    if (firstDigit != lastDigit) {
        return 0;
    }

    num = (num % power(10, length - 1)) / 10;

    return isPalindromeRecursive(num, length - 2);
    
}

int isPalindrome(int num){
    int length = findLength(num);

    return isPalindromeRecursive(num, length);
}

int isArmstrongRecursive(int num, int length) {
    if (num == 0) {
        return 0;
    } else {
        int remainder = num % 10;
        return power(remainder, length) + isArmstrongRecursive(num / 10, length);
    }
}

int isArmstrong(int num) {
    int length = findLength(num);
    return (num == isArmstrongRecursive(num, length));
}


