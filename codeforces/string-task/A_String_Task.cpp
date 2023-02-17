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
    bool vowels[26] = {0};
    vowels['a' - 'a'] = 1;
    vowels['o' - 'a'] = 1;
    vowels['y' - 'a'] = 1;
    vowels['e' - 'a'] = 1;
    vowels['u' - 'a'] = 1;
    vowels['i' - 'a'] = 1;
    
    string input;
    cin >> input;
    for(auto c: input){
        c = tolower(c);
        if(vowels[c-'a']){
            continue;
        }
        cout <<'.';
        cout<<c;
    }
    cout << endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}