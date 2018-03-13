#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define INF 1000000001

struct segmentTree{
    /**Altura del arbol 2^(log(n)+1)  -- 2n
        A valores de verdad
        st segment tree
    **/
    vi st, A;
    int n;

    int left(int p){
        return p<<1;
    }

    int right(int p){
        return (p<<1)+1;
    }

    void build(int p,int L, int R){
        if( L == R){
            st[p] = L;
            return;
        }
        int mid = (L+R)/2;
        build(left(p), L, mid);
        build(right(p), mid+1, R);
        int p1 = st[left(p)];
        int p2 = st[right(p)];
        st[p] = A[p1] <= A[p2] ? p1 : p2;
    }

    segmentTree(vi A_){
        A = A_;
        n = A.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }

    int rmq(int i, int j){
        int b = rmq(0,n-1,1,i,j);
        //cout << b << " " <<A[b] << endl;
        return A[b];
        //return b;
    }

    int rmq(int L, int R, int p, int limIzq, int limDer){
        //cout << "L, R "<<L << " " << R << endl;
        if(limIzq > R || limDer < L){
            //cout << "Fuera\n";
            return INF;
        }
        if(L >= limIzq && R <= limDer){
            //cout << "Dentro\n";
            return st[p];
        }
        /**
            Recursion otra vez
        **/

        int mid = (L+R)/2;
        int indiceIzq = rmq(L, mid, left(p), limIzq, limDer);
        int indiceDer = rmq(mid+1, R,right(p), limIzq, limDer);

        if(indiceIzq == INF){
            //cout << "INF1\n";
            return indiceDer;
        } else if(indiceDer == INF){
            //cout << "INF2\n";
            return indiceIzq;
        }
        //cout << "Pregunta\n";
        return A[indiceIzq] < A[indiceDer] ? indiceIzq : indiceDer;

    }

    void imprimir(){
        for(int i = 1; i<st.size(); i++){
            cout << st[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    vi queso;
    queso.push_back(3);
    queso.push_back(4);
    queso.push_back(5);
    queso.push_back(7);
    queso.push_back(8);
    queso.push_back(2);
    queso.push_back(4);
    queso.push_back(4);
    segmentTree st(queso);
    st.imprimir();
    int izq, der;
    while(true){
        cin >> izq >> der;
        if(izq < 0 && der < 0){
            break;
        }
        cout << st.rmq(izq, der) << endl;
    }
    return 0;
}
