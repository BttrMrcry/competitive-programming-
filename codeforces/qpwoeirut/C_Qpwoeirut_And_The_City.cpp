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

ll get(int i, array<ll, 1000001> &h){
    if(h[i] > h[i - 1] && h[i] > h[i + 1])
        return 0;
    else
        return max(h[i - 1], h[i + 1]) + 1 - h[i];
}

inline void solve() {
    int n;
    cin >> n;
    array<ll, 1000001> h;
    FO(i, n){
        cin >> h[i];
    }

    if(n % 2){
        ll sol = 0;
        for(int i = 1; i < n - 1; i += 2){
            sol += get(i, h);
            //cout << "parsol: " << sol << endl;
        }
        cout << sol << endl;
    }else{
        ll sol = LONG_LONG_MAX;
        ll parsol = 0;
        for(int i = 1; i < n - 1; i += 2){
            parsol += get(i, h);
        }
        //cout << "cur: " << parsol << endl;
        sol = min(parsol, sol);
        for(int i = n - 3; i > 0; i -= 2){
            parsol = parsol - get(i, h);
            //cout << "cur 1: " << parsol << endl;
            parsol = parsol + get(i + 1, h);
            //cout << "cur 2: " << parsol << endl;
            sol = min(parsol, sol);
        }
        cout << sol << endl;
    }

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