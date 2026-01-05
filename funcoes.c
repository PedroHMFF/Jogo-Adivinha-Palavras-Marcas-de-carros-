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
    char termo_upper[50];
    char nome_temp[100]; //variável para não estragar o nome original
    int encontrou = 0;   //para saber se achou algo

    printf("\n=== PESQUISAR MARCA ===\n");
    printf("Digite o nome (ou parte dele): ");
    scanf("%[^\n]", termo);
    limpar_buffer();

    //transforma o que o usuário digitou em MAIÚSCULAS
    strcpy(termo_upper, termo);
    to_upper_case(termo_upper);

    printf("\n--- Resultados ---\n");

    for (int i = 0; i < total_marcas; i++) {
        //aqui copia o nome da marca atual para uma variável temporária
        strcpy(nome_temp, marcas[i].nome);
        
        //transforma essa cópia em MAIÚSCULAS
        to_upper_case(nome_temp);

        //compara tudo em maiúsculo 
        if (strstr(nome_temp, termo_upper) != NULL) {
            printf("ID: %d | %s | %s | Fama: %s\n", 
                   marcas[i].id, 
                   marcas[i].nome, 
                   marcas[i].pais, 
                   marcas[i].fama);
            encontrou = 1; //avisa que achou pelo menos um
        }
    }

    //se rodou a lista toda e não achou nada, ele avisa
    if (encontrou == 0) {
        printf("Nenhuma marca encontrada para '%s'.\n", termo);
    }

    printf("------------------\n");
    printf("Pressione Enter para voltar...");
    limpar_buffer();
    getchar();
}//pesquisar marcas

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
        printf("\n1-Carros\n0-Sair\nOpcao: ");
        if (scanf("%d", &dif) != 1) {
            limpar_buffer();
            continue;
        }
        if (dif >= 1 && dif <= 3) jogo(dif);
    } while (dif != 0);
}

void jogo() {
    // Semente para gerar números aleatórios diferentes a cada execução
    srand(time(NULL)); 

    if (total_marcas == 0) {
        printf("🚨 Erro: Nao ha marcas cadastradas para iniciar o jogo.\n");
        return;
    }
    
    int indice_sorteado = rand() % total_marcas; // Sorteia de 0 até total-1
    Marcas marca_secreto = marcas[indice_sorteado]; 
    
    // Prepara o nome secreto para comparação (MAIÚSCULAS)
    char nome_secreto_upper[50]; 
    strcpy(nome_secreto_upper, marca_secreto.nome);
    to_upper_case(nome_secreto_upper); 
    
    int tentativas_restantes = MAX_TENTATIVAS;
    char palpite[50]; 
    char palpite_upper[50];

    printf("\n--- ADIVINHE A MARCA DE CARRO ---\n");
    printf("A marca secreta foi sorteada! Voce tem *%d tentativas*.\n", MAX_TENTATIVAS);

    while (tentativas_restantes > 0) {
        printf("\nTentativas restantes: %d\n", tentativas_restantes);
        
        // Dicas
        if (tentativas_restantes == MAX_TENTATIVAS) {
            printf("💡 DICA 1: A marca foi criada no ano de %d, no pais %s.\n", marca_secreto.anoCriada, marca_secreto.pais);
        } else if(tentativas_restantes == 8) {
            size_t tamanho_nome = strlen(marca_secreto.nome);
            printf("💡 DICA 2: O nome da marca tem %zu caracteres.\n", tamanho_nome);
        } else if(tentativas_restantes == 6){
            printf("💡 DICA 3: A marca tem uma fama %s no mundo.\n", marca_secreto.fama);
        } else if (tentativas_restantes <= 4) { // Ajustei para mostrar a dica sempre que faltar 4 ou menos
            printf("💡 DICA 4: %s.\n", marca_secreto.dica_especial);
        }

        // Palpite do usuario
        printf("Seu palpite: ");
    
        if (scanf(" %[^\n]", palpite) != 1) { 
            printf("Entrada invalida.\n");
            limpar_buffer(); 
            continue;
        }

        strcpy(palpite_upper, palpite);
        to_upper_case(palpite_upper);

        // Verificando
        if (strcmp(palpite_upper, nome_secreto_upper) == 0) {
            printf("\n🎉🎉 PARABENS! Voce adivinhou a marca: %s! 🎉🎉\n", marca_secreto.nome);
            return;
        } else {
            printf("❌ Que pena, '%s' nao e a marca escolhida.\n", palpite);
            tentativas_restantes--;
        }
    }

    // Fim de jogo
    printf("\n--- 💔 FIM DE JOGO 💔 ---\n");
    printf("A marca secreta era: %s\n", marca_secreto.nome);
}