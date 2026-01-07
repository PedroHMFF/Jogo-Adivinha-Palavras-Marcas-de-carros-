#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int id;// id da marca, pra ficar facil de mexer
    char nome[50];// nome da marca
    char pais[30];// nome do pais que a marca foi criada
    char fama[30];
    int anoCriada;// ano que foi criada a marca
    char dica_especial[300]; // Nova string para a dica
} Marcas;//guardado os times

typedef struct{
    int derrotas;
    int vitorias;
}Save_dat;

void cadastrarMarcas();
void listarMarcas();
void editarMarcas();
void excluirMarcas();
void carregarMarcas();
void salvarMarcas();
void pesquisarMarcas();
void verificarSave(Save_dat *ponteiro_save);
void criarSaveBinario();
void salvarDados(Save_dat *s);

void jogar(Save_dat *save_do_jogo);
void jogo(Save_dat *save_do_jogo);

#endif  