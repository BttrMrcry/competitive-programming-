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

class SegmentTreeMax {         // the segment tree is stored like a heap array
    private: 
        vi st, A;            // recall that vi is: typedef vector<int> vi;
        int n;
        int left (int p) { return p << 1; }     // same as binary heap operations
        int right(int p) { return (p << 1) + 1; }

        void build(int p, int L, int R) {                           // O(n log n)
            if (L == R)                            // as L == R, either one is fine
                st[p] = L;                                         // store the index
            else {                                // recursively compute the values
                build(left(p), L, (L + R) / 2);
                build(right(p), (L + R) / 2 + 1, R);
                int p1 = st[left(p)], p2 = st[right(p)];
                st[p] = A[p1] > A[p2] ? p1 : p2;
            }
        }

        int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
            if (i >  R || j <  L) return -1; // current segment outside query range
            if (L >= i && R <= j) return st[p];               // inside query range

            // compute the min position in the left and right part of the interval
            int p1 = rmq(left(p) , L              , (L+R) / 2, i, j);
            int p2 = rmq(right(p), (L+R) / 2 + 1, R          , i, j);

            if (p1 == -1) return p2;   // if we try to access segment outside query
            if (p2 == -1) return p1;                               // same as above
            return A[p1] > A[p2] ? p1 : p2; // as as in build routine
        }          

        int update_point(int p, int L, int R, int idx, int new_value) {
            // this update code is still preliminary, i == j
            // must be able to update range in the future!
            int i = idx, j = idx;

            // if the current interval does not intersect 
            // the update interval, return this st node value!
            if (i > R || j < L)
            return st[p];

            // if the current interval is included in the update range,
            // update that st[node]
            if (L == i && R == j) {
                A[i] = new_value; // update the underlying array
                return st[p] = L; // this index
            }

            // compute the minimum pition in the 
            // left and right part of the interval
            int p1, p2;
            p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
            p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

            // return the pition where the overall maximum is
            return st[p] = (A[p1] > A[p2]) ? p1 : p2;
        } 

    public:
        SegmentTreeMax(const vi &_A) {
            A = _A; n = (int)A.size();              // copy content for local usage
            st.assign(4 * n, 0);            // create large enough vector of zeroes
            build(1, 0, n - 1);                                  // recursive build
        }

        int rmq(int i, int j) { 
            return rmq(1, 0, n - 1, i, j); // overloading
        }   

        int update_point(int idx, int new_value) {
            return update_point(1, 0, n - 1, idx, new_value); }
};



inline void solve() {
    int n;
    cin >> n;
    array<array<int, 3>, 100001> river = {0};
    vector<int> mem(100001, 0);
    FO(i, n){
        cin >> river[i][0] >>  river[i][1] >>  river[i][2];
        mem[i] = river[i][0];
    }

    SegmentTreeMax st(mem);

    int maxV = 0;
    
    for(int i = n - 1; i >= 0; i--){
        int maxJ = 0;
        int a = river[i][1] + i;
        int b = min(n-1, river[i][2] + i);
        if(a >= n)
            maxJ = -1;
        else
            maxJ = st.rmq(a, b);
        if(maxJ >= 0){       
            mem[i] = river[i][0] + mem[maxJ];
            st.update_point(i, mem[i]);
        }
        maxV = max(maxV, mem[i]);
    }
    
    
    cout << maxV << endl;

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}