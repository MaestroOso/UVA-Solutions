#include <bits/stdc++.h>
using namespace std;
union x{
    int num;
    char bytes[4];
};
int main(){
    x queso;
    while(cin>>queso.num){
        cout << queso.num << " converts to ";
        x alpha;
        alpha.bytes[0] = queso.bytes[3];
        alpha.bytes[1] = queso.bytes[2];
        alpha.bytes[2] = queso.bytes[1];
        alpha.bytes[3] = queso.bytes[0];
        cout << alpha.num<<endl;

    }

return 0;
}
