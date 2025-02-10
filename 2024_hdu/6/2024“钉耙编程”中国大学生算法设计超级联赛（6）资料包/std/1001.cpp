#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int fa[N],duano[N],sz[N],egu[N],egv[N],du[N];
int findfa(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
}
void mg(int x, int y)
{
    int fax = findfa(x), fay = findfa(y);
    fa[fax] = fay;
    duano[x] ++; duano[y] ++;
    sz[fay] += sz[fax];
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,j,du2=0,ok=0;
        scanf("%d",&n);
        fill(du,du+1+n,0);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&egu[i],&egv[i]);
            du[egu[i]] ++; du[egv[i]] ++;
        }
        if(n <= 2)
        {
            printf("No\n"); continue;
        }
        for(i=1;i<=n;i++)
        {
            if(du[i] != 2 || du2 >= 6) continue;
            du2 ++; ok = 1;
            fill(duano+1,duano+1+n,0);
            fill(sz+1,sz+1+n,1);
            iota(fa+1,fa+1+n,1);
            for(j=1;j<n;j++)
            {
                if(egu[j] == i || egv[j] == i) continue;
                mg(egu[j],egv[j]);
            }
            for(j=1;j<=n;j++)
            {
                if(j == i) continue;
                int f = findfa(j);
                if(duano[j] == 1) sz[f] --;
            }
            for(j=1;j<=n;j++)
            {
                if(j == i) continue;
                if(findfa(j) == j && sz[j] > 1) ok = 0;
            }
            if(ok) break;
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}