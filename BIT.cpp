#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BIT
{
public:
    vector<T> tree;
    int maxval;
    BIT(int n, int initial_val) {
        tree = vector<T>(n+1, initial_val);
        maxval = n;
    }

    void todo(T a, T b) {     //can be modified accordingly
        return a + b;
    }

    void build(vector<T> a) {                 // 1 based indexing 
        for(int i = 1; i <= maxval; i++) {
            int idx = i;
            while(idx <= maxval) {
                tree[idx] = todo(tree[idx],a[i]);
                idx += (idx & -idx);
            }
        }
    }

    void update(int idx , T val) {
        assert(idx > 0);
        while(idx <= maxval) {
            tree[idx] = todo(tree[idx],val);
            idx += (idx & -idx);
        }
    }

    T get(int idx) {
        assert(idx > 0);
        T res = 0;
        while(idx > 0) {
            res = todo(res, tree[idx]);
            idx -= (idx & -dx); 
        }  
    } 
};