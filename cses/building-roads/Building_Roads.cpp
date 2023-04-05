#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long
#define MAX_N           100005

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

void bfs(vector<vector<int>> &g, array<bool, MAX_N> &v, int o){
    queue<int> tovisit;
    tovisit.push(o);
    while(!tovisit.empty()){
        int cur = tovisit.front();
        tovisit.pop();
        v[cur] = true;
        for(int c : g[cur]){
            if(v[c])
                continue;
            else
                tovisit.push(c);
        }
    }
}


inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    array<bool, 100005> v = {false};
    FO(i, m){
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    
    vector<int> joins;
    FO(i, n){
        if(v[i]){
            continue;
        }else{
            joins.push_back(i);
            bfs(g, v, i);
        }
    }
    cout << joins.size() - 1 << endl;
    for(int i = 1; i < joins.size(); i++){
        cout <<joins[i - 1] + 1 << " "<< joins[i] + 1 << endl;
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