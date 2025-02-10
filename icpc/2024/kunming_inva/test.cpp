#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max = 1e18;
struct TwoMCFGraph{
    int n, k;
    vector<vector<int>> cost;
    vector<int>bl, lim;
    vector<vector<set<pair<int, int>>>>q;
    TwoMCFGraph(){}
    TwoMCFGraph(int n_, int k_){
        n = n_;
        k = k_;
        cost.assign(n + 1, vector<int>(k + 1, Max));
        for(int i = 1; i <= n; i++)cost[i][0] = 0;
        bl.assign(n + 1, -1);
        lim.assign(k + 1, 0);
        q.assign(k + 1, vector(k + 1, set<pair<int, int>>()));
    }
    void add (int x, int c){
        for(int i = 1; i <= k; i++){
            if(i == c)continue;
            q[c][i].insert({cost[x][i] - cost[x][c], x});
        }
        bl[x] = c;
    };
    void del (int x){
        for(int i = 1; i <= k; i++){
            if(i == bl[x])continue;
            q[bl[x]][i].erase({cost[x][i] - cost[x][bl[x]], x});
        }
        bl[x] = -1;
    };
    int flow(){
        int res = 0;
        int tot = n;
        for(int i = 1; i <= n; i++)add(i, 0);
        while(tot--){
            vector g(k + 1, vector<int>(k + 1));
            for(int i = 0; i <= k; i++){
                for(int j = 1; j <= k; j++){
                    if(q[i][j].empty())g[i][j] = Max;
                    else g[i][j] = q[i][j].begin() -> first;
                }
            }
            vector<int> dis(k + 1, Max), pre(k + 1, -1);
            vector<int> vis(k + 1, 0);
            queue<int> que;
            dis[0] = 0;
            que.push(0);
            while(!que.empty()){
                int u = que.front();
                que.pop();
                vis[u] = 0;
                for(int i = 1; i <= k; i++){
                    if(dis[u] + g[u][i] < dis[i]){
                        dis[i] = dis[u] + g[u][i];
                        pre[i] = u;
                        if(!vis[i]){
                            vis[i] = 1;
                            que.push(i);
                        }
                    }
                }
            }
            int now = -1;
            for(int i = 1; i <= k; i++){
                if(lim[i] && (now == -1 || dis[i] < dis[now])){
                    now = i;
                }
            }
            if(now == -1)break; // 注意这是满流条件
            // if(now == -1 || dis[now] > 0)break; // 这是任意流条件
            res += dis[now];
            //dbg(res);
            lim[now]--;
            while(now){
                int fa = pre[now];
                assert(fa != -1);
                int v = q[fa][now].begin() -> second;
                //dbg(fa, now, v);
                del(v);
                add(v, now);
                now = fa;
            }
        }
        return res;
    }
};
void solve(){
    int n, k; cin >> n >> k;
    TwoMCFGraph g(n, k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cin >> g.cost[i][j];
        }
    }
    for(int i = 1; i <= k; i++) cin >> g.lim[i];
    cout << g.flow() << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}