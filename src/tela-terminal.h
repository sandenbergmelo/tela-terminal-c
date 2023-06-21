// Cabeçalho da biblioteca tela.c

void inicializarTela();
void janela(int linhaInicial, int colunaInicial, int linhaFinal,
            int colunaFinal, char *titulo, int tipoMoldura);
void label(int linha, int coluna, char *texto);
char *lerString(int linha, int coluna, int tamanho);
int lerInteiro(int linha, int coluna, int tamanho);
float lerDecimal(int linha, int coluna, int tamanho);
void limparTela();
