#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define ssz(x) (int((x).size()))

vector<int> node[N];
int fa[N],sz[N],egu[N],egv[N],du[N],egcnt[N];
int findfa(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
}
void mg(int x, int y)
{
    int fax = findfa(x), fay = findfa(y);
    fa[fax] = fay;
    du[x] ++; du[y] ++;
    if(fax != fay)
    {
        sz[fay] += sz[fax];
        egcnt[fay] += egcnt[fax]+1;
    }
    else egcnt[fax] ++;
}
vector<int> delnode,ans;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,i,j,u,v,x,y,ok=1;
        scanf("%d%d",&n,&m);
        delnode.clear(); ans.clear();
        for(i=1;i<=n;i++) node[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            egu[i] = u; egv[i] = v;
            node[u].push_back(v);
            node[v].push_back(u);
        }
        for(i=1;i<=m;i++)
        {
            u = egu[i]; v = egv[i]; x = y = 0;
            for(j=0;j<ssz(node[u]);j++)
            {
                if(node[u][j] != v)
                {
                    x = node[u][j]; break;
                }
            }
            for(j=0;j<ssz(node[v]);j++)
            {
                if(node[v][j] != u)
                {
                    y = node[v][j]; break;
                }
            }
            if(x>0 && y>0)
            {
                ok = 0;
                delnode.push_back(u);
                delnode.push_back(v);
                delnode.push_back(x);
                if(x != y) delnode.push_back(y);
                break;
            }
        }
        if(ok)
        {
            for(i=1;i<=n;i++) printf("%d%c",i," \n"[i==n]);
            continue;
        }
        for(i=0;i<ssz(delnode);i++) //check if u is chaos-node
        {
            ok = 1; u = delnode[i];
            fill(du+1,du+1+n,0);
            fill(egcnt+1,egcnt+1+n,0);
            fill(sz+1,sz+1+n,1);
            iota(fa+1,fa+1+n,1);
            for(j=1;j<=m;j++)
            {
                if(egu[j] == u || egv[j] == u) continue;
                mg(egu[j],egv[j]);
            }
            for(j=1;j<=n;j++) if(findfa(j) == j && sz[j] != egcnt[j]+1) ok = 0;
            for(j=1;j<=n;j++)
            {
                if(j == u) continue;
                int f = findfa(j);
                if(du[j] == 1) sz[f] --;
            }
            for(j=1;j<=n;j++)
            {
                if(j == u) continue;
                if(findfa(j) == j && sz[j] > 1) ok = 0;
            }
            if(ok) ans.push_back(u);
        }
        if(ssz(ans) == 0) printf("-1\n");
        else
        {
            sort(ans.begin(),ans.end());
            for(i=0;i<ssz(ans);i++) printf("%d%c",ans[i]," \n"[i==ssz(ans)-1]);
        }
    }
    return 0;
}
