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
    ll n;
    cin >> n;
    int l = 1, r = n*n;
    int a[55][55];

    for(int i = 0; i < n; i++){
        if(i % 2){
            for(int j = n - 1; j >= 0; j--){
                if(j % 2){
                    a[i][j] = l;
                    l++;
                }else{
                    a[i][j] = r;
                    r--;
                }
            }
        }else{
            for(int j = 0; j < n; j++){
                if(j % 2){
                    a[i][j] = r;
                    r--;
                }else{
                    a[i][j] = l;
                    l++;
                }
            }
        }
    }

    FO(i, n){
        FO(j, n){
            cout << a[i][j] << " ";
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

n = 4
//  4 1 3 2
3 2 1


5 1 4 2 3
4 3 2 1 


9

9 1 8    {8, 7, 5, 4, 2, 1, 3, 6} 
2 7 3
6 4 5


 {15, 14, 13, 11, 10, 9, 7, 6, 5, 3, 2, 1}

{12, 8, 4}

16 1 15 2
14 3 13 4
12 5 11 6 
10 7 9 8 



