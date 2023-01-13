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
    string s;
    unordered_set<char> bad;
    cin >> s;
    string good;
    cin >> good;
    int tol;
    cin >> tol;
    FO(i, 26){
        if(good[i] == '0'){
            bad.insert(i+'a');
        }
    }
    long long sol = 0;
    for(int size = 1; size <= s.size(); size++){
        int start = 0;
        int end = -1;
        int badc = 0;
        unordered_set<string> sizeSet;

        while(end - start + 1 < size){
            end++;
            if(bad.count(s[end]))
                badc++;
            
        }
        while(end < s.size()){
            if(badc <= tol){
                string ss = s.substr(start, size);
                sizeSet.insert(ss);
            }
            start++;
            end++;
            if(bad.count(s[start - 1]))
                badc--;
            if(bad.count(s[end]))
                badc++;
        }
        sol += sizeSet.size();
    }
    cout << sol << endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}