# Quiz de Trigonometria

Quiz de trigonometria para o terminal do Windows, com o Sans do Undertale
como personagem. Foi o trabalho de conclusão da disciplina Fundamentos de
Programação, desenvolvido em cerca de um mês.

## Requisitos do trabalho

O professor definiu duas restrições, e o projeto segue as duas:

- **Arquivo único em C.** Todo o código está em `src/quiz-trigonometria.c`.
- **Bibliotecas da disciplina.** O jogo usa `conio.h`, `windows.h` e `winmm`
  para tela, teclado e áudio. Por isso ele roda apenas no Windows.

## Funcionalidades

- Menu navegado com W e S, com confirmação por Enter.
- 10 perguntas de trigonometria: seno e cosseno de ângulos conhecidos,
  relações em triângulo retângulo e um problema de altura de muro.
- 30 segundos por pergunta.
- Sprite do Sans em pixel art e diálogos durante o quiz.
- Trilha sonora e efeitos de som.

## Como jogar

1. Abra a pasta `jogo/` e rode `quiz-trigonometria.exe` no Windows.
2. Mantenha os arquivos `.mp3` e `console.ico` na mesma pasta do executável.
   O jogo carrega as músicas pelo nome, então sem eles ele roda sem som.
3. No menu, use **W** e **S** para mover a seta e **Enter** para escolher.
4. Responda as perguntas dentro do tempo.

## Estrutura

```
.
├── src/
│   ├── quiz-trigonometria.c   # código-fonte
│   └── Makefile.win           # build do Dev-C++ (MinGW)
└── jogo/
    ├── quiz-trigonometria.exe # executável pronto para rodar
    ├── console.ico            # ícone da janela
    └── *.mp3                  # músicas e efeitos de som
```

## Como compilar

Com o Dev-C++ (MinGW), abra o projeto a partir de `src/` ou use o
`Makefile.win`. O código precisa linkar com `winmm` (`-lwinmm`). O
executável gerado vai para `jogo/`.

O `Makefile.win` tem os caminhos da instalação do Dev-C++ do computador
original (`C:/Program Files (x86)/Dev-Cpp/...`). Ajuste esses caminhos se
usar outra instalação.

## Limitações conhecidas

- Só roda no Windows, pelas bibliotecas exigidas.
- O jogo não tem opção de sair pelo menu nem de jogar de novo sem reiniciar.
- Todo o código fica em um único arquivo, sem separação em módulos, como
  pedido pelo trabalho.
