#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *v, int tam){
    int item,i,j;
    for(i=1;i<tam;i++){
        item=v[i];
        j=i-1;
        while(j>=0 && item<v[j]){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=item;
    }
}

int main(){
    int n,i;
    int *vet;
    scanf("%d",&n);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);
    insertionsort(vet,n);
    for(i=0;i<n;i++)
        printf("%d ",vet[i]);
return 0;
}
