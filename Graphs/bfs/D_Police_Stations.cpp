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
    ll n, k, d;
    cin >> n >> k >> d;
    vector<vector<pair<int, int>>> g(n);
    queue<int> cities;
    FO(i, k){
        int city;
        cin >> city;
        cities.push(city - 1);
    }

    FO(i, n - 1){
        int ori, des;
        cin >> ori >> des;
        g[ori].push_back({des - 1, i});
        g[des].push_back({ori - 1, i});
    }

    while(cities.empty()){
        
    }
    
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}