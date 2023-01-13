#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long

//math Functions
long long gcd(long long a, long long b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}  

long long mcd(long long a, long long b){
    return a/gcd(a, b)*b;
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
    long long n, m;
    cin >> n >> m; 
    priority_queue<long long, vector<long long>, greater<long long>> small;
    long long sum = 0;
    
    FO(i, n){
        long long num;
        cin >> num;
        small.push(num);
        sum += num;
    }

    FO(i, m){
        long long num = small.top();
        small.pop();
        int num1;
        cin >> num1;
        sum -= num;
        sum += num1;
        small.push(num1);
    }
    
    cout << sum << endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T;
    cin >> T;
    FO(tc, T){
        solve();
    }
    return 0;
}