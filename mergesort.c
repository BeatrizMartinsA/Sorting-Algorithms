#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int c, int m, int f){
    int *vet,tam,i,j,dir,esq,fim1=0,fim2=0;
    tam=f-c+1;
    vet=(int*)malloc(tam*sizeof(int));
    dir=c;
    esq=m+1;
    for(i=0;i<tam;i++){
        if(fim1==0&&fim2==0){
            if(v[dir]<v[esq]){
                vet[i]=v[dir];
                dir++;
            }
            else{
                vet[i]=v[esq];
                esq++;
            }
            if(dir>m)
                fim1=1;
            if(esq>f)
                fim2=1;
        }
        else if(fim1==0){
            vet[i]=v[dir];
            dir++;
        }
        else{
            vet[i]=v[esq];
            esq++;
        }
    }
    j=c;
    for(i=0;i<tam;i++){
        v[j]=vet[i];
        j++;
    }
}

int pontuacao(int *v,int gols,int partidas){
    int pontos=0,i,dif;
    for(i=0;i<partidas;i++){
        dif=0;
        if(v[i]<0)
            pontos=pontos+3;
        else if(v[i]==0){
            pontos++;
            if(gols>0){
                pontos=pontos+2;
                gols--;
            }
        }
        else{
            dif=v[i];
            if(dif==gols&&gols>0){
                pontos=pontos+1;
                gols=gols-dif;
            }
            else if(dif<gols&&gols>0){
                pontos=pontos+3;
                gols=gols-(dif+1);
            }
        }
    }

return pontos;
}

void merge(int *v,int c,int f){
    int m;
    if(c<f){
        m=(c+f)/2;
        merge(v,c,m);
        merge(v,m+1,f);
        intercala(v,c,m,f);
    }
}

int main(){
    int n,g,i,c,f,s,r,saldo,pontos=0;
    int *vet;
    scanf("%d %d",&n,&g);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d %d",&s,&r);
        saldo=r-s;
        vet[i]=saldo;
    }
    c=0;
    f=n-1;
    merge(vet,c,f);
    pontos=pontuacao(vet,g,n);
    printf("%d",pontos);

    return 0;
}
