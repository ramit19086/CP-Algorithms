#include <bits/stdc++.h>

using namespace std;
template <typename T>
class SegTree // 1 indexed segment tree
{
private:
    // vector<T> lazy_tree; //use only if needed
public:
    int n, val;
    vector<T> tree;
    SegTree(int _n, T val)
    {
        n = _n;
        tree = vector<T>(4 * n + 10, val);
    }

    void merge(T &c, T l, T r) //modify accordingly now it is for sum
    {
        c = l + r;
        return;
    }

    void build(vector<T> &a, int st, int end, int node = 1)
    {
        if (st == end)
        {
            tree[node] = a[st];
            return;
        }
        int mid = (st + end) / 2;
        build(a, st, mid, 2 * node);
        build(a, mid + 1, end, 2 * node + 1);
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }

    void update(int pos, T val, int st, int end, int node = 1)
    {
        if (st == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (st + end) / 2;
        if (mid < pos)
            update(pos, val, mid + 1, end, 2 * node + 1);
        else
            update(pos, val, st, mid, 2 * node);
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }

    //make range update query accordingly if you want

    T query(int l, int r, int st, int end, int node = 1)
    {
        if (st > r || end < l)
            return 0; //handle accordingly for sum we return 0 in this case
        if (st >= l && end <= r)
            return tree[node];
        int mid = (st + end) / 2;
        T ans;
        merge(ans, query(l, r, st, mid, 2 * node), query(l, r, mid + 1, end, 2 * node + 1));
        return ans;
    }
};