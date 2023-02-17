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
    int w, d, h, a, b, f, g;
    
    cin >> w >> d >> h;
    cin >> a >> b >> f >> g;

    
    int minDis = INT_MAX; 
    //first case
    {
        int sol = a + h + f + abs(b - g);
        minDis = min(sol, minDis);
    }
    
    //Second case
    {
        int sol = (d-b) + h + (d - g) + abs(a - f);
        minDis = min(sol, minDis);
    }

    //third case 
    {
        int sol = (w-a) + h + (w - f) + abs(b - g); 
        minDis = min(sol, minDis);
    }

    //fourth 
    {
        int sol = b + h + g + abs(a- f);
        minDis = min(sol, minDis);
    }

    cout << minDis << endl;
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