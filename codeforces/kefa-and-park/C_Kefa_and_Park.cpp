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

int sol = 0;
int m;
bitset<100000> visited = {0}; 

void dfs(int cur, int maxCur, bitset<100000> &cat, vector<list<int>> &g){
    if(visited[cur])
        return;

    visited[cur] = true;


    if(cat[cur]){
        maxCur++;
    }else{
        maxCur = 0;
    }
    //cout <<"maxCur: "<< maxCur <<" cur: "<< cur << endl;

    if(maxCur > m){
        return;
    }

    if(g[cur].size() == 1 && cur != 0){
        sol += 1;
        return;
    }

    for(auto v : g[cur]){
        dfs(v, maxCur, cat, g);
    }

}

inline void solve() {
    int n;
    cin >> n >> m;
    vector<list<int>> g(n);
    bitset<100000> cat = {0};

    FO(i, n){
        bool num;
        cin >> num;
        cat[i] = num;
    }

    FO(i, n - 1){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    // for(auto r: g){
    //     for(auto c:r){
    //         cout << c << " ";
    //     }
    //     cout<<endl;
    // }

    dfs(0, 0, cat, g);

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