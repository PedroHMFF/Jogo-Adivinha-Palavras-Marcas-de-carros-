#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "funcoes.h"


int main(){
    int opc = -1; 

    carregarMarcas();

    
    do { 
        printf("\n===== MENU ===== \n");
        printf("1. Jogar\n");
        printf("2. Cadastrar Marca de Carro\n");
        printf("3. Lista das Marcas de Carro\n");
        printf("4. Editar Marca\n");
        printf("5. Excluir Marca\n");
        printf("6. Pesquisar as Marcas\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção (0 a 6):\n");
        printf("Dica, olhe a lista de marcas antes de jogar!!\n");
        
        if (scanf("%d", &opc) != 1) { //verifica se o usuario digitou um numero ou nao
            printf("Entrada inválida detectada.\n");
            while (getchar() != '\n' && getchar() != EOF); //caso ele digite uma letra, usei o getchar pra limpar o buffer
            opc = -1; // coloquei opc assim pra rodar denovo as opcoes
            continue;
        }
        
        setbuf(stdin, NULL);

        switch (opc){
            case 1 : printf("Chamando jogar()...\n"); jogar(); break;
            case 2 : printf("Chamando cadastrarMarcas()...\n"); cadastrarMarcas(); break;
            case 3 : printf("Chamando listarMarcas()...\n"); listarMarcas(); break;
            case 4 : printf("Chamando editarMarcas()...\n"); editarMarcas(); break;
            case 5 : printf("Chamando excluirMarcas()...\n"); excluirMarcas(); break;
            case 6 : printf("Chamando pesquisarMarcas()...\n"); pesquisarMarcas(); break;
            case 0 : printf("Saindo...\n"); break;
            default: printf("Opção inválida! Digite um número entre 0 e 6.\n");
        }
    } while (opc != 0);


    return 0;
}