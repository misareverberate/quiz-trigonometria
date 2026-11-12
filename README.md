# Quiz de Trigonometria

Um quiz de trigonometria para o terminal do Windows, com o Sans do Undertale
fazendo parte da experiência.

Foi feito em cerca de um mês, como trabalho da disciplina de Fundamentos de
Programação, em C. Todo o código está em um único arquivo (`quiz-trigonometria.c`),
e o projeto ficou limitado pelas bibliotecas disponíveis no Dev-C++, por isso
só roda no Windows.

## Funcionalidades

- Menu navegado com W e S, com confirmação por Enter.
- 10 perguntas de trigonometria: seno e cosseno de ângulos conhecidos,
  relações em triângulo retângulo e um problema de altura de muro.
- 30 segundos por pergunta.
- Sprite do Sans em pixel art e diálogos durante o quiz.
- Trilha sonora e efeitos de som.

## Como jogar

1. Baixe o repositório e rode `quiz-trigonometria.exe` no Windows.
2. Os arquivos `.mp3` e `console.ico` precisam ficar na mesma pasta do
   executável.
3. No menu, use **W** e **S** para mover a seta e **Enter** para escolher.
4. Responda as perguntas dentro do tempo.

## Arquivos

| Arquivo | Descrição |
|---|---|
| `quiz-trigonometria.c` | Código-fonte da versão final |
| `quiz-trigonometria.exe` | Executável da versão final (Windows, 64 bits) |
| `Makefile.win` | Makefile gerado pelo Dev-C++ |
| `console.ico` | Ícone da janela do console |
| `*.mp3` | Músicas e efeitos de som do jogo |

## Como compilar

Com o Dev-C++ (MinGW), abra o projeto ou use o `Makefile.win`. O código
precisa linkar com `winmm` (`-lwinmm`).

O `Makefile.win` tem os caminhos da instalação do Dev-C++ do computador
original (`C:/Program Files (x86)/Dev-Cpp/...`). Ajuste esses caminhos se
usar outra instalação.

## Limitações

- Só roda no Windows, porque usa `conio.h`, `windows.h` e a biblioteca
  `winmm` para o áudio.
- Não há menu para sair pelo jogo nem para jogar de novo sem reiniciar.
- Todo o código está em um único arquivo, sem separação em módulos.
