/*
 * Change.cpp
 */

#include "Change.h"
#include <iostream>
#include <vector>

using namespace std;

string calcChange(int m, int numCoins, int *coinValues)
{
    string result = "";

    if (numCoins == 0) return "";
    if (m == 0) return "";
    if (coinValues[0] > m) return "-";

    int minCoins[m + 1][2];
    for (int i = 0; i < m + 1; i++){
        minCoins[i][0] = 0;
        minCoins[i][1] = 0;
    }

    for (int i = 0; i < numCoins; i++) {
        for (int k = coinValues[i]; k <= m; k++) {
            if ((minCoins[k][0] != 0 and (minCoins[k][0] > (minCoins[k - coinValues[i]][0] + 1))) or minCoins[k][0] == 0) {
                minCoins[k][0] = minCoins[k - coinValues[i]][0] + 1;
                minCoins[k][1] = coinValues[i];
            }
        }
    }
    while (m > 0){
        result += to_string(minCoins[m][1]) + ";";
        m -= minCoins[m][1];
    }
    return result;
}


/**
a)
 1) Calcular a melhor possibilidade para o menor caso
 2) Calcular a melhor possibilidade para cada um dos casos seguintes até ao caso final utilizando os resultados anteriores

b)
 minCoins) Se i = 0 return 0; Se k < coinValues[i] return 0; Se coinValues[i] <= k && result[k - coinValues[i]] + coinValues[i] <= k
**/