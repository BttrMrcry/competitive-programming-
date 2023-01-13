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
    string s;
    cin >> s;
    int m[26] = {};
    
    for(char& c: s){
        m[c-'A'] += 1;
    }

    int sz = 0;
    int imp = 0;
    FO(i, 26){
        if(m[i] % 2){
            if(!imp)
                imp = 1;
            else{
                cout << "NO SOLUTION" << endl;
                return;
            }
        }
        sz += m[i];
    }

    string res(sz, '*');
    
    int l = 0, r = sz - 1; 
    
    FO(i, 26){
        if(m[i] % 2){
            res[sz/2] = i + 'A';
        }

        int toinsert = m[i] / 2;
        FO(j, toinsert){
            res[l] = i + 'A';
            res[r] = i + 'A';
            l++;
            r--;
        }
    }

    cout << res << endl;




}

int main() {
    if(getenv("CP_IO")) setIO();
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}