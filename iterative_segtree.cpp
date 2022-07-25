
template <typename T, class F = function<T(const T&, const T&)>>
class SegTree {
    int n;
    T VAL;
    vector<T> tree;
    F todo;
public:
    SegTree(int n, int VAL, const F& todo) {
        this->n = n;
        this->VAL = VAL;
        tree.assign(2*n+2, VAL);
        this->todo = todo;
    }
    void update(int i, T x) {
        for(tree[i += n] = x; i > 1; i >>= 1)
            tree[i >> 1] = todo(tree[i], tree[i^1]);
    }
    T get(int l, int r) {
        T res = VAL;
        for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = todo(res, tree[l++]);
            if(r & 1) res = todo(res, tree[--r]);
        }
        return res;
    }
};
