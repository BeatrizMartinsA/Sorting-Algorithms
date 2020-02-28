#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINHA 100

typedef struct TipoNo{
    char original[MAXLINHA];
    char traducao[MAXLINHA];
    struct TipoNo *prox;
}TipoNo;

typedef struct{
    TipoNo **tabela;
    int m;
}TipoHash;

void inicializa_Hash(TipoHash *hash, int m){
    int i;
    hash->tabela =(TipoNo**)malloc(m*sizeof(TipoNo*));
    hash->m = m;
    for(i=0;i<m;i++){
        hash->tabela[i] = NULL;
    }
}

int horner(char *v, int m, int b){
    int h,i;
    for(h = 0, i=0; i<strlen(v); i++)
    h = (h*b + v[i]) % m;
    return h;
}

void insere_Chave(TipoHash *hash, char original[100],char traducao[100]){
    int pos,h;
    TipoNo *novo;
    h = horner(original,hash->m,128);
    pos = h % (hash->m);
    novo=(TipoNo*)malloc(sizeof(TipoNo));
    strncpy(novo->original,original,MAXLINHA);
    strncpy(novo->traducao,traducao,MAXLINHA);
    novo->prox = hash->tabela[pos];
    hash->tabela[pos] = novo;
}

int busca_traducao(TipoNo *palavra, TipoHash *hash){
    int h,pos;
    TipoNo *apontador;
    h=horner(palavra->original,hash->m,128);
    pos=h%(hash->m);
    apontador=hash->tabela[pos];
    while(apontador!=NULL){
        if(strcmp(apontador->original,palavra->original)==0){
            strncpy(palavra->traducao,apontador->traducao,MAXLINHA);
            return 1;
        }
        apontador=apontador->prox;
    }
    return 0;
}


int main(){
    int m,n,i,aux=0,r;
    TipoHash *dicionario;
    dicionario = (TipoHash*)malloc(sizeof(TipoHash));
    inicializa_Hash(dicionario,3359);
    char original[MAXLINHA],traducao[MAXLINHA],linhas[MAXLINHA];
    scanf("%d %d\n",&m,&n);

    for(i=0;i<m;i++){
        fgets(original,MAXLINHA,stdin);
        original[strlen(original)-1]='\0';
        fgets(traducao,MAXLINHA,stdin);
        traducao[strlen(traducao)-1]='\0';
        insere_Chave(dicionario,original,traducao);
    }

    for(i=0;i<n;i++){
        fgets(linhas,MAXLINHA,stdin);
        linhas[strlen(linhas)-1]='\0';
        char *palavra;
        palavra = strtok(linhas," ");
        while(palavra!=NULL){
            TipoNo word;
            strncpy(word.original,palavra,MAXLINHA);
            r=busca_traducao(&word,dicionario);
            if(r==0){
                if(aux==0){
                    printf("%s",word.original);
                    aux=1;
                }
                else
                    printf(" %s",word.original);
            }
            else{
                if(aux==0){
                    printf("%s",word.traducao);
                    aux=1;
                    }
                else
                    printf(" %s",word.traducao);
            }
            palavra=strtok(NULL," ");
        }
        printf("\n");
        aux=0;
    }
return 0;
}
