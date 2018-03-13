#include <bits/stdc++.h>
using namespace std;
int main(){
    double num;
    while(cin>>num && num){
        double partes = 2;
        double suma = 0;
        while(true){
            if(suma>=num){
                break;
            }
            suma+=(1/partes);
            partes++;
        }
        cout << partes-2 << " card(s)\n";
    }
return 0;
}
