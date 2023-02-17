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
    int n, s, r;
    cin >> n >> s >> r;
    int sol = (n-1)*(s - r);
    int defaults = n - 1;
    while(sol != r){
        int res = min(s - r - 1, sol - r);
        //cout <<"res: "<<endl;
        sol = sol - res;
        cout << s - r - res << " ";
        defaults--;
    }

    FO(i, defaults){
        cout << s - r << " ";
    }

    cout << s - r << endl;
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