/** Standart Template Library
   Estructuras de Datos que ya estan implementadas
   vector <int> vec(nombre)

   Insertar Elementos en el Arreglo - Vector
   vec.push_back(num);
   Agrega un elemento al arreglo

   Acceder a una posición
   vec[9]

   vec.size();

   Ordenar de menor a mayor
   sort(vec.begin(), s.end());

   vec.begin() --> se refiere a un apuntador a la primera posicion del vector
   vec.end() --> se refiere a un apuntador a las ultima posicion +1 del vector

   Ordenar de mayor a menor
   sort(vec.rbegin(), vec.rend());

   vec.rbegin --> se refiere a la primera posicion del vector -1
   vec.rend --> Se refiere a la ultima posicion del vector

   Inicializar el vector muchas posiciones y numero
   vector <int> vec(1000, -1)

   Para borrar un elemento
   arr.erase(apuntador_pos);

   Para borrar de un elemento a un elemento
   arr.erase(apuntador_pos_inicial, apuntador_pos_final);
   */

/** Sort --> Ordenar los elementos
    Para un arreglo: sort(arr, arr+10);
    Para un string: Sort(s.begin() , s.end());
    */


/** ---LISTAS---
list <int> milista

Insertar al final
milista.pushback(elemento);

Insertar al Principio
milista.pushfront(elemento);

Insertar un elemento en una posicion
milista.insert(posicion, dato);

Eliminar un elemento en una posicion
milista.erase(posicion, dato);

*/


/** --Iteradores--
Declaracion
list<int> :: iterator it

Recorrer una lista
for(it = milista.begin(); milista.end(); it++){

    }
*/


/** --Pilas--
Grupo de elementos que se ubican unos sobre otros. En estos
solamente se puede modificar el elemento que este en la
parte superior

stack<libro> pila;
pila.push("el señor de los anillos");
pila.top;
pila.pop;
pila.empty();

*/

/** --- Cola ---
queue <int> cola;
cola.push(dato);
cola.pop();
cola.front();
cola.empty();
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    cout << "------ VECTOR ------\n";
    vector <int> arr;
    for(int i = 0; i<10; i++)
    {
        arr.push_back(rand()%50);
    }
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    sort(arr.begin(), arr.end());
    for (int i = 0; i<10; i++)
    {
        cout << arr[i] << "\t";
    }

    for(int i = 0; i<10; i++)
    {
        if(arr[i]<10)
        {
            arr.erase(arr.begin()+i);
            i-=2;
        }
    }
    cout << endl;
    for (int i = 0; i<arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }

    cout << "\n------ PILAS ------\n";

    stack <char> pila;
    string frase = "{{{}}}";
    for(int i = 0; i<frase.size(); i++)
    {
        pila.push(frase[i]);
    }
    int a=0, b=0;
    for(int i = 0; i<; i++)
    {
        if( pila.top() = '{' )
        {
            a++;
            pila.pop();
        }
        else
        {
            b++;
            pila.pop();
        }
    }
    if(a==b)
    {
        cout << "Sin";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
