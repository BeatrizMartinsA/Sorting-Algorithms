#include <stdio.h>
#include <stdlib.h>
#define MAXCOLUNAS 80

///TAD "GRAFO" COM MATRIZ
typedef struct no{
    int livre;//1->caminho livre; 0->barreira

}TipoNo;

typedef struct grafo{
    int v;//número de linhas
    TipoNo **adj;
}TipoGrafo;

TipoNo** inicializa_matriz(int linhas,int colunas){
    int i,j;
    TipoNo **matriz;
    matriz=(TipoNo**)malloc(linhas*sizeof(TipoNo*));
    for(i=0;i<linhas;i++)
        matriz[i]=(TipoNo*)malloc(colunas*sizeof(TipoNo));
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            matriz[i][j].livre=0;
            }
    }
    return matriz;
}

void inicializa_Grafo(TipoGrafo *G, int linhas){
    G->v=linhas;
    G->adj=inicializa_matriz(linhas,MAXCOLUNAS);
}

///TAD FILA
typedef struct SCelula *TApontador;

typedef struct SCelula{
    int row,col;
    TApontador prox;
}TCelula;

typedef struct fila{
    TApontador inicio,fim;
    int tam;
}TipoFila;

TipoFila* cria_Fila(){
    TipoFila *fi;
    fi=(TipoFila*)malloc(sizeof(TipoFila));
    if(fi!=NULL){
        fi->fim=NULL;
        fi->inicio=NULL;
        fi->tam=0;
    }
    return fi;
}

void libera_Fila(TipoFila* fi){
    TCelula *novo;
    if(fi!=NULL){
        while(fi->inicio!=NULL){
            novo=fi->inicio;
            fi->inicio=fi->inicio->prox;
            free(novo);
        }
        free(fi);
    }
}

void insere_Fila(TipoFila *fi,int row,int col){
    if(fi!=NULL){
        TCelula *novo;
        novo=(TCelula*)malloc(sizeof(TCelula));
        if(novo!=NULL){
            novo->row=row;
            novo->col=col;
            novo->prox=NULL;
            if(fi->fim==NULL)
                fi->inicio=novo;
            else
                fi->fim->prox=novo;
            fi->fim=novo;
            fi->tam++;
        }
    }
}

typedef struct coordenadas{
    int row;
    int col;
}xy;

xy retira_Fila(TipoFila *fi){
    if(fi!=NULL){
        if(fi->inicio!=NULL){
            xy u;
            TCelula *novo;
            novo=fi->inicio;
            u.row=novo->row;
            u.col=novo->col;
            fi->inicio=fi->inicio->prox;
            free(novo);
            if(fi->inicio==NULL)//fila ficou vazia
                fi->fim=NULL;
            fi->tam--;
        return u;
        }
    }
}

///BUSCA
typedef struct{
    xy pai;
    int visitado; //0->não; 1->sim
    int nivel;
}TipoMatriz;

int busca(TipoGrafo *mapa,int row,int col,int l,int px,int py){
    int i,j;
    TipoMatriz matriz[l][MAXCOLUNAS];
    for(i=0;i<l;i++){
        for(j=0;j<MAXCOLUNAS;j++){
            matriz[i][j].nivel=100000;
            matriz[i][j].visitado=0;
            }
    }
    int nivel,cont,x,y;
    TipoFila *fi;
    xy u;
    fi=cria_Fila();
    matriz[row][col].visitado=1;
    insere_Fila(fi,row,col);
    nivel=0;
    matriz[row][col].nivel=nivel;
    while(fi->tam!=0){
        u=retira_Fila(fi);
        cont=0;
        while(cont<4){
            if(cont==0){
                x=u.row-1;
                y=u.col;
            }
            if(cont==1){
                x=u.row;
                y=u.col-1;
            }
            if(cont==2){
                x=u.row;
                y=u.col+1;
            }
            if(cont==3){
                x=u.row+1;
                y=u.col;
            }
            if(matriz[x][y].visitado==0 && mapa->adj[x][y].livre==1){
                matriz[x][y].visitado=1;
                insere_Fila(fi,x,y);
                matriz[x][y].pai.row=u.row;
                matriz[x][y].pai.col=u.col;
                matriz[x][y].nivel=matriz[u.row][u.col].nivel+1;
            }
            cont++;
        }
    }
    libera_Fila(fi);
    return matriz[px][py].nivel;
}

int main(){
    int l,i,j,l_joao,c_joao,l_pedrinho,c_pedrinho,dp,dj,l_tesouro,c_tesouro;
    char c;
    TipoGrafo *mapa;
    mapa=(TipoGrafo*)malloc(sizeof(TipoGrafo));
    scanf("%d\n",&l);
    inicializa_Grafo(mapa,l);
    for(i=0;i<l;i++){
        j=0;
        scanf("%c",&c);
        while(c!='\n' && j!=MAXCOLUNAS){
            if(c=='*'){
                l_joao=i;
                c_joao=j;
            }
            if(c=='+'){
                l_pedrinho=i;
                c_pedrinho=j;
            }
            if(c=='$'){
                l_tesouro=i;
                c_tesouro=j;
            }
            if( (c=='*') || (c=='+') || (c=='$') || (c==' '))
                mapa->adj[i][j].livre=1;
            j++;
            scanf("%c",&c);
        }
    }
    dj=busca(mapa,l_joao,c_joao,l,l_tesouro,c_tesouro);
    dp=busca(mapa,l_pedrinho,c_pedrinho,l,l_tesouro,c_tesouro);

    if(dj<dp)
        printf("%d",1);
    else if(dp<dj)
        printf("%d",2);
    else if(dp==dj){
        if(dp!=100000)
            printf("%d",0);
        else
            printf("%d",-1);
    }
return 0;
}
