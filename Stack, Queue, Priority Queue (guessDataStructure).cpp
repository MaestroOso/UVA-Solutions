#include <bits/stdc++.h>
using namespace std;

int main()
{
    int casos, opcion, numero;;
    while(cin>>casos)
    {
        queue<int> cola;
        bool ban_cola = true;
        stack<int> pila;
        bool ban_pila = true;
        priority_queue<int> pq;
        bool ban_pq = true;
        for(int i = 0; i<casos; i++)
        {
            cin >> opcion;
            cin >> numero;
            if(opcion==1)
            {
                cola.push(numero);
                pila.push(numero);
                pq.push(numero);
            }
            else
            {
                if(ban_cola)
                {
                    if(!cola.empty()&&cola.front()==numero)
                    {
                        cola.pop();
                    }
                    else
                    {
                        ban_cola = false;
                    }
                }
                if(ban_pila)
                {
                    if(!pila.empty()&&pila.top()==numero)
                    {
                        pila.pop();
                    }
                    else
                    {
                        ban_pila = false;
                    }
                }
                if(ban_pq)
                {
                    if(!pq.empty()&&pq.top()==numero)
                    {
                        pq.pop();
                    }
                    else
                    {
                        ban_pq = false;
                    }
                }
            }
        }
        if(ban_cola&&ban_pila&&ban_pq)
        {
            cout << "not sure\n";
        }
        else if(ban_cola&&ban_pila)
        {
            cout << "not sure\n";
        }
        else if(ban_cola&&ban_pq)
        {
            cout << "not sure\n";
        }
        else if(ban_pila&&ban_pq)
        {
            cout << "not sure\n";
        }
        else if(ban_cola)
        {
            cout << "queue\n";
        }
        else if(ban_pila)
        {
            cout << "stack\n";
        }
        else if(ban_pq)
        {
            cout << "priority queue\n";
        }
        else
        {
            cout << "impossible\n";
        }
    }
    return 0;
}
