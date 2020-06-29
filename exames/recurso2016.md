# 2015-16 recurso

## 1

### a

    //inicial e final são inteiros que representam os dias
    //no caso do final ser o número seguinte a inicial só temos o dia de compra e o de venda
    função (inicial, final):
        lucro = 1000*preco[final] - 1000*preco[inicial]
        if (final = inicial + 1)
            return lucro
        return max(lucro, funcao(inicial + 1, final), função(inicial, final - 1))

Esta resolução tem como base calcular o lucro usando apenas 2 dias, no caso de termos mais de 2 dias, dividimos em 3 casos, comprar no primeiro dia e vender no último ou não comprar no primeiro dia e não vender no último dia.

Esta função vai ser chamada n * n vezes (todos os dias iniciais possíveis * todos os dias desde o novo inicial até ao final, sendo que não podem ser o mesmo) logo tem uma complexidade temporal O(n*log(n)).

### b

**Eu acho que esta resolução é brute-force e não programação dinâmica mas não sei fazer melhor**

    //Lucro[i][j] é o lucro comprando no dia i e vendendo no dia j
    lucro = 0
    for (int i = 0, i < n - 1; i++){
        for (int j = i + 1; j < n; j++)
            lucro = max(lucro, 1000*preco[j] - 1000*preco[i])
    }

Esta resolução corre todos as possibilidades de dias iniciais e finais e guarda o melhor valor.

complexidade temporal O(n * n), corre uma vez todos os dias como iniciais e corre os dias finais possíveis.

## 2

### a

Seguindo as arestas por ordem horária, começando sempre pelas 12h.

    A -> 