#include <bits/stdc++.h>
using namespace std;
int main(){
    int adelante, atras, aux;
    while(cin >> adelante && adelante!=0){
        cin >> atras;
        vector<float> d_adelante;
        vector<float> d_atras;
        for(int i = 0; i<adelante; i++){
            cin >> aux;
            d_adelante.push_back(aux);
        }
        for(int i = 0; i<atras; i++){
            cin >> aux;
            d_atras.push_back(aux);
        }
        vector<float>radios;
        int pos = 0;
        for(int i=0; i<atras; i++){
            for(int j = 0; j<adelante; j++){
                radios.push_back(d_atras[i]/d_adelante[j]);
            }
        }
        sort(radios.begin(),radios.begin()+radios.size());

        vector<float> divisiones;
        for(int i = 0; i<radios.size()-1; i++){
            divisiones.push_back(radios[i+1]/radios[i]);
        }
        sort(divisiones.begin(),divisiones.begin()+divisiones.size());
        printf("%.2lf\n",divisiones[divisiones.size()-1]);
    }
return 0;
}
