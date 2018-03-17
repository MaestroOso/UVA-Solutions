#include <bits/stdc++.h>
using namespace std;

int resultado(vector<int> &barras, vector<int> multipl){
    int res = 0;
    for(int i = 0; i<20; i++){
        res+=barras[i]*multipl[i];
    }
    return res;
}

bool combinatoria(vector<int> &barras, int tam){
    vector<int> o(20,0);
    for(o[0]=0; o[0]<=1; o[0]++)
    for(o[1]=0; o[1]<=1; o[1]++)
    for(o[2]=0; o[2]<=1; o[2]++)
    for(o[3]=0; o[3]<=1; o[3]++)
    for(o[4]=0; o[4]<=1; o[4]++)
    for(o[5]=0; o[5]<=1; o[5]++)
    for(o[6]=0; o[6]<=1; o[6]++)
    for(o[7]=0; o[7]<=1; o[7]++)
    for(o[8]=0; o[8]<=1; o[8]++)
    for(o[9]=0; o[9]<=1; o[9]++)
    for(o[10]=0; o[10]<=1; o[10]++)
    for(o[11]=0; o[11]<=1; o[11]++)
    for(o[12]=0; o[12]<=1; o[12]++)
    for(o[13]=0; o[13]<=1; o[13]++)
    for(o[14]=0; o[14]<=1; o[14]++)
    for(o[15]=0; o[15]<=1; o[15]++)
    for(o[16]=0; o[16]<=1; o[16]++)
    for(o[17]=0; o[17]<=1; o[17]++)
    for(o[18]=0; o[18]<=1; o[18]++)
    for(o[19]=0; o[19]<=1; o[19]++){
        if(resultado(barras,o)==tam){
            cout << "YES\n";
            return true;
        }
    }
    cout << "NO\n";
    return true;
}

int main(){
    int casos, numBarras, longitud;
    cin >> casos;
    while(casos--){
        cin >> longitud >> numBarras;
        vector<int> barras(20);
        for(int i = 0; i<numBarras; i++){
            cin >> barras[i];
        }
        combinatoria(barras,longitud);
    }

return 0;
}
