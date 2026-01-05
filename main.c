#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    int opc = -1; 

    printf("DEBUG_main_1: Iniciando programa...\n");
    
    // Carrega as marcas
    printf("DEBUG_main_2: Chamando carregarMarcas()...\n");
    carregarMarcas();
    printf("DEBUG_main_3: carregarMarcas() concluído.\n");

    printf("DEBUG_main_4: Entrando no loop do menu...\n");
    
    do { 
        printf("\n===== MENU ===== \n");
        printf("DEBUG_main_5: Menu impresso.\n");
        printf("1. Jogar\n");
        printf("2. Cadastrar Marca de Carro\n");
        printf("3. Lista das Marcas de Carro\n");
        printf("4. Editar Marca\n");
        printf("5. Excluir Marca\n");
        printf("6. Pesquisar as Marcas\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção (0 a 6):\n");
        printf("Dica, olhe a lista de marcas antes de jogar!!\n");
        
        printf("DEBUG_main_6: Aguardando entrada (scanf)...\n");
        
        if (scanf("%d", &opc) != 1) { //verifica se o usuario digitou um numero ou nao
            printf("DEBUG_main_7: Entrada inválida detectada.\n");
            while (getchar() != '\n' && getchar() != EOF); //caso ele digite uma letra, usei o getchar pra limpar o buffer
            opc = -1; // coloquei opc assim pra rodar denovo as opcoes
            continue;
        }
        
        printf("DEBUG_main_8: Opção lida: %d\n", opc);
        
        setbuf(stdin, NULL);

        switch (opc){
            case 1 : printf("DEBUG_main_9: Chamando jogar()...\n"); jogar(); break;
            case 2 : printf("DEBUG_main_10: Chamando cadastrarMarcas()...\n"); cadastrarMarcas(); break;
            case 3 : printf("DEBUG_main_11: Chamando listarMarcas()...\n"); listarMarcas(); break;
            case 4 : printf("DEBUG_main_12: Chamando editarMarcas()...\n"); editarMarcas(); break;
            case 5 : printf("DEBUG_main_13: Chamando excluirMarcas()...\n"); excluirMarcas(); break;
            case 6 : printf("DEBUG_main_14: Chamando pesquisarMarcas()...\n"); pesquisarMarcas(); break;
            case 0 : printf("Saindo...\n"); break;
            default: printf("Opção inválida! Digite um número entre 0 e 6.\n");
        }
    } while (opc != 0);

    printf("DEBUG_main_15: Programa encerrando.\n");
    printf("Pressione Enter para sair...");
    while (getchar() != '\n'); // Limpa buffer
    getchar(); // Aguarda Enter
    
    return 0;
}