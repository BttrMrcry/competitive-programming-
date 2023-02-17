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
    string size1, size2;
    cin >> size1 >> size2;
    
    int x1 = 0;
    int x2 = 0;
    int s1, s2;
    
    for(auto c : size1){
        if(c == 'X'){
            x1 += 1;
        }else{
            s1 = c;
        }
    }
    
    for(auto c : size2){
        if(c == 'X'){
            x2 += 1;
        }else{
            s2 = c;
        }
    }

    if(s1 > s2){
        cout << "<" << endl;
        return;
    }else if(s1 < s2){
        cout << ">" << endl;
        return;
    }else if(s1 == 'S' && x1 > x2){
        cout << "<" << endl;
    }else if(s1 == 'S' && x1 < x2){
        cout << ">" << endl;
    }else if(s1 == 'L' && x1 > x2){
        cout << ">" << endl;
    }else if(s1 == 'L' && x1 < x2){
        cout << "<" << endl;
    }else{
        cout << "=" << endl;
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