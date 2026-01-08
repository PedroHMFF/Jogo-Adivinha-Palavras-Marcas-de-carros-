🚗 Jogo de Adivinhação de Marcas (C)
Um jogo interativo de console desenvolvido em Linguagem C onde o usuário deve adivinhar a marca de carro sorteada pelo sistema com base em dicas. O projeto conta com um sistema completo de CRUD (Create, Read, Update, Delete) para gerenciar as marcas e um sistema de persistência de dados (save game) em formato binário.

✨ Funcionalidades
🕹️ Jogo de Adivinhação: Sorteio aleatório de marcas com sistema de dicas progressivas (Ano, País, Fama e Dica Especial).

📊 Sistema de Save: Gravação de vitórias e derrotas em um arquivo binário (dados.dat), garantindo que seu progresso não seja perdido ao fechar o jogo.

📝 Gerenciamento de Marcas:

Cadastrar novas marcas de carros.

Listar todas as marcas cadastradas.

Editar informações de marcas existentes.

Excluir marcas da base de dados.

Pesquisa inteligente (case-insensitive) por nome ou parte dele.

💾 Persistência em Texto: As marcas são armazenadas de forma formatada em um arquivo .txt para fácil leitura.

🛠️ Tecnologias Utilizadas
Linguagem C (Padrão C99/C11).

Bibliotecas Standard: stdio.h, stdlib.h, string.h, time.h, ctype.h.

Manipulação de Arquivos: Leitura/Escrita de arquivos de texto e binários.

🚀 Como Executar
Clone o repositório:

Bash

git clone https://github.com/seu-usuario/nome-do-repositorio.git
Compile o projeto: Certifique-se de ter um compilador (como o GCC) instalado. No terminal, execute:

Bash

gcc main.c funcoes.c -o jogo_marcas
Inicie o jogo:

Bash

./jogo_marcas
📂 Estrutura de Arquivos
main.c: Ponto de entrada do programa e controle do menu principal.

funcoes.c: Implementação de toda a lógica do jogo e gerenciamento de dados.

funcoes.h: Definição das estruturas (structs) e protótipos das funções.

marcas.txt: Banco de dados das marcas cadastradas.

dados.dat: Arquivo binário que armazena o histórico de pontuação do jogador.

🎮 Como Jogar
Ao iniciar, o jogo verificará se você possui um arquivo de progresso.

Dica: Antes de jogar pela primeira vez, utilize a opção de Cadastrar Marca ou verifique se o arquivo marcas.txt contém dados.

No menu de jogo, você receberá dicas conforme o número de tentativas restantes diminui.

Tente adivinhar o nome exato da marca para vencer!

Nota: Este projeto foi desenvolvido para fins de estudo sobre manipulação de strings, structs e arquivos em C.
