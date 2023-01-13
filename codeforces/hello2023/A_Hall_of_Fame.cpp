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
    vector<char> direc(n);

    int righti = INT_MAX;
    int lefti = -1; 
    FO(i, n){
        char d;
        cin >> d;
        if(d == 'L' && lefti < i){
            lefti = i;
        }
        if(d == 'R' && i < righti ){
            righti = i;
        }
    }
    if(righti == INT_MAX || lefti == -1){
        cout << -1 << endl;
        return;
    }

    if(lefti < righti && righti - lefti == 1){
        cout << righti << endl;
        return;
    }

    if(lefti > righti){
        cout << 0 << endl;
        return;
    }
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 0;
    cin >> T;
    FO(tc, T){
        solve();
    }
    return 0;
}