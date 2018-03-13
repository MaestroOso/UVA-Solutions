#include <bits/stdc++.h>
using namespace std;

/** Respuesta --> Costo menor total
    Meses     --> Numero de meses
    Contratar --> Costo de contratar
    Salario   --> Pago del salario
    Multa     --> Multa por despedir
    Minimo numero de meses
**/

int meses, contratar, salario, multa, maximo, respuesta, minimo, queso = 10000000;


void imprimirMatriz(vector<vector<int> > progreso)
{
    for(int i = 0; i<progreso.size(); i++)
    {
        for(int j = minimo; j<progreso[i].size(); j++)
        {
            cout << progreso[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int funcion(int numEsclavos, int contrataciones, int despidos)
{
    return numEsclavos*salario + contrataciones*contratar + despidos*multa;
}

int calcularMejorSalario(vector<int> esclavos)
{
    /** Mes 0  --> Se contratan todos los trabajadores y se les paga **/
    if(meses == 1)
    {
        return esclavos[0]*salario + esclavos[0]*contratar;
    }

    /**
        Filas --> Meses
        Columnas --> Numero de esclavos
    **/
    vector<vector<int> > progreso(meses, vector<int>(maximo,queso));

    /** El primer mes el único valido es el numero de empleados de ese mes
        el resto es queso **/
    progreso[0][esclavos[0]] = esclavos[0]*salario + esclavos[0]*contratar;

    /** Se recorren todos los meses salvo el último donde no hay multa **/
    for(int mes = 1; mes < meses; mes++)
    {
        //imprimirMatriz(progreso);
        /** Recorro todas las casillas posibles es decir desde el minimo de
            esclavos total del mes **/
        for(int tra = minimo; tra < maximo; tra++)
        {
            if(tra < esclavos[mes])
            {
                progreso[mes][esclavos[mes]] = min(progreso[mes][esclavos[mes]], progreso[mes-1][tra] + funcion(esclavos[mes],esclavos[mes]-tra,0));
            }
            else
            {
                /** Recorrer todos los casos posibles pasados **/
                for(int pasado = tra; pasado < maximo; pasado++)
                {
                    if(progreso[mes-1][pasado]!=queso)
                        progreso[mes][tra] = min(progreso[mes][tra], progreso[mes-1][pasado] + funcion(tra, 0, pasado-tra));
                }
            }
        }
    }


    respuesta = queso;
    //imprimirMatriz(progreso);

    for(int i = 0; i<progreso[meses-1].size(); i++)
    {
        //cout << progreso[meses-1][i] << " ";
        respuesta = min(respuesta, progreso[meses-1][i]);
    }
    //imprimirMatriz(progreso);
    return respuesta;
}

int main()
{
    int casos = 1;
    while(true)
    {
        scanf("%d",&meses);
        if(meses == 0)
        {
            return 0;
        }
        scanf("%d %d %d",&contratar,&salario,&multa);
        maximo = 0;
        minimo = INT_MAX;
        vector<int> esclavos(meses);
        for(int i = 0; i<meses; i++)
        {
            scanf("%d",&esclavos[i]);
            maximo = max(maximo,esclavos[i]);
            minimo = min(minimo,esclavos[i]);
        }
        maximo++;
        calcularMejorSalario(esclavos);
        printf("Case %d, cost = $%d\n", casos, respuesta);
        casos++;
    }
    return 0;
}
