const int mod = 1e9 + 7;
const int N = 410;
int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
int sub(int a, int b) { return (((a - b) % mod) + mod) % mod; }
int add(int a, int b) { return ((a + b) % mod); }

int power(int x, int y, int M)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return res % M;
}
int mi(int x) { return power(x, mod - 2, mod); }
int fac[N + 1];
int invfac[N + 1];

void pre()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= N; i++)
        fac[i] = mul(i, fac[i - 1]);
    invfac[N] = mi(fac[N]);
    for (int i = N - 1; i > 0; i--)
        invfac[i] = mul(invfac[i + 1], i + 1);
    invfac[0] = 1;
    p2[0] = 1;
    for (int i = 1; i <= N; i++)
        p2[i] = mul(p2[i - 1], 2);
}

int nCr(int x, int r)
{
    if (x < r)
        return 0;
    return (fac[x] * ((invfac[r] * invfac[x - r]) % mod)) % mod;
}
