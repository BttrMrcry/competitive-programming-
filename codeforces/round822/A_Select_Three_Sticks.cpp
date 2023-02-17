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
    vector<ll> nums(n); 
    FO(i, n){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    ll minMov = INT_MAX;
    for(int i = 2; i < n; i++){
        ll median = nums[i - 1];
        ll v = abs(median - nums[i]) + abs(median - nums[i - 1]) + abs(median - nums[i - 2]);
        minMov = min(v, minMov);
    }
    cout  << minMov << endl;
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