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

void solve() {
    int t;
    scanf("%d",&t);
    pow(1,2);
    while(t--){
        long long y, x, res;
        cin >> y >> x;
        if(y == x){
            res = x*x - x + 1;
        }else if(y > x){
            //Si es impar, la numeración va de abajo a arriba
            if(y % 2){
                long long lastp = (y - 1) * (y - 1);
                res = lastp + x;
            //Si es par, la numeración va de arriba a abajo
            }else{
                res = y*y - x + 1;
            }
        }else{
            //Si es impar, la numeración va de abajo a arriba
            if(x % 2){
                res = x*x - y + 1;
            //Si es par, la numeración va de arriba a abajo
            }else{
                long long lastp = (x-1) * (x-1);
                res = lastp + y;
            }
        }
        printf("%lld\n",res);
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