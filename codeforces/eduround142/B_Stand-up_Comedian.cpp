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
    ll a[4];
    ll sol = 0;
    FO(i, 4){
        cin >> a[i];
    }
    ll b = 0;
    ll c = 0;

    sol += a[0];
    ll dif = abs(a[1] - a[2]);
    
    if(a[0] - dif <= -1){
        sol += (a[1] + a[2] - dif + a[0] + 1);
        cout << sol << endl;
        return;
    }
    if(dif == 0 && a[1] == 1){
        cout << 1 << endl;
        return;
    }

    long long minVal = a[0] - dif + 1;

    if(a[3] > minVal){
        sol += minVal;
    }else{
        sol += a[3];
    }

    cout << sol << endl;    

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