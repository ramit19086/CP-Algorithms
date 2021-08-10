include <bits/stdc++.h>
using namespace std;
class DSU
{
private:
    int n;
    vector<int> rank, parent;
public:
    DSU(int n = 1) : n(n)
    {
        rank = vector<int>(n + 1), parent = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int Find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = Find(parent[v]);
    }

    bool Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b)
            return 0;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return 1;
    }
};
