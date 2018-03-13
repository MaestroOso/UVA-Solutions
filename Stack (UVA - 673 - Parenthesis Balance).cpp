#include <bits/stdc++.h>
using namespace std;
string revision(string cadena){
    stack<int> pila;
    for(int i = 0; i<cadena.size(); i++){
        if(cadena[i]=='(' || cadena[i]=='['){
            pila.push(cadena[i]);
        } else {
            if(cadena[i]==')'){
                if(pila.empty()){
                    return "No";
                }
                if(pila.top()=='('){
                    pila.pop();
                } else {
                    return "No";
                }
            } else if(cadena[i]==']'){
                if(pila.empty()){
                    return "No";
                }
                if(pila.top()=='['){
                    pila.pop();
                } else{
                    return "No";
                }
            }
        }
    }
    if(!pila.empty()){
        return "No";
    }
    return "Yes";
}

int main(){
    int casos;
    string cadena;
    cin >> casos;
    cin.ignore();
    while(casos--){
        getline(cin,cadena);
        cout << revision(cadena) << endl;
    }
    return 0;
}
