#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
//#include "main.h"

#define MAX_DISCOS 64

typedef struct {
    int discos[MAX_DISCOS];
    int topo;
} Pilha;

// Função para inicializar uma pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Função para verificar se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == MAX_DISCOS - 1;
}
// Função para empilhar um disco
void empilhar(Pilha *p, int disco) {
    if (!pilhaCheia(p)) {
        p->discos[++(p->topo)] = disco;
    }
}

// Função para desempilhar um disco
int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->discos[(p->topo)--];
    }
    return -1;
}

// Função para obter o disco no topo da pilha sem desempilhar
int topo(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->discos[p->topo];
    }
    return -1;
}


// Função para imprimir as hastes e os discos
void imprimirHastes(Pilha hastes[3], int numDiscos) {
    for (int i = numDiscos - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i > hastes[j].topo) {
                printf("    |    ");
            } else {
                printf("%4d    ", hastes[j].discos[i]);
            }
        }
        printf("\n");
    }
}

int movimentoValido(Pilha hastes[3], int origem, int destino) {
    int discoOrigem = topo(&hastes[origem]);
    int discoDestino = topo(&hastes[destino]);
