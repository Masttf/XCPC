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
constexpr int  Max = 1e18;
void solve(){
    int k;cin >> k;
    vector<int> lim(k + 1);
    int n = 0;
    for(int i = 1; i <= k; i++) cin >> lim[i], n += lim[i];
    vector a(n + 1, vector<int> (k + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= k; j++){
    		cin >> a[i][j];
            a[i][j] = -a[i][j];
    	}
    }
    vector<int> bl(n + 1, -1);
    int ans = 0;
    vector q(k + 1, vector (k + 1, set<pair<int ,int>>()));
    auto add = [&](int x, int c) -> void{
        for(int i = 1; i <= k; i++){
            if(i == c)continue;
            q[c][i].insert({a[x][i] - a[x][c], x});
        }
        bl[x] = c;
    };
    auto del = [&](int x) -> void{
        for(int i = 1; i <= k; i++){
            if(i == bl[x])continue;
            q[bl[x]][i].erase({a[x][i] - a[x][bl[x]], x});
        }
        bl[x] = -1;
    };
    for(int i = 1; i <= n; i++){
        add(i, 0);
    }
    while(1){
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
        if(now == -1 || dis[now] > 0)break;
        //dbg(now);
        ans += dis[now];
        lim[now]--;
        while(now){
            int fa = pre[now];
            int v = q[fa][now].begin() -> second;
            //dbg(fa, now, v);
            del(v);
            add(v, now);
            now = fa;
        }
    }
    // for(int i = 1; i <= n; i++){
    // 	dbg(i, bl[i]);
    // }
    cout << -ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}