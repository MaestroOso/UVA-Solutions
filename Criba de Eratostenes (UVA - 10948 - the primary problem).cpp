#include <bits/stdc++.h>
using namespace std;

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




int main()
{
    sieve(1000000);
    long long caso=0;
    while(cin>>caso && caso)
    {
        bool band=0;
        int a1,a2;
        for(int i=primes.size()-1; i>=0 && !band; i--)    /**for(int i=0; i<primes.size(); i++)*/ //Ambos for sirven para solucionar el problema
        {
            if(primes[i]<caso)
            {
                if(isPrime[caso-primes[i]])
                {
                    band=1;
                    a1=primes[i];
                    a2=caso-primes[i];
                }

            }
        }
        if(a1>a2)
            swap(a1,a2);
        if(band)
            cout<<caso<<":\n"<<a1<<'+'<<a2<<endl;

        else
            cout<<caso<<":\n"<<"NO WAY!"<<endl;
    }

    return 0;
}
