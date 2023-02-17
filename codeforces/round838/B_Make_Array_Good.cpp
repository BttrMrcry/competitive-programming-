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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> nums(n);
    FO(i, n){
        cin >> nums[i].first;
        nums[i].second = i + 1;
    }

    sort(nums.begin(), nums.end());

    ll multi = nums[0].first;
    cout << n << endl;
    FO(i, n){
        ll nextmul = ((nums[i].first - 1) / multi + 1) * multi;
        cout << nums[i].second << " " << nextmul - nums[i].first << endl;
        multi = nextmul; 
    }
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