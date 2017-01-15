struct Lista{
    char palavra[20];
    int linha;
    int quant;
    struct Lista* proximo;
};
typedef struct Lista lista;

lista *criarlista(void);
lista* inserirPalavra(lista *l, char p[20]); //INSERIR UMA NOVA PALAVRA NO VETOR DICIONARIO
lista* inserir(lista *l, int linha, int quant); //INSERIR UM NOVO ELEMENTO NA LISTA DE UMA PALAVRA
void liberarlista(lista *l);
int buscarPalavra(lista *l[], char* p, int i); //VERIFICAR SER A PALAVRA JA FOI ADICIONADA NO VETOR DICIONARIO
void verificarPalavra(lista *l, char palavra[20]); //VERIFICA AS LINHAS QUE A PALAVRA ESTA E A QUANTIDADE
int listavazia(lista *l);
void mostrarlista(lista *l);
