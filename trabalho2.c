/*
 * ex3.c
 * Last Change:  2014-05-14
 * Maintainer:   Lucas de Sena <contact@seninha.net>
 * License:      This file is placed in public domain.
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Lista {
    int dado1, dado2;
    struct Lista *prox;
} Lista;

Lista * criarElemento (int num1, int num2) {
    Lista * elemento;
    elemento = NULL;
    elemento = malloc (sizeof (Lista));

    elemento -> dado1 = num1;
    elemento -> dado2 = num2;
    elemento -> prox = NULL;

    return elemento;
}

Lista * percorreLista (Lista * elemento) {
    if (elemento == NULL) return NULL;
    while (elemento->prox != NULL)
        elemento=elemento->prox;
    return elemento;
}

Lista * inserirElemento (Lista * lista, int num1, int num2) {
    Lista * aux;
    aux = NULL;
    aux = malloc (sizeof (Lista));
    aux = criarElemento(num1, num2);

    aux->prox = (lista);

    return aux;
}

Lista * adicionaElemento (Lista * lista, int num1, int num2) {
    Lista * aux;
    aux=NULL;
    aux = malloc (sizeof (Lista));
    aux = criarElemento(num1, num2);

    Lista * elemento = NULL;
    elemento = percorreLista(lista);
    if (elemento != NULL) {
        elemento -> prox = aux;
        return lista;
    }
    else {
        return aux;
    }
}

int comparaLista (Lista * lista1, Lista * lista2) {
    int result = 1;
    while (result != 0 && lista1 != NULL && lista2 != NULL) {
        if (lista1->dado1 != lista2->dado1 || lista1->dado2 != lista2->dado2)
            result = 0;
        lista1 = lista1->prox;
        lista2 = lista2->prox;
    }

    return result;
}

Lista * juntaLista(Lista * lista1, Lista *lista2) {
    Lista * lista;
    lista = NULL;
    lista = malloc(sizeof(Lista));

    while (lista1 != NULL && lista2 != NULL) {
        adicionaElemento (lista, lista1->dado1, lista1->dado2);
        adicionaElemento (lista, lista2->dado1, lista2->dado2);
        lista1 = lista1->prox;
        lista2 = lista2->prox;
    }

    return lista;
}

void imprimeLista(Lista * lista){
    while (lista != NULL) {
        printf("    %d - %d\n", lista->dado1, lista->dado2);
        lista = lista->prox;
    }
}


int main (int argc, char **argv) {
    puts("Indique que exercício da lista você quer verificar:\n\
    Exercício 1 [1]\n\
    Exercício 2 [2]\n\
    Exercício 3 [3]\n\
    Exercício 4 [4]\n\
    Exercício 5 [5]\n\
    Exercício 6 [6]\n\
    Exercício 7 [7]\n\
    Exercício 8 [8]\n");
    printf(": ");
    char opcao;
    opcao = getchar();

    switch (opcao) {
        case '1':
            puts("Inserindo elementos no início de uma lista\n");

            Lista * a_lista;
            a_lista = NULL;
            a_lista = inserirElemento(a_lista, 4,6);
            a_lista = inserirElemento(a_lista, 7,3);
            a_lista = inserirElemento(a_lista, 8,0);

            puts("Imprimindo conteúdo da lista:\n");
            imprimeLista(a_lista);
            break;
            
        case '2':
            puts("Adicionando elementos no final de uma lista\n");

            Lista * b_lista;
            b_lista = NULL;
            b_lista = adicionaElemento(b_lista, 4,6);
            b_lista = adicionaElemento(b_lista, 7,3);
            b_lista = adicionaElemento(b_lista, 8,0);

            puts("Imprimindo conteúdo da b_lista:\n");
            imprimeLista(b_lista);
            break;
        
        case '3':
            puts("Comparando listas\n");

            Lista * c_lista1;
            c_lista1 = NULL;
            c_lista1 = criarElemento(1,2);
            inserirElemento(c_lista1, 4,6);
            adicionaElemento(c_lista1, 7,9);

            Lista * c_lista2;
            c_lista2 = NULL;
            c_lista2 = criarElemento(1,3);
            inserirElemento(c_lista2, 4,6);
            adicionaElemento(c_lista2, 7,4);

            puts("Imprime 0 se está diferente, 1 se está igual: ");
            printf("%d\n", comparaLista(c_lista1, c_lista2));
            break;
    }

    return 0;
}

/* vim: set ai fdm=marker fmr={{{,}}} ft=c: */
