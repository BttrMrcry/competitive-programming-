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
    vector<int> num(n);

    
    FO(i, n){
        cin >> num[i];
    }
    int onedif = 0;
    int last = num[0];    
    
    FO(i, n){
        if(num[i] != last){
            onedif = 1;
        
        }
        last = num[i];
    }

    if(onedif == 1){
        cout << "YES" << endl;
        sort(num.begin(), num.end(), greater<>());
        if(num[0] == num[1]){
            for(int i = 1; i < n; i++){
                if(num[i-1] != num[i]){
                    swap(num[0], num[i]);
                }
            }
        }
        FO(i, n){
            cout << num[i] << " ";
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
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

