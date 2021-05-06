#include <bits/stdc++.h>
using namespace std;

template <typename T>
class RMQ
{
public:
    int n, k;
    vector<vector<T>> ans;
    vector<int> myLog;
    //Takes any of the idempotent function
    //for example min in this case                     (IF YOU WANT TO USE SUM MODIFY THE TODO AND QUERY ACCORDINGLY)
    T todo(T a, T b)
    {
        return min(a, b);
    }

    // /USEFUL AS NO ACCURACY ERRORS FOR OUR USE CASE AND FAST ALSO
    void computeLog(int n)
    {
        myLog.resize(n + 1);
        myLog[1] = 0;
        for (int i = 2; i < n; i++)
            myLog[i] = myLog[i / 2] + 1;
    }

    RMQ(vector<T> &a)
    {
        n = a.size();
        computeLog(n);
        k = myLog[n] + 1;
        init(a);
    }

    void init(vector<T> &a)
    {
        ans.resize(n);
        for (int i = 0; i < n; i++)
            ans[i].resize(k);
        for (int i = 0; i < n; i++)
            ans[i][0] = a[i];
        int temp = 1;
        for (int j = 1; j <= k; j++)
        {
            temp <<= 1;
            for (int i = 0; i + temp <= n; i++)
                ans[i][j] = todo(ans[i][j - 1], ans[i + temp / 2][j - 1]);
        }
    }

    //modify the query accordingly
    T query(int L, int R)
    {
        int j = myLog[R - L + 1];
        return todo(ans[L][j], ans[R - (1 << j) + 1][j]);

        //In case of sum use this 
        // long long sum = 0;
        // for (int j = k; j >= 0; j--)
        // {
        //     if ((1 << j) <= R - L + 1)
        //     {
        //         sum += ans[L][j];
        //         L += 1 << j;
        //     }
        // }
    }
};
