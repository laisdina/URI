/*
ACM-ICPC South America Contest 2005 (Brazil)
Year: 2005
Category: Final Phase
Ad-Hoc
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>

int main(void){
	int a,j,NA,NJ,cont,cont1;
	
	scanf("%d %d",&NA,&NJ);
	while((NA != 0) || (NJ != 0)){
		a = 0;
		j = 0;
		cont = 0;
		cont1 = 0;
		int A[NJ][NA];
		
		for(j = 0; j < NJ; j++){
			for(a = 0; a < NA; a++){
			     	scanf("%d",&A[j][a]);
			}
		}
		
		for(a = 0; a < NA; a++){
			cont = 0;
			for(j = 0; j < NJ; j++){ 
				if(A[j][a] == 1){
				    cont++;
			    }
			}
			if(cont == (NJ)){
				cont1++;
			}
		}
		if(cont1 > 0){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
		scanf("%d %d",&NA,&NJ);
	}
	return 0;
}
