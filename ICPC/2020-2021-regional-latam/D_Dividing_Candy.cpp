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

set<int> s;
void merge(int num){
    if(s.count(num)){
        s.erase(num);
        merge(num + 1);
    }else{
        s.insert(num);
    }
}

void solve() {
    
    int n; cin >> n;
    if(n==1) {
        cout << "N" << endl;
        return;
    }
    FO(i,n){
        int num; cin >> num;
        merge(num);
    }
 
    if(s.size()<=2) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
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