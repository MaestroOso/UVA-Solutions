#include<bits/stdc++.h>
using namespace std;

int convertir (vector<int> &numvec){
    int num = 0;
    int potencia = 1;
    for(int i = numvec.size()-1; i>=0; i--){
        num = num + (numvec[i]*potencia);
        potencia = potencia *10;
    }
    return num;
}


void suma(vector<int> &numeros){
    vector<int> num1;
    vector<int> num2;
    sort(numeros.begin(),numeros.begin()+numeros.size());
    for(int i = 0; i<numeros.size(); i++){
        if(numeros[i]!=0){
            num1.push_back(numeros[i]);
            numeros.erase(numeros.begin()+i);
            i = numeros.size();
        }
    }

    for(int i = 0; i<numeros.size(); i++){
        if(numeros[i]!=0){
            num2.push_back(numeros[i]);
            numeros.erase(numeros.begin()+i);
            i = numeros.size();
        }
    }

    int i = 0;
    while(!numeros.empty()){
        if(i%2==0){
            num1.push_back(numeros[0]);
            numeros.erase(numeros.begin());
        } else {
            num2.push_back(numeros[0]);
            numeros.erase(numeros.begin());
        }
        i++;
    }
    int sum1 = convertir(num1);
    int sum2 = convertir(num2);
    int total = sum1 + sum2;
    cout << total << endl;
}

int main(){
    int num;
    while(cin >> num && num!=0){
        vector<int> numeros(num,0);
        for(int i = 0; i<num; i++){
            cin >> numeros[i];
        }
        suma(numeros);
    }
    return 0;
}
