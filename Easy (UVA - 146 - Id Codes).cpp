#include<bits/stdc++.h>

using namespace std;
int main(){
    string cadena;
    while(cin>>cadena && cadena!="#"){
        if(next_permutation(cadena.begin(),cadena.end())==true){
            cout << cadena << endl;
        } else {
            cout << "No Successor" << endl;
        }
    }
return 0;
}
