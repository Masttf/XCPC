#include<bits/stdc++.h>
using namespace std;
int dep[100010] = {0},a[100010];
int dfs(int x)
{
    if(dep[x] != 0)
    {
        return dep[x];
    }
    else return dep[x]=dfs(a[x])+1;
}
int main()
{
    ios::sync_with_stdio(false); 
    int n,d;
    cin >> n >> d;
    int f[n];
    for(int i = 0;i < n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        a[v] = u;
        f[i] = v;
    }
    dep[1]=1;
    for(int i = 1;i <=n;i++)
    {
        dfs(f[i]);
    }
    long long ans = 0;
    for(int i = 0;i < n-1;i++)
    {
        if(dep[f[i]]-1<=d)
            ans++;
    }
    cout << ans;
    return 0;
}