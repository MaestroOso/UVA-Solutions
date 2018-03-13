#include <bits/stdc++.h>
using namespace std;
bool esJolly(vector<bool> seq){
    for(int i = 0; i<seq.size(); i++){
        if(seq[i]==false){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    while(cin>>n){
        vector<int> numeros(n,0);
        for(int i = 0; i<numeros.size(); i++){
            cin >> numeros[i];
        }
        vector<bool> diferencias(n,false);
        diferencias[0] = true;
        for(int i = 0; i<numeros.size()-1; i++){
            diferencias[abs(numeros[i]-numeros[i+1])] = true;
        }
        /**
        for(int i = 0; i<diferencias.size(); i++){
            cout << diferencias[i] << " ";
        }
        cout << endl;
        **/
        if(esJolly(diferencias)==true){
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }

return 0;
}
