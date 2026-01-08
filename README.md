# 🚗 Jogo de Adivinhação de Marcas (C)

Este projeto é um jogo de console interativo desenvolvido em **Linguagem C**. O objetivo é adivinhar a marca de carro sorteada pelo sistema com base em dicas progressivas. O projeto demonstra o uso de manipulação de arquivos, structs e lógica de programação estruturada.

---

## ✨ Funcionalidades

* **🕹️ O Jogo:** Sorteio aleatório de marcas com sistema de dicas dinâmico (Ano, País, Fama e Dica Especial).
* **📊 Sistema de Save:** Gravação de vitórias e derrotas em um arquivo binário (`dados.dat`), mantendo seu histórico salvo.
* **📝 CRUD de Marcas:**
    * **Cadastrar:** Adicione novas marcas ao banco de dados.
    * **Listar:** Visualize todas as marcas cadastradas e seus IDs.
    * **Editar/Excluir:** Gerencie os dados existentes de forma prática.
    * **Pesquisar:** Busca inteligente (case-insensitive) por nome ou parte dele.
* **💾 Persistência:** As marcas são salvas em um arquivo de texto (`marcas.txt`) para fácil manutenção e leitura.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C 
* **Bibliotecas:** `stdio.h`, `stdlib.h`, `string.h`, `time.h`, `ctype.h`
* **Armazenamento:** * Arquivos de Texto (`.txt`) para o banco de dados.
    * Arquivos Binários (`.dat`) para o save do jogador.

---

## 🚀 Como Compilar e Executar

Para rodar o projeto localmente, siga os passos abaixo:

### 1. Pré-requisitos
Ter um compilador C instalado (como GCC, MinGW ou Clang).

### 2. Compilação

Abra o terminal na pasta do projeto e digite:
```bash
gcc main.c funcoes.c -o jogo_marcas
```
###3. Execução
Dependendo do seu sistema operacional, use o comando abaixo no terminal
```bash
./jogo_marcas.exe
```
No Linux ou macOS:
```bash
./jogo_marcas
```
---

## 🎮 Regras do Jogo

O jogo testará seu conhecimento automotivo. A cada rodada:

1.  **Sorteio:** O sistema escolhe aleatoriamente uma marca do banco de dados.
2.  **Tentativas:** Você inicia com **10 tentativas**.
3.  **Sistema de Dicas:** As dicas são liberadas automaticamente conforme suas tentativas diminuem:
    * **Início (10 tentativas):** Exibe o *Ano de criação* e o *País de origem*.
    * **8 tentativas restantes:** Revela a *quantidade de letras* do nome da marca.
    * **6 tentativas restantes:** Informa o nível de *Fama* (Baixa/Média/Alta).
    * **4 ou menos tentativas:** Libera a *Dica Especial* (curiosidade sobre a marca).

> **Vitória/Derrota:** Se acertar, soma-se uma vitória ao seu save. Se as tentativas acabarem, conta-se uma derrota e a marca é revelada.

---

## 📂 Estrutura do Projeto

* `main.c`: Arquivo principal contendo o menu e o loop do programa.
* `funcoes.c`: Implementação de toda a lógica do jogo, regras de negócio e manipulação de arquivos.
* `funcoes.h`: Cabeçalho com as definições das `structs` e protótipos das funções.
* `marcas.txt`: Banco de dados legível onde as marcas ficam salvas (Formato: `ID|Nome|País|Ano|Fama|Dica`).
* `dados.dat`: Arquivo binário gerado automaticamente para salvar seu placar (Vitórias/Derrotas).


* **💡 Dica: Antes de jogar pela primeira vez, use a opção 2. Cadastrar Marca no menu para popular o banco de dados!**
* **Nota: Este projeto foi desenvolvido para fins de estudo sobre manipulação de strings, structs e arquivos em C.**
   
