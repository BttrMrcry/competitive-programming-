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
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    vector<long long> mem(x + 1, INT_MAX);
    FO(i, n){
        cin >> c[i];
    }
    mem[0] = 0;
    for(int i = 1; i <= x; i++){
        FO(j, n){
            int ip = i - c[j];
            if(ip < 0){
                continue;
            }else{
                mem[i] = min(mem[i], mem[ip] + 1);
            }
        }
    }
    if(mem[x] == INT_MAX)
        cout << "-1" << endl;
    else
        cout << mem[x] << endl;


}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}