#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
const int N = 10005;
const int M = 21;
int a[N], dp[N][M][M][2], ml[N][M], tmp[M][M];
multiset<pair<int, int>> se;  //val,id
int n, k, m, sum, x, y, ls;

void ck_min(int& s, int t)
{
    s = min(s, t);
}

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    x = n / k;
    y = n % k;
    ls = min(m, k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        if (i >= k)
        {
            auto it = se.begin();
            for (int j = 0; j < ls; ++j)
            {
                ml[i][j] = it->first;
                ++it;
            }
        }
        if (i >= k)
        {
            auto it = se.find(make_pair(a[i - k], i - k));
            if (it != se.end())
            {
                se.erase(it);
            }
        }
        if (i != n)
        {
            se.insert(make_pair(a[i], i));
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int l = 0; l <= m; ++l)
            {
                dp[i][j][l][0] = dp[i][j][l][1] = INF;
            }
        }
    }
    /*
    cout<<"ml ----------------"<<endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < ls; ++j)
        {
            cout << ml[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"ml ----------------"<<endl;
    */
    dp[0][0][0][1] = 0;
    for (int i = 0; i < n; ++i)
    {
        auto ix = i / k;
        auto iy = i % k;
        if (iy > y)
            continue;
        //往右走
        if (iy != y)
        {
            for (int j = m; j >= 0; --j)
            {
                for (int l = m; l >= 0; --l)
                {
                    //不选，不交换
                    ck_min(dp[i + 1][j][l][0], dp[i][j][l][0]);
                    //不选，但是交换进来
                    if(l<20)
                    {
                        ck_min(dp[i + 1][j][l + 1][0], dp[i][j][l][0] + a[i]);
                    }
                    //选，交换
                    if (j != m)
                    {
                        ck_min(dp[i + 1][j + 1][l][1], dp[i][j][l][0]);
                        ck_min(dp[i + 1][j + 1][l][1], dp[i][j][l][1]);
                    }
                    //选，不交换
                    ck_min(dp[i + 1][j][l][1], dp[i][j][l][0] + a[i]);
                    ck_min(dp[i + 1][j][l][1], dp[i][j][l][1] + a[i]);
                }
            }
        }
        //往下走
        if (ix != x)
        {
            for (int j = m; j >= 0; --j)
            {
                for (int l = m; l >= 0; --l)
                {
                    tmp[j][l] = min(dp[i][j][l][0], dp[i][j][l][1]);
                }
            }
            //01背包辅助转移
            for (int it = 0; it < ls; ++it)
            {
                for (int j = m; j >= 0; --j)
                {
                    for (int l = m; l > 0; --l)
                    {
                        ck_min(tmp[j][l], tmp[j][l - 1] + ml[i + k][it]);
                    }
                }
            }
            for (int j = m; j >= 0; --j)
            {
                for (int l = m; l >= 0; --l)
                {
                    ck_min(dp[i + k][j][l][0], tmp[j][l]);
                    ck_min(dp[i + k][j][l][1], tmp[j][l]);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= m; ++i)
    {
        ck_min(ans, dp[n][i][i][1]);
    }
    printf("%d\n", sum - ans);
    return 0;
}
/*
11 3 0
-1 1 1 -1 1 1 1 1 -1 1 1

11 3 1
-1 1 1 -1 1 1 1 1 -1 1 1

11 3 5
9 8 7 6 5 8 4 6 5 4 8


13 7 1
75000  22054  -88232 0     45497 -71059 -84906
-53229 -94156 1818   61088 10621 2312   *


13 10 1
0    -2881 -56264 -9650 93472 0 25326 0 -44071 31625
-514 -86403 66977 *


13 10 1
0 -1 -1 1 1 1 1 1 1 1
1 -1 1 *


13 8 1
39453 0   89723 -31802 0 74015 -20161 48377 
0   28051 0     0      3914

17 10 1
63157 96056 87371 62549 0 19813 0 98091 39246 0 
45989 0 -49092 -51617 38294 63382 76711 *


17 10 1
63157 96056 87371 62549 0 19813 0 98091 39246 0 45989 0 -49092 -51617 38294 63382 76711
*/
