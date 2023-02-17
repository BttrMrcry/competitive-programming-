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
    string s;
    cin >> s;
    int ab = INT_MAX;
    int ba = INT_MAX;
    for(int i = 1; i < s.size(); i++){
        if( s[i - 1] == 'A' && s[i] == 'B'){
            ab = i;
            break;
        }   
    }

    for(int i = 1; i < s.size(); i++){
        if( s[i - 1] == 'B' && s[i] == 'A'){
            ba = i;
            break;
        }   
    }

    for(int i = ab + 2; i < s.size(); i++){
        if( s[i - 1] == 'B' && s[i] == 'A'){
            cout << "YES" << endl;
            return;
        }   
    }

    for(int i = ba + 2; i < s.size(); i++){
        if( s[i - 1] == 'A' && s[i] == 'B'){
            cout << "YES" << endl;
            return;
        }   
    }

    cout << "NO" << endl;



}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}