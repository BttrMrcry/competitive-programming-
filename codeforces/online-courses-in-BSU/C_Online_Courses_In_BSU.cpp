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

vector<int> importants, visited, counted;
vector<list<int>> g;
list<int> sol;

void dfs(int cur){
    if(counted[cur])
        return;
    if(visited[cur]){
        cout << -1 << endl;
        exit(0);
    }
    visited[cur] = 1;
    for(auto v : g[cur]){
        dfs(v);
    }
    sol.push_back(cur + 1);
    counted[cur] = 1;
}



inline void solve() {
    int n, k;
    cin >> n >> k;
    importants.resize(k);
    visited.resize(n);
    counted.resize(n);
    g.resize(n);
    
    FO(i, k){
        cin >> importants[i];
        importants[i] -= 1;
    }

    FO(i, n){
        int depen;
        cin >> depen;
        FO(j, depen){
            int prev;
            cin >> prev;
            g[i].push_back(prev - 1);
        }
    }

    for(auto x : importants){
        if(!visited[x])
            dfs(x);
    }

    cout << sol.size() << endl;
    for(auto e: sol){
        cout << e << " ";
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