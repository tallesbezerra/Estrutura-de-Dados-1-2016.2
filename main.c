#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"
#include <string.h>
#define T 20
//Universidade Federal de Roraima
//Estrutura de Dados 1 2016.2 - Trabalho Prático 1, Artefato 2
//Aluno: Talles Bezerra de Assunção
//Sistema de catalogação de palavras de um arquivo.txt

int main()
{
    lista *dicionario[T];//VETOR DA ESTRUTURA DICIONARIO
    char aux[T];
    int i=0,busca;
    int j=0;//INDICE DO VETOR
    FILE *f = fopen("palavras.txt","r");//ABRE O ARQUIVO
    if(f==NULL){
        printf("Erro na abertura do arquivo\n");
        return 0;
    }
    while(!feof(f)){//PERCORRE O ARQUIVO ATE O FINAL
        dicionario[j] = criarlista();//CRIA UMA LISTA NO ELEMENTO CORRESPONDENTE AO CONTADOR DO INDECE
        fscanf(f,"%s",aux);//ADICIONA A PRIMEIRA PALAVRA DO ARQUIVO A VARIAVEL AUXILIAR
        strlwr(aux);
        busca = buscarPalavra(dicionario,&aux,j);//VERIFICA DE A PALAVRA EXISTE NO VETOR
        if(busca==1){//SE NÃO EXISTE, ADICIONA A PALAVRA E SOMA 1 AO CONTADOR DE INDICE
            dicionario[j] = inserirPalavra(dicionario[j],aux);
            j++;
        }
    }
    fclose(f);//FECHA O ARQUIVO

    for(i=0;i<j;i++){//PERCORRE CADA ELEMENTO DO VETOR, VERICANDO EM QUE LINHA A PALAVRA ESTA E A QUANTIDADE
        verificarPalavra(dicionario[i],dicionario[i]->palavra);
    }

    printf("\tDICIONARIO DE PALAVRAS\n\n");
    printf("palavra ---> (linha,quantidade)\n\n");
    for(i=0;i<j;i++){//EXIBE NA TELA AS PALAVRAS E A LISTA DE CADA UMA
        printf("%s ---> ",dicionario[i]->palavra);
        mostrarlista(dicionario[i]->proximo);
    }

    for(i=0;i<j;i++){//PERCORRE TODA A ESTRUTURA, LIBERANDO A LISTA DE CADA ELEMENTO
        liberarlista(dicionario[i]);
    }
}
