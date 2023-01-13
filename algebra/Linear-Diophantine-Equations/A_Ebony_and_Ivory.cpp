#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long

//math Functions
long long gcd(long long a, long long b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int extended_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


long long mcd(long long a, long long b){
    return a/gcd(a, b)*b;
}


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
    int a, b, c, x, y;
    cin >> a >> b >> c;

    int g = extended_gcd(a, b, x, y);

    if(c % g)
        cout<<"No"<<endl;
    else{
        if(x >= 0 && y >= 0){
            cout << "Yes" << endl;
            return;
        }

        if(x <= 0 && y <= 0){
            cout << "No" << endl;
            return;
        }

         
        int x0 = x * c / g;
        int y0 = y * c / g;
        
        

        int k;
        if(x0 < 0){
            k = ceil(-(double)g * x0 / b);
        }
        
        if(y0 < 0){
            
            k = floor((double)g * y0 / a);
        }
        

        int x1 = x0 + k * b / g;
        int y1 = y0 - k * a / g;

        

        if(x1 >= 0 && y1 >= 0){
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
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