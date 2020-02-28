#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINHA 10000

typedef struct TipoNo{
    char aminoacido[3];
    char codon[5];
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

void insere_Chave(TipoHash *hash, char aminoacido[1],char codon[3]){
    int pos,h;
    TipoNo *novo;
    h = horner(codon,hash->m,128);
    pos = h % (hash->m);
    novo=(TipoNo*)malloc(sizeof(TipoNo));
    strncpy(novo->aminoacido,aminoacido,1);
    strncpy(novo->codon,codon,3);
    novo->prox = hash->tabela[pos];
    hash->tabela[pos] = novo;
}

int busca_aminoacido(TipoNo *no, TipoHash *hash){
    int h,pos;
    TipoNo *apontador;
    h=horner(no->codon,hash->m,128);
    pos=h%(hash->m);
    apontador=hash->tabela[pos];
    while(apontador!=NULL){
        if(strcmp(apontador->codon,no->codon)==0){
            strncpy(no->aminoacido,apontador->aminoacido,1);
            return 1;
        }
        apontador=apontador->prox;
    }
    return 0;
}


int main(){
    int m,n,i,aux=0,r,j=0,tam,k;
    TipoHash *dicionario;
    dicionario = (TipoHash*)malloc(sizeof(TipoHash));
    inicializa_Hash(dicionario,64);
    char aminoacido[3],codon[5],entrada[8],linhas[MAXLINHA],str[3];
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        aux=0;
        fgets(entrada,8,stdin);
        char *s;
        s=strtok(entrada,"\t");
        while(s!=NULL){
            if(aux==0){
                strcpy(codon,s);
                codon[3]='\0';
                }
            else if(aux==1){
                strcpy(aminoacido,s);

                aminoacido[1]='\0';
            }
            s=strtok(NULL," ");
            aux++;
        }
        insere_Chave(dicionario,aminoacido,codon);
    }
    scanf("%d\n",&m);
    for(i=0;i<m;i++){
        fgets(linhas,MAXLINHA,stdin);
        linhas[strlen(linhas)-1]='\0';
        tam = strlen(linhas)-1;
        while(j<=tam){
            for(k=0;k<3;k++)
                str[k]=linhas[j+k];
            j+=3;
            TipoNo busca;
            strncpy(busca.codon,str,3);
            r=busca_aminoacido(&busca,dicionario);
            if(r==0)
                printf("*");
            else
                printf("%s",busca.aminoacido);
            }
            printf("\n");
            j=0;
        }
    return 0;
}
