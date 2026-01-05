#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int id;// id da marca, pra ficar facil de mexer
    char nome[50];// nome da marca
    char pais[30];// nome do pais que a marca foi criada
    char fama[30];//fama entre baixa,media,alta, pra eu poder filtrar nos modos facil,medio e dificil
    int anoCriada;// ano que foi criada a marca
    char dica_especial[300]; // Nova string para a dica
} Marcas;//guardado os times

void cadastrarMarcas();
void listarMarcas();
void editarMarcas();
void excluirMarcas();
void carregarMarcas();
void salvarMarcas();
void pesquisarMarcas();

void jogar();
void jogo();

#endif  