#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x)
#define pll(x)          printf("%lld\n", x)
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define all(x)          x.begin(), x.end()

typedef vector<int> vi;
typedef vector<long long> vll;

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
    long long n;
    cin >> n;
    if(n == 1){
        cout << "NO" << endl;
        return;
    }


    long long sum = n*(n+1)/2;
    if(sum % 2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if(n % 2){
        int l = 1;
        int r = n - 1;
        cout << n / 2 + 1 << endl;
        while(l < r){
            cout << l <<" "<< r << " ";
            l += 2;
            r -= 2;
        }
        cout << endl;
        cout << n / 2 << endl;
        l = 2;
        r = n - 2;
        while(l < r){
            cout << l <<" "<< r << " ";
            l += 2;
            r -= 2;
        }
        cout << n << endl;

    }else{
        int l = 1;
        int r = n;
        cout << n / 2 << endl;
        while(l < r){
            cout << l <<" "<< r <<" ";
            l += 2;
            r -= 2;
        }
        cout << endl;
        cout << n / 2 <<endl;
        l = 2;
        r = n - 1;
        while(l < r){
            cout << l <<" "<< r << " ";
            l += 2;
            r -= 2;
        }
    }
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}