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
    int a, b;
    cin >> a >> b;
    double px = (double)(2*a - b)/3;
    long long x = llround(px);
    

    if(abs(px - x) > 0.000001 || x < 0){
        cout << "NO" << endl;
        return;
    }

    double py = (double)(2*b - a)/3;
    long long y = llround(py);
    
    if(abs(py - y) > 0.000001 || y < 0){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;


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