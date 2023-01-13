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


inline void solve() {
    int n;
    cin >> n;

    if(n == 3){
        cout << "NO" << endl;
    }else if (n % 2){
        int x = n/2;
        int y = -n/2 + 1; 
        cout << "YES" << endl;
        FO(i, n){
            if(i % 2){
                cout << x << " ";
            }else{
                cout << y << " ";
            }
            
        }

    } else{
        cout <<"YES"<< endl;
        FO(i, n){
            if(i % 2){
                cout << -1 << " ";
            }else{
                cout << 1 << " ";
            }
            
        }
        cout << endl;

    }
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 0;
    cin >> T;
    FO(tc, T){
        solve();
    }
    return 0;
}