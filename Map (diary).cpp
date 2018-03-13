#include <bits/stdc++.h>
using namespace std;
int za = 'Z'-'A';
map<char,int> an;
map<int,char> na;
vector<int> pos;
void inicializar(){
an['A'] = 0; na[0] = 'A';
an['B'] = 1; na[1] = 'B';
an['C'] = 2; na[2] = 'C';
an['D'] = 3; na[3] = 'D';
an['E'] = 4; na[4] = 'E';
an['F'] = 5; na[5] = 'F';
an['G'] = 6; na[6] = 'G';
an['H'] = 7; na[7] = 'H';
an['I'] = 8; na[8] = 'I';
an['J'] = 9; na[9] = 'J';
an['K'] = 10; na[10] = 'K';
an['L'] = 11; na[11] = 'L';
an['M'] = 12; na[12] = 'M';
an['N'] = 13; na[13] = 'N';
an['O'] = 14; na[14] = 'O';
an['P'] = 15; na[15] = 'P';
an['Q'] = 16; na[16] = 'Q';
an['R'] = 17; na[17] = 'R';
an['S'] = 18; na[18] = 'S';
an['T'] = 19; na[19] = 'T';
an['U'] = 20; na[20] = 'U';
an['V'] = 21; na[21] = 'V';
an['W'] = 22; na[22] = 'W';
an['X'] = 23; na[23] = 'X';
an['Y'] = 24; na[24] = 'Y';
an['Z'] = 25; na[25] = 'Z';
for(int i = 0; i<2; i++){
    for(int j = 0; j<26; j++){
        pos.push_back(j);
    }
    }
}


int calcularDistancia(char letra){
    if(letra<'E'){
        return letra+('Z'-'A')-'E'+1;
    } else if (letra=='E'){
        return 0;
    } else {
        return letra-'E';
    }
}

int main()
{
    inicializar();
    int casos;
    cin >> casos;
    cin.ignore();
    while(casos--){
        string linea;
        getline(cin,linea);
        map<char,int> aparicion;
        for(int i = 0; i<linea.size(); i++){
            if(linea[i]!=' '){
                if(aparicion.find(linea[i])==aparicion.end()){
                    aparicion[linea[i]]=1;
                } else {
                    aparicion[linea[i]]++;
                }
            }
        }
        map<char,int>::iterator it = aparicion.begin();
        int numMax = 0;
        char letra = ' ';
        for( ;it!=aparicion.end(); it++){
            if(it->second > numMax){
                numMax = it->second;
                letra=it->first;
            }
        }

        bool si = true;
        for(it = aparicion.begin();it!=aparicion.end(); it++){
            if(it->second == numMax && it->first != letra){
                cout << "NOT POSSIBLE\n";
                si = false;
                break;
            }
        }
        if(letra==' ' && si){
            si=false;
            cout << "NOT POSSIBLE\n";
        }
        if(!si){
            continue;
        }

        int dist = calcularDistancia(letra);
        cout << dist << " ";
        for(int i = 0; i<linea.size(); i++){
            if(linea[i]!=' '){
                    int q = pos[26+an[linea[i]]-dist];
                    cout << na[q];
                } else {
                    cout << " ";
                }
            }
        cout << endl;

    }
    return 0;
}

