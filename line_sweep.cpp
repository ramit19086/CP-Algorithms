#include<bits/stdc++.h>

using namespace std;

#define int long long
#define nl << "\n"

const int inf = 1e18;
// vvi points; 
vector<array<int, 3>> points; // better for time complexity 

int cross_product(array<int, 3> p1, array<int, 3> p2) { return p1[0] * p2[1] - p1[1] * p2[0]; }
int get_quad(array<int, 3> p)
{
    if (p[1] != 0)
        return p[1] > 0 ? 0 : 1;
    else
        return p[0] >= 0 ? 0 : 1;
}

bool cmp(array<int, 3> p1, array<int, 3> p2)
{
    int q1 = get_quad(p1), q2 = get_quad(p2);
    if (q1 != q2)
        return q1 < q2;
    return cross_product(p1, p2) > 0;
}

void solve()
{
    int n; cin >> n;
    points = vector<array<int, 3>>(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> points[i][j];
    int sum = 0;
    for(auto& i : points)
        sum += i[2];
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        array<int, 3> curr_point = points[i];
        vector<array<int, 3>> other;
        for (int j = 0; j < n; j++)
            if (j != i)
                other.push_back({ points[j][0] - points[i][0], points[j][1] - points[i][1], points[j][2] });
        sort(all(other), cmp);
        int upar = 0;
        for (int j = 0, l = 1; j < n - 1; j++)
        {
            upar = max(0LL, upar - other[j][2]);
            if (l == j)
                l = (l + 1) % (n - 1);
            while (l != j and cross_product(other[j], other[l]) > 0)
                upar += other[l][2], l = (l + 1) % (n - 1);
            ans = min(ans, abs(upar - (sum - upar - points[i][2] - other[j][2])));
        }
    }
    cout << ans nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
