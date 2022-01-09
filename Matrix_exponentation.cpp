typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi multiply_matrix(vvi a, vvi b)
{
    int n = a.size();
    vvi mul(n, vi(n));
    // O(n^3)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                mul[i][j] += a[i][k] * b[k][j];
    return mul;
}

vvi power(vvi a, int expo)
{
    int n = a.size();
    vvi mul(n, vi(n, 1));
    for (; expo > 0; expo >>= 1, a = multiply_matrix(a, a))
        if (expo & 1)
            mul = multiply_matrix(mul, a);
    return mul;
}
