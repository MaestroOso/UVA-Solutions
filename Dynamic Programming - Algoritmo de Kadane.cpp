#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> par;
typedef vector<int> secuencia;

par kadane(secuencia seq)
{
  int maximoActual=seq[0];
  int maximoTotal=seq[0];
  int sA = 0, eA = 0;
  par maximo;
  maximo.first = 0;
  maximo.second = 0;
  
  for(int i = 1; i < seq.size(); i++)
  {
    if(maximoActual + seq[i] < seq[i])
    {
      maximoActual = seq[i];
      sA = i;
      eA = i;
    }
    else
    {
      maximoActual = maximoActual + seq[i];
      eA = i;
    }
    
    if(maximoTotal < maximoActual)
    {
      maximoTotal = maximoActual;
      maximo.first = sA;
      maximo.second = eA;
    }
  }
  return maximo;
}

int main()
{
  secuencia seq;
  seq.push_back(10);
  seq.push_back(5);
  seq.push_back(0);
  seq.push_back(-25);
  seq.push_back(-20);
  seq.push_back(-20);
  seq.push_back(-14);
  seq.push_back(-25);

  par cadena = kadane(seq);
  cout<<cadena.first<<endl;
  cout<<cadena.second<<endl;
  return 0;
}
