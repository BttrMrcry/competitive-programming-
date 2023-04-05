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
string s;
cin >> n;
cin >> s;

int cnt = 0;
int cur = 0;
for(int i = 0; i < n; i++){
    if(s[i] == 'a'){
        cur++;
    }else if(s[i] == 'b'){
        if(cur > 1)
            cnt += cur;
        cur = 0;
    }
}
if(cur > 1)
    cnt += cur;

cout << cnt << endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}