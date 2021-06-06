const int mod = 1e9 + 7, N;
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
vi fac;
void pre()
{
  fac[0] = fac[1] = 1;
   for(int i = 2;i<=N;i++)
      fac[i] = mul(i,fac[i-1]);
}

int nCr(int x, int r)
{
    if (x < r)
        return 0;
    return (fac[x] * ((mi(fac[r]) * mi(fac[x - r])) % mod)) % mod;
}
