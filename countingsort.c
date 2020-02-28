#include <stdio.h>
#include <stdlib.h>

void countingsort(int *v, int tam, int k){
    int *b,*c,i;
    b=(int*)malloc(tam*sizeof(int));
    c=(int*)malloc((k+1)*sizeof(int));
    for(i=0;i<=k;i++)
        c[i]=0;
    for(i=0;i<tam;i++)
        c[v[i]]++;
    for(i=1;i<=k;i++)
        c[i]=c[i]+c[i-1];
    for(i=tam-1;i>=0;i--){
        b[c[v[i]]-1]=v[i];
        c[v[i]]--;
    }
    for(i=0;i<tam;i++)
        v[i]=b[i];
}


int main(){
    int n,i,maior;
    int *vet;
    scanf("%d",&n);
    vet=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&vet[i]);
        if(i==0)
            maior=vet[i];
        if(i>0){
            if(vet[i]>maior)
                maior=vet[i];
        }
    }
    countingsort(vet,n,maior);
    for(i=0;i<n;i++)
        printf("%d ",vet[i]);
return 0;
}
