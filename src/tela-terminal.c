#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./tela-terminal.h"

void limparTela() {
#ifdef _WIN32
  system("cls");
  return;
#else
  system("clear");
#endif
}

void moverCursor(int linha, int coluna) {
  // Define a posição do cursor no terminal
  printf("\033[%d;%dH", linha, coluna);
}

// Função para definir a tela do terminal
void inicializarTela() {
  limparTela();      // Limpa a tela do terminal
  moverCursor(1, 1); // Move o cursor para a posição (1, 1)
}

void janela(int linhaInicial, int colunaInicial, int linhaFinal,
            int colunaFinal, char *titulo, int tipoMoldura) {

  int largura = colunaFinal - colunaInicial + 1;

  moverCursor(linhaInicial, colunaInicial); // Define a posição do cursor no
                                            // canto superior esquerdo da janela

  // Imprime a moldura superior
  if (tipoMoldura == 1) {
    printf("╔");
    for (int i = 1; i < largura - 1; i++) {
      printf("═");
    }
    printf("╗");
  } else {
    // Outros tipos de moldura (para fazer no futuro)
  }

  // Imprime o título centralizado
  int posicaoTitulo = (largura - strlen(titulo)) / 2;
  moverCursor(linhaInicial, colunaInicial + posicaoTitulo);
  printf("%s", titulo);

  // Imprime a moldura inferior
  moverCursor(linhaFinal, colunaInicial);
  if (tipoMoldura == 1) {
    printf("╚");
    for (int i = 1; i < largura - 1; i++) {
      printf("═");
    }
    printf("╝");
  } else {
    // Outros tipos de moldura (para fazer no futuro)
  }

  // Imprime as laterais da moldura
  for (int i = linhaInicial + 1; i < linhaFinal; i++) {
    moverCursor(i, colunaInicial);
    printf("║");
    moverCursor(i, colunaFinal);
    printf("║");
  }

  // Preenche o interior da janela com espaços em branco
  for (int i = linhaInicial + 1; i < linhaFinal; i++) {
    for (int j = colunaInicial + 1; j < colunaFinal; j++) {
      moverCursor(i, j);
      printf(" ");
    }
  }
}

void label(int linha, int coluna, char *texto) {
  moverCursor(linha, coluna);
  printf("%s", texto);
}

char *lerString(int linha, int coluna, int tamanho) {
  char *string =
      malloc((tamanho + 1) * sizeof(char)); // Aloca memória para a string
  if (string == NULL) {
    printf("Erro de alocação de memória!\n");
    exit(1);
  }

  moverCursor(linha, coluna); // Define a posição do cursor no terminal
  fgets(string, tamanho + 1,
        stdin); // Lê a string do usuário, considerando o tamanho especificado
  string[strcspn(string, "\n")] = '\0'; // Remove o caractere de nova linha

  return string;
}

int lerInteiro(int linha, int coluna, int tamanho) {
  char
      buffer[tamanho + 1]; // Cria um buffer para armazenar a entrada do usuário

  moverCursor(linha, coluna); // Define a posição do cursor no terminal
  fgets(buffer, tamanho + 1,
        stdin); // Lê a entrada do usuário, considerando o tamanho especificado

  return atoi(buffer); // Converte a string para int usando a função atoi
}

float lerDecimal(int linha, int coluna, int tamanho) {
  char
      buffer[tamanho + 1]; // Cria um buffer para armazenar a entrada do usuário

  moverCursor(linha, coluna); // Define a posição do cursor no terminal
  fgets(buffer, tamanho + 1,
        stdin); // Lê a entrada do usuário, considerando o tamanho especificado

  char *posicaoVirgula =
      strchr(buffer, ','); // Encontra a posição da vírgula na string
  if (posicaoVirgula != NULL) {
    *posicaoVirgula = '.'; // Substitui a vírgula por um ponto para garantir a
                           // leitura correta do decimal
  }

  return atof(buffer); // Converte a string para float usando a função atof
}
