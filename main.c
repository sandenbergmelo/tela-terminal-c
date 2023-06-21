#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./src/tela-terminal.h"

#define LINHA_FINAL 24
#define COLUNA_FINAL 80

int main() {

  // Exemplo de uso das funções da biblioteca
  inicializarTela();
  janela(1, 1, LINHA_FINAL, COLUNA_FINAL, "Registro de informações", 1);

  label(3, 3, "Nome: ");
  char *nome = lerString(3, 9, COLUNA_FINAL);

  label(5, 3, "Idade: ");
  int idade = lerInteiro(5, 10, LINHA_FINAL);

  label(7, 3, "Salário: ");
  float salario = lerDecimal(7, 12, LINHA_FINAL);

  // Mostrar os dados digitados
  label(11, 3, "Dados digitados:");

  label(12, 3, "Nome:");
  label(12, 9, nome);

  char idadeString[16];
  sprintf(idadeString, "%d", idade); // Converte o int para string
  label(13, 3, "Idade:");
  label(13, 10, idadeString);

  char salarioString[16];
  sprintf(salarioString, "%.2f", salario); // Converte o float para string
  label(14, 3, "Salário:");
  label(14, 11, salarioString);

  label(16, 3, "Pressione qualquer tecla para sair...\n");
  scanf("%*c");

  return 0;
}
