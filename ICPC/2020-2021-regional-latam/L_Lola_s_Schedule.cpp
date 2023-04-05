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
x = 5
......xx.xx.xxxx.....x
00    1    1
inline void solve() {
    bitset<200010> act = {0};
    int n, x;
    cin >> n >> x;

    FO(i, n){
        int s, d;
        cin >> s >> d;
        for(int j = s; j < s + d + 1; j++){
            act[j] = true;
        }
    }   
    int minCo = INT_MAX; 
    int minIn = -1;
    for(int i = 0; i <= 480; i++){
        int co = 0;
        for(int j = i; j < 200010; j += x){
            
            if(act[j]){
                co++;
                //cout << j << endl;
            }
        }
        if(co < minCo){
            minCo = co;
            minIn = i;
        }
    }

    cout << minIn << " " << minCo << endl;

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}