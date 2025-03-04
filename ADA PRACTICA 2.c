#include <stdio.h>
#include <limits.h>


int divide(int dividend, int divisor) {
   
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }


   
    int negative = (dividend < 0) ^ (divisor < 0);


 
    long long absDividend = dividend < 0 ? -(long long)dividend : (long long)dividend;
    long long absDivisor = divisor < 0 ? -(long long)divisor : (long long)divisor;


    int quotient = 0;


    while (absDividend >= absDivisor) {
        long long tempDivisor = absDivisor, count = 1;
        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            count <<= 1;
        }
        absDividend -= tempDivisor;
        quotient += count;
    }


    if (negative) {
        quotient = -quotient;
    }


    if (quotient > INT_MAX) {
        return INT_MAX;
    } else if (quotient < INT_MIN) {
        return INT_MIN;
    } else {
        return quotient;
    }
}


int main() {
    int n,j;




    printf("Introduce el divisor: ");
    scanf("%i",&n);
    printf("Itroduce el dividendo: ");
    scanf("%i",&j);




    printf("%d\n", divide(n, j));
    return 0;
}
