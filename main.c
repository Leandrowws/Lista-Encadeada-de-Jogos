#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Jogo {
    struct Jogo *proximo;
    char nome[25];
    int jogabilidade;
    int historia;
    int arte;
    float nota;
} Jogo;

typedef struct {
    int tam;
    Jogo *inicio;
} Lista;

void novaLista(Lista *lista){
    lista->tam = 0;
    lista->inicio = NULL;
}

void inserirOrdenado(Lista *lista, int jogabilidade, int arte, int historia, char nome[25]) {

    Jogo *aux;
    Jogo *novo = (Jogo*)malloc(sizeof(Jogo));

    if(novo == NULL) {
        printf("Erro ao alocar memoria\n");
        return;
    }

    novo->proximo = NULL;
    strcpy(novo->nome, nome);
    novo->jogabilidade = jogabilidade;
    novo->arte = arte;
    novo->historia = historia;
    novo->nota = ((jogabilidade*5.0)+(historia*3.0)+(arte*2.0))/10.0;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
    } 
    else if(novo->nota > lista->inicio->nota) {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    } 
    else {
        aux = lista->inicio;

        while(aux->proximo && novo->nota < aux->proximo->nota)
            aux = aux->proximo;

        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }

    lista->tam++;
}

void novoJogo(Lista *lista){
    char nome[25];
    int historia, arte, jogabilidade;

    printf("Digite o nome do jogo: ");
    fgets(nome, 25, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a nota para a jogabilidade do jogo: ");
    scanf("%d", &jogabilidade);
    while(jogabilidade < 0 || jogabilidade > 100) {
        printf("Digite novamente (0-100): ");
        scanf("%d", &jogabilidade);
    }
    getchar();

    printf("Digite a nota para a historia do jogo: ");
    scanf("%d", &historia);
    while(historia < 0 || historia > 100) {
        printf("Digite novamente (0-100): ");
        scanf("%d", &historia);
    }
    getchar();

    printf("Digite a nota para a arte do jogo: ");
    scanf("%d", &arte);
    while(arte < 0 || arte > 100) {
        printf("Digite novamente (0-100): ");
        scanf("%d", &arte);
    }
    getchar();
    inserirOrdenado(lista, jogabilidade, arte, historia, nome);
}

void imprimir(Lista lista){
    Jogo *jogo = lista.inicio;
    int i = 1;

    while(jogo) {
        printf("%d - %s (%.2f)\n", i, jogo->nome, jogo->nota);
        jogo = jogo->proximo;
        i++;
    }

    if(lista.tam == 0)
        printf("Lista vazia!\n");
}

void salvarEmArquivo(Lista lista) {

    FILE *arquivo = fopen("MelhoresJogos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Jogo *jogo = lista.inicio;
    int i = 1;

    while(jogo) {
        fprintf(arquivo,"%d - %s - %.2f (%d;%d;%d)\n", i, jogo->nome, jogo->nota, jogo->jogabilidade, jogo->historia, jogo->arte);
        jogo = jogo->proximo;
        i++;
    }

    fclose(arquivo);
}

void lerDoArquivo(Lista *lista) {
    FILE *arquivo = fopen("MelhoresJogos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char nome[25];
    int jogabilidade, historia, arte;
    float nota;
    int indice;

    while (fscanf(arquivo, "%d - %24[^-] - %f (%d;%d;%d)", &indice, nome, &nota, &jogabilidade, &historia, &arte) == 6) {
        inserirOrdenado(lista, jogabilidade, arte, historia, nome);
    }

    fclose(arquivo);
}

int main()
{
    Lista lista;
    novaLista(&lista);
    lerDoArquivo(&lista);
    
    int sel;

    do {
        printf("\n1 - Inserir novo jogo\n2 - Imprimir\n0 - Sair\n");
        scanf("%d", &sel);
        getchar();
        if(sel == 1) {
            novoJogo(&lista);
            salvarEmArquivo(lista);
        } 
        else if(sel == 2)
            imprimir(lista);
    } while(sel != 0);

    return 0;
}