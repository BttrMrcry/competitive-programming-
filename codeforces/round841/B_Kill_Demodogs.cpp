#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
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
    unsigned long long n;
    cin >> n;
    unsigned long long f = n * (n + 1) % MODC;
    unsigned long long c = (4 * n - 1) % MODC;
    unsigned long long s= f*c*2022/6 % MODC;
    cout << s << endl;
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

/*
  1 2 3 4
1 1 2 3 4
2 2 4 6 8
3 3 6 9 12
4 4 8 12 16 20
*/

/*
1*2+2*3+3*4

N*(N-1)= N^2-N
 1^2-1 + 2^2-2 + 3^2-3
*/


