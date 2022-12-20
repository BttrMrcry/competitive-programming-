#include <bits/stdc++.h>
using namespace std;


#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x)
#define pll(x)          printf("%lld\n", x)
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define all(x)          x.begin(), x.end()

typedef vector<int> vi;
typedef vector<long long> vll;



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

void solve() {
    int exp; // exponente de la operación
    cin >> exp;
    long long res = 1; //resultado
    long long power = 2; // potencia par actual, al inicio es la base
    while(exp > 0){
        if(exp & 1) // Revisa el primer bit
            res = res * power % MODC; //multiplica por el resultado acomulado si el bit está activado
        power = power * power % MODC; //Calcula la siguiente potencia par
        exp = exp >> 1; //recorre el exponente a la derecha para tener acceso al siguiente bit.
    }
    cout << res << endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}