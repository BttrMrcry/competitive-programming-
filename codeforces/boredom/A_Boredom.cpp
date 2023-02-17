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
    array<ll, 100002> nums = {0};
    array<ll, 100002> mem = {0};
    cin >> n;

    FO(i, n){
        int num;
        cin >> num;
        nums[num] += 1;
    }
    mem[0] = 0;
    mem[1] = nums[1];
    for(int i = 2; i <= 100000; i++){
        mem[i] = max(mem[i-1], mem[i - 2]+nums[i]*i);
        //cout << mem[i] << endl;
    }
    cout << mem[100000] << endl;


}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}