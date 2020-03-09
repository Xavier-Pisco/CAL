/*
 * Partioning.cpp
 */

#include "Partitioning.h"


int s_recursive(int n,int k)
{
   if (k == n or k == 1)
       return 1;

   return s_recursive(n - 1, k - 1) + k*s_recursive(n - 1, k);
}

int s_dynamic(int n,int k)
{
    int values[n][n];

    for (int i = 0; i < n; i++){
        values[i][0] = 1;
    }

    for (int i = 0; i < n; i++){
        if (i < k)
            values[i][i] = 1;

        for (int j = 1; j < k; j++){
            if (j < i)
                values[i][j] = values[i - 1][j - 1] + (j+1)*values[i - 1][j];
        }
    }
    return values[n-1][k-1];
}


int b_recursive(int n)
{
    static int prevn = n;
    static int k = 1;

    if (prevn != n){
        k = 1;
        prevn = n;
    }

    if (k == n)
        return s_recursive(n, k++);

    return s_recursive(n,k++) + b_recursive(n);
}

int b_dynamic(int n)
{
    int result = 0;
	for(int i = 1; i <= n; i++){
	    result += s_dynamic(n,i);
	}
	return result;
}


