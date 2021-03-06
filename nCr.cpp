const int N = 1e5;
const int mod = 1e9 + 7;
int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
int sub(int a, int b) { return (((a - b) % mod) + mod) % mod; }
int add(int a, int b) { return ((a + b) % mod); }

int power(int x, int y)
{
    int res = 1;
    for (; y > 0; x = (x * x) % mod, y >>= 1)
        if (y & 1) res = (res * x) % mod;
    return res;
}
int mi(int x) { return power(x, mod - 2); }
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
}

int nCr(int x, int r)
{
    if (x < r)
        return 0;
    return (fac[x] * ((invfac[r] * invfac[x - r]) % mod)) % mod;
}
