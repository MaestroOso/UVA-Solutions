#include <bits/stdc++.h>
using namespace std;
/** Usada para imprimir las soluciones **/
int linea;


/** Verifica la solucion del problema
    recibe el tablero por parametro con las posiciones de las damas
    Para las posiciones se sabe que cada una esta en una columna diferente y estas
    son representadas como la posicion en el arreglo. Los valores en cada una de las
    posiciones son las poisiones de las damas en las columnas

    Para verificar si una posicion esta correcta se verifican todas las damas ubicadas antes
    de la fila en la que se encuentra el backtracking. Para ello se verifica que ninguna de las
    otras damas se encuentre en la misma fila o que esten sobre la misma diagonal.
    Para comprobar las diagonales se sabe que la distancia entre filas y entre columnas es la misma
    entonces es porque las damas estan sobre la misma diagonal
**/
bool posCorrecta(vector<int> &tablero, int fila, int col){
    for(int anterior = 0; anterior<col; anterior++){
        if(tablero[anterior]== fila || (abs(tablero[anterior]-fila) == abs(anterior-col))){
            return false;
        }
    }
    return true;
}

/** La variable que recorre es la que realiza el backtracking, es decir, la que va cambiando.
    Si esta variable llega al final del tablero mas uno, es decir a la octava posicion y
    la combianacion que se tiene es la pedida por el caso entonces se procede a imprimir dicha solucion.

    Si aun no se ha llegado a este caso, se va recorriendo todas las filas del tablero iterando todas
    las posibles combinaciones. Para cada una se va verificando que dicha solucion sea correcta parcialmente y
    si lo es entonces se actualiza el tablero con esta posición y se aumenta la variable que recorre para ir
    buscando la siguiente posible combinación

    De lo contrario no realiza nada y va buscando asi las combinaciones. Si no encuentra ninguna que le sirva entonces
    simplemente se devuelve al caso mas cercano anterior y vuelve a buscar las combinaciones
**/

void backtracking(vector<int> &tablero, int filaD, int columnaD, int variableQueRecorre){
    if(variableQueRecorre==8 && tablero[columnaD] == filaD){
        printf("%2d      %d", ++linea, tablero[0]+1);
        for(int j = 1; j<8; j++){
            printf(" %d", tablero[j]+1);
        }
        cout << endl;
    }
    for(int r = 0; r<8; r++){
        if(posCorrecta(tablero,r,variableQueRecorre)){
            tablero[variableQueRecorre] = r;
            backtracking(tablero,filaD,columnaD,variableQueRecorre+1);
        }
    }
}

/** Recibe las coordenadas de cada una de las damas de los casos de prueba. Hace el llamado a la
    funcion backtracking desde la posicion 0 y va imprimiendo los casos que sirven

    Recordar que el tablero toma la notacion de 0 a 7 y para la impresion y lectura se debe tener
    esto en cuenta**/
int main(){
    int casos;
    int filaD, columnaD;
    cin >> casos;
    while(casos--){
        linea = 0;
        cin >> filaD >> columnaD;
        filaD--;
        columnaD--;
        vector<int> tablero(8,0);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        /**Genera todas las posibles soluciones**/
        backtracking(tablero,filaD,columnaD,0);
        if(casos){
            cout << endl;
        }
    }
return 0;}
