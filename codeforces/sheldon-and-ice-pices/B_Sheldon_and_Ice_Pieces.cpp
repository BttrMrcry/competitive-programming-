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
    array<int, 10> digits = {0};
    array<int, 10> count = {0};
    string t;
    string ice;

    cin >> t >> ice;

    for(char c : t){
        if(c -'0' == 9){
            digits[6] += 1;
        }else if(c - '0' == 5){
            digits[2] += 1;
        }else{
            digits[c - '0'] += 1;
        }

    }

    for(char c: ice){
        if(c -'0' == 9){
            count[6] += 1;
        }else if(c - '0' == 5){
            count[2] += 1;
        }else{
            count[c - '0'] += 1;
        }
    }

    int sol = INT_MAX;

    FO(i, 10){
        if(digits[i] != 0)
            sol = min(count[i]/digits[i], sol);
    }

    cout << sol << endl;

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}