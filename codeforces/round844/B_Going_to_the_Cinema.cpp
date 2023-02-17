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

#define maxn  200001

inline void solve() {
    int n;
    array<int, maxn> a = {0};
    cin >> n;

    FO(i, n){
        cin >> a[i];
    }

    sort(a.begin(), a.begin() + n, greater<>());

    int c = 0;
    bool ok = true;
    if(a[0] < n)
        c++;
    
    // FO(i, n){
    //     cout << a[i] << endl;
    // }

    for(int i = 1; i < n; i++){
        if(a[i] < n - i && a[i-1] > n - i && a[i-1] != a[i]){
            //cout <<"index: "<< i <<"val: "<<a[i] << endl;
            c++;
        }
        if(a[i] == 0){
            ok = false;
        }
    }

    if(ok)
        c++;

    cout << c << endl;
    
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