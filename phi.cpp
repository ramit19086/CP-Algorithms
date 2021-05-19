#include<bits/stdc++.h>
using namespace std;
const int mxn = 4e6 + 20;
int phi[mxn + 1];
int ans[mxn + 1];
bool is_composite[mxn + 1];

void pre()
{
    vector<int> prime;
    for (int i = 2; i <= mxn; i++)
    {
        if (!is_composite[i])
        {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= mxn; j++)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
            phi[i * prime[j]] = (prime[j] - 1) * phi[i];
        }
    }
}