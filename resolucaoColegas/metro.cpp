#include <stdio.h>
#include <iostream>
#include <cstring>

struct No {
    char valor[10000];
    No *anterior, *proximo;

    No() {
        anterior = NULL;
        proximo = NULL;
    }

    No(char _valor[10000]) {
        strcpy(valor, _valor);
        anterior = NULL;
        proximo = NULL;
    }
};

struct ListaDE {
    No *cabeca, *cauda;
    int n;

    ListaDE() {
        cabeca = NULL;
        cauda = NULL;
        n = 0;
    }

    bool vazia() {
        return cabeca == NULL;
    }

    void inserirFinal(char valor[10000]) {
        No *novo = new No(valor);
        if (vazia()) {
            cabeca = novo;
            cauda = novo;
        }
        else {
            novo->anterior = cauda;
            cauda->proximo = novo;
            cauda = novo;
        }
        n++;
    }

    int tamanho() {
        return n;
    }

    void imprimir() {
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%s \n", aux->valor);
            aux = aux->proximo;
        }
        printf("\n");
    }

    void estacoesMetro(char origem[10000], char destino[10000]) {
        No *aux = cabeca;
        int origemIndex = -1, destinoIndex = -1;
        int i = 0;

        while (aux != NULL) {
            if (strcmp(aux->valor, origem) == 0) {
                origemIndex = i;
            }
            if (strcmp(aux->valor, destino) == 0) {
                destinoIndex = i;
            }
            i++;
            aux = aux->proximo;
        }

        char direcao[1000];
        int qtdEstacoes;
        if (origemIndex < destinoIndex) {
            strcpy(direcao, "direita");
            qtdEstacoes = destinoIndex - origemIndex;
        } else {
            strcpy(direcao, "esquerda");
            qtdEstacoes = origemIndex - destinoIndex;
        }

        printf("%s %d\n", direcao, qtdEstacoes);
    }
};

int main() {
    char origem[10000], destino[10000];
    fgets(origem, 10000, stdin);
    fgets(destino, 10000, stdin);
    origem[strcspn(origem, "\n")] = '\0';
    destino[strcspn(destino, "\n")] = '\0';

    ListaDE l;
    l.inserirFinal("PALMEIRAS BARRA FUNDA");
    l.inserirFinal("MARECHAL DEODORO");
    l.inserirFinal("SANTA CECILIA");
    l.inserirFinal("REPUBLICA");
    l.inserirFinal("ANHANGABAU");
    l.inserirFinal("SE");
    l.inserirFinal("PEDRO II");
    l.inserirFinal("BRAS");
    l.inserirFinal("BRESSER MOOCA");
    l.inserirFinal("BELEM");
    l.inserirFinal("TATUAPE");
    l.inserirFinal("CARRAO");
    l.inserirFinal("PENHA");
    l.inserirFinal("VILA MATILDE");
    l.inserirFinal("GUILHERMINA ESPERANCA");
    l.inserirFinal("PATRIARCA");
    l.inserirFinal("ARTUR ALVIM");
    l.inserirFinal("CORINTHIANS ITAQUERA");


    l.estacoesMetro(origem, destino);
    return 0;
}
