#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
int l2[MAXN];

void build(vector<vector<pair<int, int>>> &ans, int begin, int k)
{
    for (int i = 1; i < k; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            vector<pair<int, int>> cmp;
            for (int l = 0; l < (1 << k); l += (1 << j))
            {
                for (int m = 0; m < (1 << (j - 1)); ++m)
                {
                    if (((l + m) / (1 << i)) & 1)
                    {
                        cmp.emplace_back(begin + l + m, begin + l + m + (1 << (j - 1)));
                    } else
                    {
                        cmp.emplace_back(begin + l + m + (1 << (j - 1)), begin + l + m);
                    }
                }
            }
            ans.push_back(cmp);
        }
    }
}

void Sort(vector<vector<pair<int, int>>> &ans, int l, int r)
{
    for (int i = 13; i >= 0; --i)
    {
        vector<int> vis(r, 0);
        vector<pair<int, int>> cmp;
        for (int j = l; j < r; ++j)
        {
            if (vis[j])continue;
            if (j + (1 << i) < r)
            {
                vis[j + (1 << i)] = true;
                cmp.emplace_back(j, j + (1 << i));
            }
        }
        if (!cmp.empty())
        {
            ans.push_back(cmp);
        }
    }
}

void Reverse(vector<vector<pair<int, int>>> &ans, int l, int r)
{
    vector<pair<int, int>> cmp;
    for (int i = 0; l + i < r - i - 1; ++i)
    {
        cmp.emplace_back(r - i - 1, l + i);
    }
    ans.push_back(cmp);
}

int main(int argc, char *argv[])
{
    l2[1] = 0;
    for (int i = 2; i <= 10000; ++i)
    {
        l2[i] = l2[i >> 1] + 1;
    }
    vector<vector<pair<int, int>>> op;

    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("0\n");
        return 0;
    }

    if ((n & (-n)) == n)
    {
        build(op, 0, l2[n]);
        Sort(op, 0, n);
    } else
    {
        build(op, 0, l2[n]);
        Sort(op, 0, (1 << l2[n]));
        Reverse(op, 0, (1 << l2[n]));
        build(op, n - (1 << l2[n]), l2[n]);
        Sort(op, n - (1 << l2[n]), n);
        Sort(op, 0, n);
    }

    printf("%d\n", (int) op.size());
    for (auto &it: op)
    {
        printf("%d", (int) it.size());
        for (auto &i: it)
        {
            printf(" %d %d", i.first, i.second);
        }
        printf("\n");
    }
    return 0;
}