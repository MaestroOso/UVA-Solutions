#include <bits/stdc++.h>
using namespace std;

long long tam;
bitset<10000010> bs;
vector<int> primes;

void sieve(long long upperbound)
{
    tam = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i<= tam; i++)
    {
        if(bs[i])
        {
            for(long long j = i*i; j<= tam; j+=i)
            {
                bs[j] = 0;
            }
            primes.push_back((int)i);
        }
    }
}

bool isPrime(long long N){
    if(N <= tam){
        return bs[N];
    }
    for(int i = 0; i<primes.size(); i++){
        if(N%primes[i]==0){
            return false;
        }
    }
    return true;
}

int main()
{
    sieve(10000000);
    int num;
    bool primeraVez = false;
    //cout << primes[primes.size() - 1] << endl;
    while(/**cin >> num**/ scanf("%d",&num) && num)
    {
        primeraVez = true;
        printf("%d = ", num);
        if(num < 0)
        {
            printf("-1");
            num = num*(-1);
            primeraVez = false;
        }
        for(int i = 0; primes[i] <= sqrt(num); i++)
        {
            //cout << i << " " << primes[i] << endl;
            if(num == 1)
            {
                break;
            }
            while(num%primes[i] == 0)
            {
                if(primeraVez)
                {
                    printf("%d", primes[i]);
                    primeraVez = false;
                }
                else
                {
                    printf(" x %d", primes[i]);
                }
                num = num/primes[i];
            }
        }
        if(num!=1){
            if(primeraVez)
                {
                    printf("%d", num);
                }
                else
                {
                    printf(" x %d", num);
                }
        }
        printf("\n");
    }
    return 0;
}
