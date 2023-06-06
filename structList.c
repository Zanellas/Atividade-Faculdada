#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[20];
    float nota;
    int turma;
} Aluno;

struct Nodo
{
    Aluno dado;
    struct Nodo *ant;
    struct Nodo *prox;
};
typedef struct Nodo nodo;

struct Descritor
{
    int n;
    struct Nodo *pri;
    struct Nodo *ult;
};
typedef struct Descritor descritor;

void iniciar(nodo *L, descritor *D)
{
    L->ant = NULL;
    L->prox = NULL;

    D->n = 0;
    D->pri = NULL;
    D->ult = NULL;
}

int estaVazia(descritor *D)
{
    if (D->n == 0)
        return 1;
    else
        return 0;
}

Aluno primeiroElemento(descritor *D)
{
    nodo *no = D->pri;
    return no->dado;
}

Aluno ultimoElemento(descritor *D)
{
    nodo *no = D->ult;
    return no->dado;
}

void inserirInicio(nodo *L, descritor *D, Aluno *dado)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));

    strcpy(novo->dado.nome, dado->nome);
    novo->dado.turma = dado->turma;
    novo->dado.nota = dado->nota;

    if (estaVazia(D))
    {
        L->prox = novo;
        novo->prox = NULL;
        D->ult = novo;
    }
    else
    {
        nodo *primeiro = L->prox;
        L->prox = novo;
        novo->prox = primeiro;
        primeiro->ant = novo;
    }

    D->n++;
    D->pri = novo;
    novo->ant = NULL;
}

void inserirFinal(nodo *L, descritor *D, Aluno *dado)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));

    strcpy(novo->dado.nome, dado->nome);
    novo->dado.turma = dado->turma;
    novo->dado.nota = dado->nota;

    if (estaVazia(D))
    {
        L->prox = novo;
        novo->ant = NULL;
        D->pri = novo;
    }
    else
    {
        nodo *ultimo = D->ult;
        novo->ant = ultimo;
        ultimo->prox = novo;
    }

    novo->prox = NULL;
    D->ult = novo;
    D->n++;
}

void inserirMeio(nodo *L, descritor *D, Aluno *dado, int posicao)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));

    strcpy(novo->dado.nome, dado->nome);
    novo->dado.turma = dado->turma;
    novo->dado.nota = dado->nota;

    nodo *atual = D->pri;
    int contador = 1;
    while (contador < posicao)
    {
        atual = atual->prox;
        contador++;
    }

    novo->ant = atual->ant;
    novo->prox = atual;
    atual->ant->prox = novo;
    atual->ant = novo;
    D->n++;
}

void excluirInicio(nodo *L, descritor *D)
{
    nodo *primeiro = L->prox;
    nodo *segundo = primeiro->prox;
    L->prox = segundo;
    segundo->ant = NULL;
    D->pri = segundo;
    D->n--;
    free(primeiro);
}

void excluirFinal(nodo *L, descritor *D)
{
    nodo *ultimo = D->ult;
    nodo *penultimo = ultimo->ant;
    penultimo->prox = NULL;
    D->ult = penultimo;
    D->n--;
    free(ultimo);
}

void excluirMeio(nodo *L, descritor *D, char *nome)
{
    nodo *p = L->prox;
    while (p != NULL && strcmp(p->dado.nome, nome) != 0)
    {
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("Aluno nao encontrado.\n");
        return;
    }
    p->ant->prox = p->prox;
    if (p->prox != NULL)
    {
        p->prox->ant = p->ant;
    }
    D->n--;
    free(p);
}

void imprimir(nodo *L, descritor *D, char ordem)
{
    if (estaVazia(D))
    {
        printf("Lista vazia!\n\n");
        return;
    }

    if (ordem == 'e')
    {
        // esquerda para direita
        nodo *no = L->prox;
        printf("%-10s %-6s %-5s \n", "Nome", "Nota", "Turma");
        while (no != NULL)
        {
            printf("%-10s %-6.1f %-4d \n", no->dado.nome, no->dado.nota, no->dado.turma);
            no = no->prox;
        }
    }
    else if (ordem == 'd')
    {
        // direita para esquerda
        nodo *no = D->ult;
        printf("%-10s %-6s %-5s \n", "Nome", "Nota", "Turma");
        while (no != NULL)
        {
            printf("%-10s %-6.1f %-4d \n", no->dado.nome, no->dado.nota, no->dado.turma);
            no = no->ant;
        }
    }
}

int main()
{
    Aluno aluno1 = {"Joao", 7.5, 1};
    Aluno aluno2 = {"Maria", 8.0, 2};
    Aluno aluno3 = {"Paula", 9.0, 3};
    Aluno aluno4 = {"Carlos", 9.5, 1};
    nodo *L = (nodo *)malloc(sizeof(nodo));
    descritor *D = (descritor *)malloc(sizeof(descritor));
    iniciar(L, D);
    imprimir(L, D, 'e');
    printf("\n");

    inserirInicio(L, D, &aluno1);
    inserirFinal(L, D, &aluno2);
    inserirFinal(L, D, &aluno3);
    inserirMeio(L, D, &aluno4, 3);

    imprimir(L, D, 'e');
    printf("\n");

    excluirMeio(L, D, "Maria");
    excluirMeio(L, D, "Paula");

    imprimir(L, D, 'e');

    printf("\n");
}
