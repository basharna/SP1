#include <stdio.h>
#include "NumClass.h"

int main(){
    int firstNum, secondNum;

    printf("Enter first number: ");
    if (scanf("%d", &firstNum) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%d", &secondNum) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    printf("The Armstrong numbers are: ");

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isArmstrong(i))
        {
            printf("%d ",i);
        }
        
    }

    printf("\nThe Palindromes are: ");

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPalindrome(i))
        {
            printf("%d ",i);
        }
        
    }

    printf("\nThe Prime numbers are: ");

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isPrime(i))
        {
            printf("%d ",i);
        }
        
    }

    printf("\nThe Strong numbers are: ");

    for (int i = firstNum; i <= secondNum; i++)
    {
        if (isStrong(i))
        {
            printf("%d ",i);
        }
        
    }

    printf("\n");
    
    return 0;
}