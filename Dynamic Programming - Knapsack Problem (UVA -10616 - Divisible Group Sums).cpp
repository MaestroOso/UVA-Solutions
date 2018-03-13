#include <bits/stdc++.h>
using namespace std;

int dp[202][12][22];
/** Numero de elementos a tomar **/
int M;
/** Divisor **/
int D;
/** Elementos **/
int N;
/** Queries **/
int Q;
/** Arreglo elemntos**/
int arrElementos[202];

/**
    ele es el elemento en el que voy
    pp es la cantidad de elementos que he agarrado

**/

int dinamica(int ele, int pp, int sum){
    if(pp == M){
        if((sum%D)==0){
            return 1;
        }
        return 0;
    }
    if(ele==N){
        return 0;
    }
    if(dp[ele][pp][sum]!=-1){
        return dp[ele][pp][sum];
    }
    int c=0;
    c+= dinamica(ele+1, pp+1, ((sum+arrElementos[ele])%D + D)%D);
    c+= dinamica(ele+1, pp, sum);
    return dp[ele][pp][sum] = c;
}

int main(){
    int casos = 0;
    while(scanf("%d %d", &N, &Q)!=EOF&&(N || Q)){
        for(int i = 0; i<N; ++i){
            scanf("%d", &arrElementos[i]);
        }
        printf("SET %d:\n", ++casos);
        for(int i = 0; i<Q; ++i){
            memset(dp,-1,sizeof(dp));
            scanf("%d %d", &D, &M);
            printf("QUERY %d: %d\n", i+1, dinamica(0,0,0));
        }
    }
    return 0;
}
