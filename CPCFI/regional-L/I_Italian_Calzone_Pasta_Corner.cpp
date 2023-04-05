#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long
#define MP(a, b)              make_pair(a, b)

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



int r, c, lim = 0;
array<array<int, 100>, 100>  m = {0};
array<pair<int, int>, 4> a = {MP(1, 0), MP(-1, 0), MP(0, 1), MP(0, -1)};

bool isValid(const int ri, const int ci, const array<array<bool, 100>, 100> &v, const int lim){
    if(ri >= r || ri < 0 || ci >= c || ci < 0 || v[ri][ci] || m[ri][ci] < lim)
        return false;
    return true;
}

//busqueda
int busqueda(const int ri, const int ci){
    int ans = 0;
    array<array<bool, 100>, 100> v = {0}; 
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; 
    v[ri][ci] = true;
    pq.push({m[ri][ci],{ri, ci}});
    while(!pq.empty()){
        auto curVal = pq.top().first;
        auto curPos = pq.top().second;
        pq.pop();
        lim = curVal;
        ans++;
        for(const pair<int, int> &d: a){
            int nr = curPos.first + d.first;
            int nc = curPos.second + d.second;
            if(isValid(nr, nc, v, lim)){
                pq.push({m[nr][nc], {nr, nc}});
                v[nr][nc] = true;
            }
        }
    }
    return ans;

}


inline void solve() {
    int ans = 0;
    cin >> r >> c;
    FO(i, r){
        FO(j, c){
            cin >> m[i][j];
        }
    }
    FO(i, r){
        FO(j, c){
            ans = max(busqueda(i, j), ans);
        }
    }
    cout << ans << endl;
    
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}