/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
    if (n > 1)
	    return n*factorialRecurs(n-1);
    else
        return n;
}

int factorialDinam(int n)
{
    int factorials[n + 1];
    factorials[0] = 1;

    for (int i = 1; i <= n; i++){
        factorials[i] = i*factorials[i - 1];
    }
    return factorials[n];
}

/**
c)
 Both implementations use same time and memeory
 **/