#include <bits/stdc++.h>
using namespace std;
int main(){
    int casos;
    string linea;
    cin >> casos;
    cin.ignore();
    getline(cin,linea);
    while(casos--){
        map<string,double> especies;
        double cont = 0;
        while(getline(cin,linea) && linea!=""){
            cont++;
            if(especies.find(linea)!=especies.end()){
                especies[linea]++;
            } else {
                especies[linea] = 1;
            }
        }

        for(map<string,double>::iterator it = especies.begin(); it!=especies.end(); it++){
            cout << (it->first) << " ";
            printf("%.4f\n", ((it->second/cont)*100.0));
        }
        if(casos!=0){
        cout << endl;
        }
    }
return 0;
}
