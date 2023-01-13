#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
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

inline void solve() {
    int n;
    cin >> n;
    long long ac = 1;
    FO(i,n){
        long long k;
        cin >> k;
        ac *= k;
    }
    long long res = ac + n - 1;

    cout << res*2022 << endl;


}

int main() {
    if(getenv("CP_IO")) setIO();
    int T;
    cin >> T;
    FO(tc, T){
        solve();
    }
    return 0;
}