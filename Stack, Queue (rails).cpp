#include<iostream> 
#include<queue> 
#include<stack> 
  
using namespace std; 
  
int main() 
{ 
    int num,n; 
    bool bandera = true, primero = true; 
    while(true) 
    { 
        if(bandera) 
        { 
            cin>>num; 
            if(!primero) 
            { 
                cout<<endl; 
            } 
            primero = false; 
            bandera = false; 
            if(num == 0)break; 
        } 
        queue<int> cola; 
        stack<int> pila; 
        for(int i = 0; i<num; i++) 
        { 
            cin >> n; 
            if(n == 0) 
            { 
                bandera = true; 
                break; 
            } 
            cola.push(n); 
        } 
        if(bandera)continue; 
        for(int i = 1; i<=num; i++) 
        { 
            pila.push(i); 
            while(!pila.empty()&&pila.top()==cola.front()) 
            { 
                pila.pop(); 
                cola.pop(); 
            } 
        } 
        if(cola.empty()) 
        { 
            cout << "Yes\n"; 
        } 
        else
        { 
            cout << "No\n"; 
        } 
    } 
    return 0; 
} 