#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

lista *criarlista(void){
    return NULL;
}
lista* inserirPalavra(lista *l, char p[20]){
    //COMO A REFERENCIA VEM DE UM VETOR DO TIPO LISTA,
    //O ELEMENTO SEMPRE SERA NULO
    lista* novo = (lista*)malloc(sizeof(lista));
    strcpy(novo->palavra,p);
    novo->proximo = NULL;
    return novo;
}
lista* inserir(lista *l, int linha, int quant){
    lista* novo = (lista*)malloc(sizeof(lista));
    novo->linha = linha;
    novo->quant = quant;
    novo->proximo = NULL;
    //SE O ELEMENTO FOR NULO, ATRIBUI O NOVO ELEMENTO NA PROPRIA REFENCIA
    if(l==NULL){
        l = novo;
    }
    //SE NÃO, PERCORRE ATE O ULTIMO ELEMETO E ATRIBUI A REFERENCIA DO NOVO AO ELEMENTO->PROXIMO
    else{
        lista* aux;
        for(aux=l;aux->proximo!=NULL;aux=aux->proximo){}
        aux->proximo = novo;
    }
    return l;
}
void liberarlista(lista *l){
    lista* p = l;
    while(p!=NULL){
        lista* aux = p->proximo;
        free(p);
        p=aux;
    }
}
int buscarPalavra(lista *l[], char* p, int i){
    //PASSA A REFERENCIA DO VETOR DE PALAVRAS E COMPARA COM AS QUE JA ENTÃO ADICIONADAS
    //SE A PALAVRA NÃO FOI ENCONTRADA RETORNA 1, SE FOI RETORNA 0
    int j;
    for(j=0;j<i;j++){
        if(l[j] == NULL)
            return 1;
        else if(strcmp(p,l[j]->palavra)==0)
            return 0;
    }
    return 1;
}
void verificarPalavra(lista *l, char palavra[20]){
    FILE *f = fopen("palavras.txt","r");
    if(f==NULL){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }
    l->proximo = criarlista();
    char aux[20],ch;
    int contp=0,contl=0;
    while(!feof(f)){
        fscanf(f,"%s",aux);//PEGA UMA STRING ATÉ ENCONTRA UM ESPACO OU \N
        ch = fgetc(f);//PEGA O PROXIMO CARACTER, ESPACO OU \N
        if(!strcmp(palavra,aux)){//SE FOR IGUAL A PALAVRA PASSADA, SOMA 1 NO CONTADOR DE PALAVRAS
            contp++;
        }
        if(ch=='\n'){//FIM DA LINHA
            if(contp!=0){//SE O CONTADOR DE PALAVRA FOR ALTERADO, ADICIONA UM NOVO ELEMENTO NA LISTA E ZERA O CONTADOR DE PALAVRAS
                l->proximo = inserir(l->proximo,contl,contp);
                contp=0;
            }
        contl++;//SOMA 1 NO CONTADOR DE LINHAS
        }
    }
    fclose(f);
}
int listavazia(lista *l){
    if(l == NULL)
        return 1;
    else
        return 0;
}
void mostrarlista(lista *l){
    lista* aux;
    for(aux=l;aux!=NULL;aux=aux->proximo)
        printf("(%d,%d) ",aux->linha,aux->quant);
    printf("\n");
}
