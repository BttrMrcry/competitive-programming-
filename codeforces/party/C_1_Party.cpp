#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long


struct UnionFindNode {
    UnionFindNode* parent;
    long long size;
    bool valid;

    UnionFindNode(){
        parent = this;
    }

    UnionFindNode* find(){
        if(parent == this){
            return this;
        }else{
            return parent = parent->find();
        }
    }

    UnionFindNode* unionSets(UnionFindNode* other){
        UnionFindNode* set1 = this->find();
        UnionFindNode* set2 = other->find();

        if(set1 == set2){
            return set1;
        }else{
            if(set2->size > set1->size){
                swap(set1, set2);
            }
            set2->parent = set1;
            set1->size += set2->size;
            return set1;
        }
    }
};


void dfs(int cur, int parent, vector<vector<int>> &g, vector<bool> &visited, vector<UnionFindNode> &nodes){
    if(visited[cur])
        return;

    visited[cur] = true;
    if(parent != -1){
        nodes[cur].unionSets(&nodes[parent]);
    }
    
    for(auto v : g[cur]){
        dfs(v, cur, g, visited, nodes);
    }
}


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
    int n, k, m;
    cin >> n;
    vector<vector<int>> g(n);
    cin >> k;
    FO(i, k){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    vector<UnionFindNode> nodes(n);
    vector<bool> visited(n, false);
    
    FO(i, n){
        if(!visited[i])
            dfs(i, -1, g, visited, nodes);
    }

    cin >> m;


    FO(i, m){
        int u, v;
        cin >> u >> v;
        if(nodes[u - 1].find() == nodes[v - 1].find()){
            nodes[u - 1].find() -> valid = false;
        }
    }

    ll sol = 0;
    for(auto &node: nodes){
        if(&node == node.find() && node.valid)
            sol = max(sol, node.size);
    }

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