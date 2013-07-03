/*
ACM-ICPC South America Contest (Brazil)
Year: 2011
Category: Final Phase
Ad-Hoc
*/

#include<stdio.h>
#include<stdlib.h>
 
typedef struct vaga{
    int tam;
    int ini;
    int fim;
}Vaga;
 
int* desestacionar(int* estacionamento, int C, int placa);
Vaga maiorVaga(int* estacionamento, int tamanho, int comp);
int* estacionar(int* estacionamento, int tamanho, int placa, Vaga vaga);
Vaga inicializar(Vaga vaga); 
 
int main(void){
    int N,C,i,j,comp,faturamento,placa;
    Vaga vaga;
    char e;
     
    while(scanf("%d %d",&C,&N) != EOF){
        i = 0;
        faturamento = 0;
        int* estaciona = (int*)malloc(C*sizeof(int));
        for(i = 0; i < C; i++) {
            estaciona[i] = 0;
        }
        for(i = 0; i < N; i++){
            scanf(" %c %d",&e,&placa);
            if(e == 'C'){
                scanf("%d",&comp);
                vaga = maiorVaga(estaciona,C,comp);
                if(vaga.tam >= comp){
                   faturamento += 10;
                   estaciona = estacionar(estaciona,C,placa,vaga);
                }
            }
            else{
                estaciona = desestacionar(estaciona,C,placa);
            }   
        }
        printf("%d\n",faturamento);
    }
    return 0;
}
Vaga inicializar(Vaga vaga){
    vaga.ini = -1;
    vaga.fim = -1;
    vaga.tam = 0;
    return vaga;
}
Vaga maiorVaga(int* estacionamento,int tamanho, int comp){
    int i;
    Vaga vaga;
    vaga = inicializar(vaga);
     
    for(i = 0; i < tamanho; i++){
        if(estacionamento[i] == 0){
            if(vaga.ini == -1){
                vaga.ini = i;
            }
            vaga.fim = i;
            vaga.tam++;
            if(vaga.tam >= comp){
                return vaga;
            }
        }
        else{
            vaga = inicializar(vaga);
        }
    }
    return vaga;
}
int* estacionar(int* estacionamento, int tamanho, int placa, Vaga vaga){
    int i;
    for(i = vaga.ini; i <= vaga.fim; i++){
            estacionamento[i] = placa;
    }
    return estacionamento;
}
int* desestacionar(int* estacionamento,int C, int placa){
    int i;
    for(i = 0; i < C; i++){
        if(estacionamento[i] == placa){
            estacionamento[i] = 0;
        }
    }
    return estacionamento;
}
