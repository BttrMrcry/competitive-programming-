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


inline void solve() {
    vector<vector<long long>> dp(10000, vector<long long>(750));
    vector<vector<long long>> t(750, vector<long long>(750));
    vector<long long> p(10000); 60mb
    long long k, l, n;
    cin >> k >> l;

    FO(i, k){
        FO(j, k){
            cin >> t[i][j];
        }
    }

    cin >> n;

    FO(i, n - 1){
        cin >> p[i];
    }

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}