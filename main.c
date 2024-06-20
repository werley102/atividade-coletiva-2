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

return discoOrigem != -1 && (discoDestino == -1 || discoOrigem < discoDestino);
}

void realizarMovimento(Pilha hastes[3], int origem, int destino) {
    int discoMover = desempilhar(&hastes[origem]);
    if (discoMover != -1) {
        empilhar(&hastes[destino], discoMover);
    }
}
char passosSolucao[1000][100];
int proximoPasso = 0;
void adicionarPasso(char passo[]) {
    static int indice = 0;
    strcpy(passosSolucao[indice], passo);
    indice++;
}

void resolverTorreHanoi(int numDiscos, int origem, int destino, int auxiliar) {
    if (numDiscos == 1) {
        char passo[100];
        sprintf(passo, "Mova o disco 1 da torre %c para a torre %c", origem + 'A', destino + 'A');
        adicionarPasso(passo);
        return;
    }

    resolverTorreHanoi(numDiscos - 1, origem, auxiliar, destino);
    char passo[100];
    sprintf(passo, "Mova o disco %d da torre %c para a torre %c", numDiscos, origem + 'A', destino + 'A');
    adicionarPasso(passo);
    resolverTorreHanoi(numDiscos - 1, auxiliar, destino, origem);
}

int hasteParaIndice(char haste) {
    haste = toupper(haste);
    if (haste == 'A') return 0;
    if (haste == 'B') return 1;
    if (haste == 'C') return 2;
    return -1; // Caso inválido
}

// Função para verificar se todos os discos estão em uma das hastes de destino
int verificarFimDeJogo(Pilha hastes[3], int numDiscos) {
    // Verifica se todos os discos estão na torre B
    int naTorreB = 1;
    for (int i = 0; i < numDiscos; i++) {
        if (hastes[1].discos[i] != numDiscos - i) {
            naTorreB = 0;
            break;
        }
    }

    // Verifica se todos os discos estão na torre C
    int naTorreC = 1;
    for (int i = 0; i < numDiscos; i++) {
        if (hastes[2].discos[i] != numDiscos - i) {
            naTorreC = 0;
            break;
        }
    }

    return naTorreB || naTorreC;
}

