
template <typename T>
class SegTree
{
private:
    int __st, __end, val;
    T *tree, *lazy;
    void merge(T &c, T l, T r) //modify accordingly now it is for sum change push and update also
    {
        c = l + r;
        return;
    }
    void _build(vector<T> &a, int st, int end, int node)
    {
        if (st == end)
        {
            tree[node] = a[st];
            return;
        }
        int mid = (st + end) / 2;
        _build(a, st, mid, 2 * node),_build(a, mid + 1, end, 2 * node + 1);
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }
    void push(int node, int st, int mid, int end) // now for sum change accordingly for max and min
    {
        tree[node * 2] += lazy[node] * (mid - st + 1), lazy[node * 2] += lazy[node];
        tree[node * 2 + 1] += lazy[node] * (end - mid), lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
    void _update(int pos, T val, int st, int end, int node)
    {
        if (st == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (st + end) / 2;
        if (mid < pos) _update(pos, val, mid + 1, end, 2 * node + 1);
        else _update(pos, val, st, mid, 2 * node);
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }
    void __update(int L, int R, T val, int st, int end, int node)
    {
        if (L > R || st > R || end < L) return;
        if (L <= st && end <= R)
        {
            tree[node] += val * (end - st + 1), lazy[node] += val;  // now for sum change accordingly for max and min
            return;
        }
        int mid = (st + end) / 2;
        push(node, st, mid, end);
        __update(L, R, val, st, mid, 2 * node), __update(L, R, val, mid + 1, end, 2 * node + 1);
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }
    T _query(int L, int R, int st, int end, int node)
    {
        if (st > R || end < L)  return 0;  // for sum return 0;
        if (st >= L && end <= R) return tree[node];
        int mid = (st + end) / 2;
        push(node, st, mid, end); T ans;
        merge(ans, _query(L, R, st, mid, 2 * node), _query(L, R, mid + 1, end, 2 * node + 1));
        return ans;
    }
public:
    SegTree(int _st, int _end, T val)
    {
        __st = _st, __end = _end;
        tree = new T[4 * __end + 10], lazy = new T[4 * __end + 10];
        for (int i = 0; i < 4 * __end + 10; i++)
            tree[i] = val, lazy[i] = 0;
    }

    ~SegTree() { delete[] tree, delete[] lazy; }

    void bulid(vector<T> &a) { _build(a, __st, __end, 1); }

    void update(int pos, T val) { _update(pos, val, __st, __end, 1); }

    void updateRange(int L, int R, T val) { __update(L, R, val, __st, __end, 1); }

    T query(int L, int R) { return _query(L, R, __st, __end, 1); }
};
