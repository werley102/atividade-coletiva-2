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
