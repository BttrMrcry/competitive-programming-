#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long

long long gcd(long long a, long long b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}  

long long mcd(long long a, long long b){
    return a/gcd(a, b)*b;
}

int extended_euclidean(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll invMod(ll a, ll m){
    long long x, y;
    long long g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        return -1;
    }
    else {
        x = (x % m + m) % m;
        return x;
    }
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MODC;
        a = a * a % MODC;
        b >>= 1;
    }
    return res;
}


// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------
void setIO(){
    string file = __FILE__;
    file = string(file.begin(),file.end()-3);
    string input_file = file+"in";
    string output_file =file+"out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

#define M 500010

array<ll, M> fact;
array<ll, M> invFact;

void preCal(){
    fact[0] = 1;
    invFact[0] = invMod(fact[0], MODC);

    for(int i = 1; i < M; i++){
        fact[i] = fact[i-1] * i % MODC;
        invFact[i] = invMod(fact[i], MODC);
    }
}



inline long long com(long long a, long long b){
    return fact[a] * invFact[a - b] % MODC * invFact[b] % MODC; 
}


inline void solve() {
    ll m, n;
    cin >> m >> n;

    long long res = 0;
    long long nexp = 1;
    long long n1exp = binpow(n - 1, m - n);
    long long invN = invMod(n - 1, MODC);

    for(int i = 0; i <= m - n; i++){

        if(i == m - n){
            n1exp = 1;
        }
        res = (res + com(m - i - 1, n - 1)*nexp % MODC *n1exp % MODC) % MODC;
        nexp  = nexp * n % MODC;
        n1exp = n1exp * invN % MODC;
        //cout << res << endl;
    }


    cout << res << endl;


}

int main() {
    if(getenv("CP_IO")) setIO();
    int T;
    cin >> T;
    preCal();
    FO(tc, T){
        solve();
    }
    return 0;
}


//Cada nodo es un elemento que pueden unirse entre sí
struct UnionFindNode {
    UnionFindNode* parent;
    long long size;

    UnionFindNode(){
        parent = this;
    }

    UnionFindNode* find(){
        if(parent == this){
            return this;
        }else{
            return parent = parent->find();
        }
    }

    UnionFindNode* unionSets(UnionFindNode* other){
        UnionFindNode* set1 = this->find();
        UnionFindNode* set2 = other->find();

        if(set1 == set2){
            return set1;
        }else{
            if(set2->size > set1->size){
                swap(set1, set2);
            }
            set2->parent = set1;
            set1->size += set2->size;
            return set1;
        }
    }
};

