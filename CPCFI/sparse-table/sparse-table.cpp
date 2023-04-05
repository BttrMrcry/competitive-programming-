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

int log2_floor(unsigned long long n){
    if(n == 0)
        return -1;
    if(n == 1)
        return 0;

    int pos = 0;
    int res = 0;

    while(n != 0){
        if(n & 1){
            res = pos;
        }
        pos++;
        n = n >> 1;
    }
    return res;
}

int f(int a, int b){
    return min(a, b);
}

struct SparseTable {
    int N;
    int P;
    vector<vector<int>> dp;

    SparseTable(int N){
        this->N = N;
        this->P = log2_floor(N);
        dp = vector<vector<int>>(N, vector<int>(P));  
    }

    void build(const vector<int> &a){
        dp[0] = a;
        for(int p = 1; p <= this->P; p++){
             for (int i = 0; i + (1 << p) <= this->N; i++)
                dp[p][i] = f(dp[p - 1][i], dp[p - 1][i + (1 << (p - 1))]);
        }
    }

    int fast_query(unsigned int l, unsigned int r){
        return min(dp[P][l], dp[P][r - (1 << P) + 1]);
    }

    //For sum
    int log_query(unsigned int l, unsigned int r){
        long long res;
        int K = (1 << P);
        for (int p = K; p >= 0; p--) {
            if ((1 << p) <= r - l + 1) {
                res += dp[p][l];
            l += 1 << p;
        }
}       return res;
    }
};





inline void solve() {
    int N;
    cin >> N;
    int P = log2_floor(N);
    vector<vector<int>> dp(P, vector<int>(N));
    FO(i, N){
        cin >> dp[0][i];
    } 
    return;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}