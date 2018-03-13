#include <bits/stdc++.h>
using namespace std;

long long power(long long n, long long elevado){
    long long y = n;
    for(int i = 1; i<elevado; i++){
        y = y*n;
    }
    return y;
}

vector<bool> isPrime;
vector<int> primes;
void sieve (long long n)
{
    n++;
    isPrime.assign(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(long long i = 2; i <= n; i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(long long j = i*i; j <= n; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
    return;
}

bool esprimo(long long n)
{
    if(n<isPrime.size())
    {
        return isPrime[n];
    }
    else
    {
        int pos = 0;
        while(primes[pos]<sqrt(n))
        {
            if(n%primes[pos]==0)
            {
                return false;
            }
            pos++;
        }
        return true;
    }
}

int factoresPrimos(long long n){
    int primeraVez = 0;
    for(int i = primes.size()-1; i>=0; i--){
        int cont = 0;
        if(n%primes[i]==0){
            while(n%primes[i]==0){
                if(n==1){cout << endl; return 1;}
                cont++;
                n = n/primes[i];
            }
            if(primeraVez!=0){cout<<" ";}
            cout << primes[i] << " " << cont;
            primeraVez++;
        }
        if(n==1){
            cout << endl;
            return 1;
        }
    }


}


int main()
{
    sieve(32800);
    string linea;
    while(getline(cin,linea) && linea!="0"){
        long long n, mult, total=1;
        stringstream ss;
        ss.str(linea);
        while(ss>>n){
            ss>>mult;
            total*= power(n,mult);
        }
        total--;
        factoresPrimos(total);
    }
    return 0;
}
