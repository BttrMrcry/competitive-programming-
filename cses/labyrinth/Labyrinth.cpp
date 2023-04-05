#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long
#define MK(a, b)              make_pair(a, b)

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

int n, m;
array<array<char, 1000>, 1000> l = {'.'};
array<array<bool, 1000>, 1000> v = {false};
array<pair<int, int>, 4> dir = {MK(1, 0), MK(-1, 0), MK(0, 1), MK(0, -1)};
bool isValid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m ||v[i][j] ||l[i][j] == '#' ){
        return false;
    }
    return true;
}


deque<char> parSol;
deque<char> sol;
int cs = INT_MAX;
void dfs(int i, int j, int h){
    if(h >= cs){
        parSol.pop_back();
        return;
    }

    if(!isValid(i, j)){
        parSol.pop_back();
        return;
    }
    //cerr << l[i][j] << endl;
    

    if(l[i][j] == 'B'){
        if(parSol.size() < cs){
            sol = parSol;
            cs = parSol.size();
        }
        parSol.pop_back();
        return;
    }
    v[i][j] = true;

    for(const auto &d: dir){
        auto nexti = i + d.first;
        auto nextj = j + d.second;
        if(d == MK(1, 0)){
            parSol.push_back('D');
            dfs(nexti, nextj, h + 1);
        }else if(d == MK(-1, 0)){
            parSol.push_back('U');
            dfs(nexti, nextj, h + 1);
        }else if(d == MK(0, 1)){
            parSol.push_back('R');
            dfs(nexti, nextj, h + 1);
        }else{
            parSol.push_back('L');
            dfs(nexti, nextj, h + 1);
        } 
    }
    parSol.pop_back();
    v[i][j] = false;
}


inline void solve() {

    cin >> n >> m;

    FO(i, n){
        FO(j, m){
            cin >> l[i][j];
            //cerr << l[i][j];
        }
        //cerr << endl;
    }

    FO(i, n){
        FO(j, m){
            if(l[i][j] == 'A'){
                dfs(i, j, 0);
                break;
            }
        }
    }

    if(cs == INT_MAX)
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << cs << endl;
        for(auto e: sol){
            cout << e;
        }
        cout << endl;
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