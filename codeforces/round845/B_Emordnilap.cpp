#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long


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

array<ll, 100001> fact;

void precal(){
    fact[0] = 1;
    for(int i = 1; i <= 100000; i++){
        fact[i] = i * fact[i - 1] % MODC;
    }
}

ll sum(ll n){
    return n * (n + 1) / 2 % MODC;
}

inline void solve() {
    int n;
    cin >> n;
    ll sol = 2*sum(n-1) % MODC *fact[n] % MODC;
    cout << sol << endl;

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    cin >> T;
    precal();
    FO(tc, T){
        solve();
    }
    return 0;
}