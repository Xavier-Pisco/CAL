# 2015-16 Exame

## 1

### a

    utlimaPosicao = -5 // Guarda  kms do último cartaz
                    // começa a -5 para ser possível meter um cartaz na posição 0 kms
    custo = 0
    for (int i = 0; i < pos.size(); i++)
        if (pos[i] - ultimaPosicao >= 5)
            //coloca o cartaz nessa posição
            custo += valor[i]
            ultimaPosicao = pos[i]

Este algoritmo tem uma complexidade temporal O(n), em que n é o número de cartazes no vetor pos[].

Não é um algoritmo ótimo, no caso dos vetores pos = {1, 3, 6} e valor = {1, 5, 1} o custo final vai ser 2 (1º cartaz + 3º cartaz), enquanto que o valor máximo possível de obter na cobrança de cartazes seria 5 (apenas 2º cartaz).

### b

Não sei

## 2

### a

A - C - D - F - G = 8 + 1 + 4 + 3 = 16

### b

    //Cada vértice tem um atributo preco que corresponde ao seu preço por 1l de gasolina

    for each v ∈ V
        custo(v) <- infinito
        paht(v) <- nil
    gasolina = 10
    custo(A) = 10 * preco(A)
    Q = {} //min-priority queue
    insert(Q, A)
    while (Q != {})
        v <- extract_min(Q)
        for each w ∈ adj(v)
            if gasolina < weight(v, w)
                if custo(w) > custo(v) + 10*preco(w)
                    gasolina += 10
                    custo(w) = custo(v) + 10*preco(w)
                    gasolina -= weight(v, w)
                    path(w) = v
                    if w ∉ Q
                        insert(Q, w)
                    else
                        decrease-key(Q, w)
            else
                if custo(w) > custo(v)
                    custo(w) = custo(v)
                    gasolina -= weight(v, w)
                    path(w) = v
                    if w ∉ Q
                        insert(Q, w)
                    else
                        decrease-key(Q, w)

### c

A - C - D - F - G - C - B - D - B - A - E - F - E - D - G

## 3

### a

Usando o algoritmo de Prim, começa-se por adicionar as arestas com menos peso  e depois vai-se adicionando as arestas que ligam a vértices que não estão na árvore, começando pelos que têm menor valor.

Prints por ordem da evolução da árvore

<img src="exame2016prints/1.png" height = 200>
<img src="exame2016prints/2.png" height = 200>
<img src="exame2016prints/3.png" height = 200>
<img src="exame2016prints/4.png" height = 200>
<img src="exame2016prints/5.png" height = 200>
<img src="exame2016prints/6.png" height = 200>

### b

Não sei nenhuma solução possível.

## 4

### a

É impossível pois o fluxo de F para qualquer outro ponto tem de passar pela aresta A-F e A-F tem fluxo máximo de **10000 uv**. Este é também o fluxo máximo da rede.

Gráfico de fluxo:

<img src="exame2016prints/4.a.png" height = 200>


### b

O volume máximo da rede continuaria o mesmo, sendo que passaria a ser dividido entre os dois consumidores.


### c

Os dois possíveis gráficos de fluxo (prioridade para D ou prioridade para C):
<img src="exame2016prints/4.b.png" height = 200>
<img src="exame2016prints/4.c.png" height = 200>

O volume máximo da rede aumentaria para 30000 uv, sendo que o consumidor D poderia receber um fluxo máximo de 30000 uv (20000 de G e 10000 de A) e o consumidor em C poderia receber um fluxo de até 15000 uv (10000 de A e 5000 de D).

## 5

### a

2³ = 8, ou seja, 3 bits codificam 8 caracteres de tamanho fixo.

a, b, c, d, A, B, C, D, E = 9 caracteres, logo não é possível definir os caracteres usando apenas 3 bits.

### b

7 * a + 5 * b + 5 * c + 8 * d + 3 * A + 2 * B + 2 * C + 2 * D + 5 * E.

Começamos pelos que aparecem mais vezes para poupar no número de bits.

d = 1, a = 01, b = 001, c = 0001, E = 00001, A = 000001, B = 0000001, C = 00000001, D = 00000000

No mínimo, são precisos 7 * 2 + 5 * 3 + 5 * 4 + 8 * 1 + 3 * 6 + 2 * 7 + 2 * 8 + 2 * 8 + 5 * 5 = 146 bits.

### c

Utilizando tamanho fixo seriam necessários 4 * 39 = 156 bits, enquanto uqe em código de tamanho variável, seriam necessários apenas 146 bits, mas no caso de mensagens que contenham o mesmo número de caracteres diferentes, isto é, o mesmo número de as, bs, cs, etc. seria melhor utilizar o código de tamanho fixo.

Ao utilizar RLE, seriam necessários menos bits para representar a string, pois existem sequências de vários caracteres repetidos mais de 3 vezes e que seriam representadas por *Xy, onde X é a letra do alfabeto e y o número de vezes que aparece.

## 6

### a

Se o problema for quais são as solicitações a que se consegue responder num determinado intervalo de tempo, pode ser traduzido num problema de decisão assim:

    É possível responder a estas solicitações em t <= k?

### b

Não sei responder a esta