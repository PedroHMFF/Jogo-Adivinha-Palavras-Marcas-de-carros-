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

* **Linguagem:** C (Padrão C99/C11)
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

