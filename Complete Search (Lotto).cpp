#include <bits/stdc++.h>
using namespace std;
int main(){
    int tam, caso=0;
    while(cin>>tam && tam!=0){
        if(caso>0){
            cout << endl;
        }
        vector<int> com(tam);
        for(int i = 0; i<tam; i++){
            cin >> com[i];
        }

        for(int i = 0; i<=tam-6; i++){
            for(int j = i+1; j<=tam-5; j++){
                for(int k = j+1; k<=tam-4; k++){
                    for(int l = k+1; l<=tam-3; l++){
                        for(int m = l+1; m<=tam-2; m++){
                            for(int n = m+1; n<=tam-1; n++){
                                printf("%d %d %d %d %d %d\n",com[i],com[j],com[k],com[l],com[m],com[n]);
                            }
                        }
                    }
                }
            }
        }
        caso++;
    }
return 0;
}
