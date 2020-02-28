#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int fim){
    int aux,i,j,x;
    x=v[fim];
    i=inicio-1;
    for(j=inicio;j<fim;j++){
        if(v[j]<x){
            aux=v[j];
            v[j]=v[i+1];
            v[i+1]=aux;
            i++;
        }
    }
    aux=v[i+1];
    v[i+1]=v[fim];
    v[fim]=aux;
    return i+1;
}

void quicksort(int *v, int inicio, int fim){
   int pivo;
   if(inicio < fim){
        pivo=particiona(v,inicio,fim);
        quicksort(v,inicio,pivo-1);
        quicksort(v,pivo+1,fim);
   }
}

int main(){
    int n,i;
    int *vet;
    scanf("%d",&n);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);
    quicksort(vet,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",vet[i]);
return 0;
}
