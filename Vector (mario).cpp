#include <bits/stdc++.h>
using namespace std;
int main(){
    int casos, num, aux = 0;
    cin >> casos;
    while(casos--){
        aux++;
        cin >> num;
        vector<int> paredes(num,0);
        for(int i = 0; i<num; i++){
            cin >> paredes[i];
        }
        int alto = 0, bajo = 0;
        for(int i = 1; i<num; i++){
            if(paredes[i-1]<paredes[i]){
                alto++;
            } else if(paredes[i-1]>paredes[i]){
                bajo ++;
            }
        }
        printf("Case %d: %d %d\n",aux,alto,bajo);
    }


return 0;
}
