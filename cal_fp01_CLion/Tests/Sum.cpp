/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>

string calcSum(int* sequence, int size)
{
    string result;

    int values[size][2];
    int sum;

    for (int m = 1; m <= size; m++){

        values[m - 1][1] = 99999;
        values[m - 1][0] = 0;

        for (int i = 0; i + m <= size; i++){

            sum = 0;

            for (int j = 0; j < m; j++){

                sum += sequence[i+j];

            }

            if (sum < values[m - 1][1]){
                values[m - 1][0] = i;
                values[m - 1][1] = sum;
            }
        }

    }

    for (int i = 0; i < size; i++){
        result += to_string(values[i][1]) + ',' + to_string(values[i][0]) + ';';
    }

	return result;
}

