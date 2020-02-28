#include <stdio.h>
#include <stdlib.h>

void selectionsort(int *v, int tam){
    int menor,i,j,aux;
    for(i=0;i<tam-1;i++){
        menor=i;
        for(j=i+1;j<tam;j++){
            if(v[menor]>v[j])
                menor=j;
        }
        aux=v[i];
        v[i]=v[menor];
        v[menor]=aux;
    }
}

int main(){
    int n,i;
    int *vet;
    scanf("%d",&n);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);
    selectionsort(vet,n);
    for(i=0;i<n;i++)
        printf("%d ",vet[i]);
return 0;
}
