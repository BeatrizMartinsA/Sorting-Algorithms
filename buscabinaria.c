#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, int tam, int chave){///para um vetor que já está ordenado
    int inicio=0,meio,fim=tam-1;
    while(inicio<=fim){
        meio=(inicio+fim)/2;
        if(chave>v[meio])
            inicio=meio+1;
        else if(chave<v[meio])
            fim=meio-1;
        else
            return meio;
    }
    return 0;
}


int main(){
    int n,i,valor,pos;
    int *vet;
    scanf("%d",&n);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&vet[i]);
    scanf("%d",&valor);
    pos=busca_binaria(vet,n,valor);
    printf("%d",pos);
return 0;
}
