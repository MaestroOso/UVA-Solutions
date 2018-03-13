#include <bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        string linea;
        getline(cin,linea);
        if(linea.empty()){
            return 0;
        }
        int cont = 0;
        for(int i = 0; i<linea.size(); i++){
            if((linea[i]>='A' && linea[i]<='Z')||(linea[i]>='a' && linea[i]<='z')){
                cont++;
                while((linea[i]>='A' && linea[i]<='Z')||(linea[i]>='a' && linea[i]<='z')){
                    i++;
                    if(i==linea.size()){
                        break;
                    }
                }
            }
        }
        cout << cont << endl;
    }
return 0;
}
