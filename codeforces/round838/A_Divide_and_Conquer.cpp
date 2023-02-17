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
    int minm = INT_MAX;
    int odd = 0, even = 0;
    FO(i, n){
        int a;
        cin >> a;
        int c = 0;

        if(a % 2){
            odd++;
            while(a % 2){
                a = a/2;
                c++;
            }
            minm = min(minm, c);
        }else{
            while(a % 2 == 0 && a != 0){
                a = a/2;
                c++;
            }
            if(a != 0){
                minm = min(minm, c);
            }
        }


    }

    if(odd % 2){
        cout << minm << endl;
    }else{
        cout << "0" << endl;
    }
    
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    cin >> T;
    FO(tc, T){
        solve();
    }
    return 0;
}