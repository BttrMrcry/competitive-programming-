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



struct FenwickTree {
    int N;
    vector<long long> tree;
    
    FenwickTree(const vector<long long> values): tree(values){
        N = values.size();
        tree[0] = 0;
        for(int i = 1; i < N; i++){
            int parent = i + lsb(i);
            if(parent < N) tree[parent] += tree[i];
        }
    }

    static int lsb(int i){
        return i & -i;
    }

    long long prefixSum(int i){
        long long sum = 0;
        while(i != 0){
            sum += tree[i];
            i &= ~lsb(i);
        }
        return sum;
    }

    long long sum(int left, int right){
        return prefixSum(right) - prefixSum(left - 1);
    }

    long long get(int i) {
        return sum(i, i);
    }
    void add(int i, long v) {
        while (i < N) {
            tree[i] += v;
            i += lsb(i);
        }
    }

    void set(int i, long v) {
        add(i, v - sum(i, i));
    }
};

inline void solve() {
    vector<long long> values = {0,1,2,2,4};
    FenwickTree ft(values);
    cout << ft.sum(1, 4) << endl; // 9, sum all numbers in interval [1, 4] in O(log(n))
    ft.add(3, 1); // Adds +1 to index 3.

    cout << ft.sum(1, 4) << endl; // 10, sum all numbers in interval [1, 4]
    ft.set(4, 0); // Set index 4  to have value zero.

    cout << ft.sum(1, 4) << endl; // 6, sum all numbers in interval [1, 4]
    ft.get(2);    // 2, Get the value at index 2, this is the same as .sum(2, 2)


}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}