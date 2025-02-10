#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 1e5+5;
const ll Inf = 1e18;

int n, m, k, cnt;
int head[N], vis[N];
ll dis[N];
ll mindis[N];

struct Edge{int to, nxt;ll len;}e[N * 3];

void addedge(int u, int v, ll t){
    e[++cnt]= (Edge){v, head[u], t};
    head[u]= cnt;
}

int lowbit(int x){return x & (-x);}

priority_queue <pair<int, int> >q;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        dis[0]= 0;
        cin>>n>>m>>k;
        cnt = 0;
        for (int i = 1;i <= n;++i) head[i] = -1, dis[i] = Inf, vis[i] = 0;
        for (int i = 1;i <= m;++i){
            int u, v, t;
            cin>>u>>v>>t;
            addedge(u, v, t);
            addedge(v, u, t);
        }
        for (int j = 2;j <= n;++j) addedge(1, j, 1ll * k * (1 | j));
        dis[1]=0;
        q.push(make_pair(0, 1));
        while (!q.empty()){
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            for (int i = head[u];i > 0;i = e[i].nxt){
                int v = e[i].to;
                if (dis[v] > dis[u] + e[i].len){
                    dis[v] = dis[u] + e[i].len;
                    q.push(make_pair(-dis[v], v));
                }
            }
        }
        for (int i = 0;i <= n;++i) mindis[i] = dis[i], vis[i] = 0;
        for (int i = 2;i <= n;++i){
            if (i != lowbit(i))
                for (int j = 0;(1<<j) <= n; ++j)
                    if (i & (1<<j)) mindis[i] = min(mindis[i], mindis[i ^ (1<<j)]);
            if (mindis[i] + 1ll * k * i < dis[i]) dis[i] = mindis[i] + 1ll * k * i;
        }
        for (int i = 1;i <= n;++i) vis[i] = 0, q.push(make_pair(-dis[i], i));
        while (!q.empty()){
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            for (int i = head[u];i > 0;i = e[i].nxt){
                int v = e[i].to;
                if (dis[v] > dis[u] + e[i].len){
                    dis[v] = dis[u] + e[i].len;
                    q.push(make_pair(-dis[v], v));
                }
            }
        }
        cout<<dis[2];
        for (int i = 3;i <= n;++i) cout<<' '<<dis[i];cout<<'\n';
    }
    return 0;
}