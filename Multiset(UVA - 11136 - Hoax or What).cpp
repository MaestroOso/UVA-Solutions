#include <bits/stdc++.h>
using namespace std;
int main(){
    int dias, recibosD, valor;
    long long suma = 0;
    while(cin>>dias && dias){
        suma = 0;
        multiset<int> facturas;
        for(int i = 0; i<dias; i++){
            cin >> recibosD;
            for(int j = 0; j<recibosD; j++){
                cin >> valor;
                facturas.insert(valor);
            }
            multiset<int>::iterator it = facturas.begin();
            multiset<int>::iterator it2 = facturas.end();
            it2--;
            int maximo = *it;
            int minimo = *it2;
            suma+=(minimo-maximo);
            facturas.erase(it2);
            facturas.erase(it);
        }
        cout << suma << endl;
    }
return 0;
}
