template<typename T>
class BIT
{
public:
    vector<T> tree;
    int N;
    BIT(int n, int initial_val) {
        tree = vector<T>(n + 1, initial_val);
        N = n;
    }

    T todo(T a, T b) {
        return a + b;
    }

    void build(vector<T> a) {
        for (int i = 1; i <= N; i++) {
            int idx = i;
            for (;idx <= N; idx += idx & (-idx))
                tree[idx] = todo(tree[idx], a[i]);
        }
    }

    void update(int idx, T val) {
        for (; idx <= N; idx += idx & (-idx))
            tree[idx] = todo(tree[idx], val);
    }

    T get(int idx) {
        T res = 0;
        for (; idx > 0; idx -= idx & (-idx))
            res = todo(res, tree[idx]);
        return res;
    }
};
