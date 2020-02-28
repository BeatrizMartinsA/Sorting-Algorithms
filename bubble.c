#include <stdio.h>
#include <stdlib.h>

int bubble(int *vetor, int tam){
    int t=0,i,j,aux;
    for(i=0;i<tam;i++){
        for(j=1;j<tam;j++){
            if(vetor[j]<vetor[j-1]){
                aux=vetor[j];
                vetor[j]=vetor[j-1];
                vetor[j-1]=aux;
                t++;
            }
        }
    }

return t;
}

int main(){
    int n,i,trocas=0;
    int *vet;
    scanf("%d",&n);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);
    trocas=bubble(vet,n);
    if(trocas%2==0)
        printf("Carlos");
    else
        printf("Marcelo");

 return 0;
}


