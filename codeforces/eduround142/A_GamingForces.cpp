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
    int n;
    cin >> n;
    array<int, 100> h;
    for(int i = 0; i < n; i += 1){
        cin >> h[i];
    }
    sort(h.begin(), h.begin() + n);

    int count = 0;
    for(int i = 1; i < n; i += 2){
        if(h[i - 1] == 1 && h[i] == 1){
            count += 1;
            h[i] = 0;
            h[i - 1] = 0; 
        }
    }

    for(int i = 0; i < n; i++){
        if(h[i] != 0){
            count += 1;
        } 
    }

    cout << count << endl;

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