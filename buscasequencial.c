#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int *v, int tam, int chave){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==chave)
            return i;
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
    pos=busca_sequencial(vet,n,valor);
    printf("%d",pos);
return 0;
}
