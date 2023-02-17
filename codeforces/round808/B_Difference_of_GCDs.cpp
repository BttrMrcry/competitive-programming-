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
    int n, r, l;
    cin >> n >> l >> r;
    vector<int> sol;
    for(int i = 1; i <= n; i++){
        int multi = (((l - 1) / i) + 1)* i;
        if(multi > r){
            cout << "NO" << endl;
            return;
        } 
        sol.push_back(multi);
    }
    cout << "YES" << endl;
    for(auto n : sol){
        cout << n << " ";
    }
    cout << endl;
    return;

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    cin >> T;
    FO(tc, T){
        solve();
    }
    return 0;
}