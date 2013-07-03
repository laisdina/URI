/*
ACM-ICPC South America Contest (Brazil)
Year: 2005
Category: Final Phase
Ad-Hoc
*/

#include<stdio.h>
 
int main(void){
    int N,h,i,j,k,min,flag;
     
    while(scanf("%d",&N) != EOF){
        min = 0;
        i = 0;
        j = 0;
        k = 0;
        h = 0;
        flag = 0;
        int largada[N+1];
        int chegada[N+1];
         
        for(i = 1; i < (N+1); i++){
            scanf("%d",&largada[i]);            
        }
        for(i = 1; i < (N+1); i++){
            scanf("%d",&chegada[i]);
        }
     
        for(i = 1; i < (N+1); i++){
            for(j = 1; j < (N+1); j++){
                if(largada[i]  == chegada[j]){
                        int aux[i-1];
                        for(k = 1; k < i; k++){
                            aux[k] = largada[k];    
                        }
                        if(largada[i] == chegada[1]){
                            min += (k-1);
                        }
                        else{
                            for(k = 1; k < i; k++){
                                flag = 0;
                                for(h = 1; h < j; h++){
                                    if(aux[k] == chegada[h]){
                                        flag = 1;
                                    }
                                }
                                if(flag == 0){
                                    min++;
                                }
                            }   
                        }                    
                        j = N+1;
                }
            }
        } 
        printf("%d\n",min);
    }
}
