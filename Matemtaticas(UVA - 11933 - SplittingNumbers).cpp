#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numero;
    while(cin>>numero && numero!=0){
        vector<int> posicionesCon1;
        int aux = 1;
        for(int i = 0; i<32-1; i++){
            if(numero&aux){
                posicionesCon1.push_back(i);
            }
            aux<<=1;
        }
        /**for(int i = 0; i<posicionesCon1.size(); i++){
            cout << posicionesCon1[i] << endl;
        }**/
        int nuevo = 0;
        for(int i = 0; i<posicionesCon1.size();i+=2){
            nuevo+=1<<posicionesCon1[i];
        }
        cout << nuevo << " " << numero-nuevo << endl;
    }
    return 0;
}

