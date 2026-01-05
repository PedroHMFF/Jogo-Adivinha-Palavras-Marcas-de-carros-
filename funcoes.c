#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcoes.h"

#define MAX_TENTATIVAS 10
#define MAX_MARCAS 100
#define ARQUIVO_MARCAS "marcas.txt"

Marcas marcas[MAX_MARCAS];
int total_marcas = 0;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void to_upper_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

void salvarMarcas() {
    FILE *arquivo = fopen(ARQUIVO_MARCAS, "w");
    if (arquivo == NULL) return;

    for (int i = 0; i < total_marcas; i++) {
        fprintf(arquivo, "%d|%s|%s|%d|%s|%s\n",
                marcas[i].id,
                marcas[i].nome,
                marcas[i].pais,
                marcas[i].anoCriada,
                marcas[i].fama,
                marcas[i].dica_especial);
    }
    fclose(arquivo);
}

void carregarMarcas() {
    FILE *arquivo = fopen(ARQUIVO_MARCAS, "r");
    if (arquivo == NULL) {
        arquivo = fopen(ARQUIVO_MARCAS, "w");
        if (arquivo != NULL) fclose(arquivo);
        total_marcas = 0;
        return;
    }

    total_marcas = 0;
    while (total_marcas < MAX_MARCAS && 
           fscanf(arquivo, " %d|%49[^|]|%29[^|]|%d|%14[^|]|%99[^\n]",
                  &marcas[total_marcas].id,
                  marcas[total_marcas].nome,
                  marcas[total_marcas].pais,
                  &marcas[total_marcas].anoCriada,
                  marcas[total_marcas].fama,
                  marcas[total_marcas].dica_especial) == 6) {
        total_marcas++;
    }
    fclose(arquivo);
}

void cadastrarMarcas() {
    if (total_marcas >= MAX_MARCAS) {
        printf("Limite de marcas atingido!\n");
        return;
    }

    Marcas novaMarca;
    novaMarca.id = total_marcas + 1;

    printf("Nome da marca: ");
    scanf(" %[^\n]", novaMarca.nome);
    printf("País: ");
    scanf(" %[^\n]", novaMarca.pais);
    printf("Ano: ");
    scanf("%d", &novaMarca.anoCriada);
    printf("Fama (baixa/media/alta): ");
    scanf(" %[^\n]", novaMarca.fama);
    printf("Dica especial: ");
    scanf(" %[^\n]", novaMarca.dica_especial);

    marcas[total_marcas] = novaMarca;
    total_marcas++;
    salvarMarcas();
    printf("Sucesso! ID: %d\n", novaMarca.id);
}

void listarMarcas() {
    printf("\n=== LISTA DE MARCAS ===\n");
    for (int i = 0; i < total_marcas; i++) {
        printf("ID: %d | %s | %s | %d | %s\n",
               marcas[i].id, marcas[i].nome, marcas[i].pais, 
               marcas[i].anoCriada, marcas[i].fama);
    }
}

void editarMarcas() {
    int id, idx = -1;
    printf("ID para editar: ");
    scanf("%d", &id);

    for (int i = 0; i < total_marcas; i++) {
        if (marcas[i].id == id) { idx = i; break; }
    }

    if (idx == -1) {
        printf("Não encontrada.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", marcas[idx].nome);
    printf("Novo país: ");
    scanf(" %[^\n]", marcas[idx].pais);
    printf("Novo ano: ");
    scanf("%d", &marcas[idx].anoCriada);
    printf("Nova fama: ");
    scanf(" %[^\n]", marcas[idx].fama);
    printf("Nova dica: ");
    scanf(" %[^\n]", marcas[idx].dica_especial);

    salvarMarcas();
}

void pesquisarMarcas() {
    char termo[50];
    printf("Termo de pesquisa: ");
    scanf(" %[^\n]", termo);

    for (int i = 0; i < total_marcas; i++) {
        if (strstr(marcas[i].nome, termo) != NULL) {
            printf("ID: %d | %s | %s | %s\n", 
                   marcas[i].id, marcas[i].nome, marcas[i].pais, marcas[i].fama);
        }
    }
}

void excluirMarcas() {
    int id, idx = -1;
    printf("ID para excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < total_marcas; i++) {
        if (marcas[i].id == id) { idx = i; break; }
    }

    if (idx == -1) return;

    for (int i = idx; i < total_marcas - 1; i++) {
        marcas[i] = marcas[i + 1];
    }
    total_marcas--;

    for (int i = 0; i < total_marcas; i++) {
        marcas[i].id = i + 1;
    }

    salvarMarcas();
}

void jogar() {
    int dif = -1;
    do {
        printf("\n1-Facil (Fama Alta)\n2-Medio (Fama Media)\n3-Dificil (Fama Baixa)\n0-Sair\nOpcao: ");
        if (scanf("%d", &dif) != 1) {
            limpar_buffer();
            continue;
        }
        if (dif >= 1 && dif <= 3) jogo(dif);
    } while (dif != 0);
}

void jogo(int dif) {
    srand(time(NULL));
    if (total_marcas == 0) return;

    int validas[MAX_MARCAS];
    int qtd_validas = 0;
    char filtro[15];

    if (dif == 1) strcpy(filtro, "alta");
    else if (dif == 2) strcpy(filtro, "media");
    else strcpy(filtro, "baixa");

    for (int i = 0; i < total_marcas; i++) {
        if (strcasecmp(marcas[i].fama, filtro) == 0) {
            validas[qtd_validas++] = i;
        }
    }

    if (qtd_validas == 0) {
        printf("Nenhuma marca com fama '%s' cadastrada.\n", filtro);
        return;
    }

    int sorteado = validas[rand() % qtd_validas];
    Marcas secreta = marcas[sorteado];
    char secreta_up[50], palpite[50], palpite_up[50];

    strcpy(secreta_up, secreta.nome);
    to_upper_case(secreta_up);

    int tentativas = MAX_TENTATIVAS;
    while (tentativas > 0) {
        printf("\nTentativas: %d\n", tentativas);
        if (tentativas == 10) printf("DICA: Pais %s, Ano %d\n", secreta.pais, secreta.anoCriada);
        if (tentativas <= 5) printf("DICA ESPECIAL: %s\n", secreta.dica_especial);

        printf("Palpite: ");
        scanf(" %[^\n]", palpite);
        strcpy(palpite_up, palpite);
        to_upper_case(palpite_up);

        if (strcmp(palpite_up, secreta_up) == 0) {
            printf("Acertou! %s\n", secreta.nome);
            return;
        }
        tentativas--;
    }
    printf("Fim! Era %s\n", secreta.nome);
}