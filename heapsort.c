#include <stdio.h>
#include <stdlib.h>

void max_heapify(int *vet, int tam, int pos){
    int esq=0,dir=0,aux=0,maior=pos;
    esq=2*pos+1;
    dir=2*pos+2;
    if(esq<=(tam-1) && vet[esq]>vet[pos])
        maior=esq;
    if(dir<=(tam-1) && vet[dir]>vet[maior])
        maior=dir;
    if(maior!=pos){
        aux=vet[pos];
        vet[pos]=vet[maior];
        vet[maior]=aux;
        max_heapify(vet,tam,maior);
    }
}

void build_max_heap(int *vet, int tam){
    int i;
    for(i=(tam/2)-1;i>=0;i--){
        max_heapify(vet,tam,i);
        }
}

void heapsort(int *vet, int tam){
    int i,aux=0;
    build_max_heap(vet,tam);
    for(i=(tam-1);i>0;i--){
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        max_heapify(vet,i,0);
    }
}

int main(){
    int n,i;
    int *vet;
    scanf("%d",&n);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);
    heapsort(vet,n);
    for(i=0;i<n;i++)
        printf("%d ",vet[i]);
    return 0;
}
