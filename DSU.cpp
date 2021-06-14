class DSU
{
private:
    int *rank, *parent, n;

public:
    DSU(int n = 1) : n(n)
    {
        rank = new int[n + 1], parent = new int[n + 1];
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a), b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    ~DSU()
    {
        delete[] rank, delete[] parent;
    }
};