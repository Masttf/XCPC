#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    map<pair<int, int>, int> mp;
    vector g(n + 1, vector<int>());
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	mp[{u, v}] = i;
    }
    vector<pair<int, int>> ans(n);
    vector dis(n + 1, vector<int>(2));
    vector cnt(n + 1, vector<int>(2));
    vector<int> dp(n + 1);
    auto add = [&](int x, int y) -> void{
    	dp[x] += dp[y];
    	dp[x] += cnt[y][1] * dis[x][0] + cnt[x][0] * dis[y][1] + cnt[x][0] * cnt[y][1];
		dp[x] += cnt[y][0] * dis[x][1] + cnt[x][1] * dis[y][0] + cnt[x][1] * cnt[y][0];
		dis[x][0] += dis[y][0] + cnt[y][0];
		dis[x][1] += dis[y][1] + cnt[y][1];
		cnt[x][0] += cnt[y][0];
		cnt[x][1] += cnt[y][1];
    };
    auto del = [&](int x, int y) -> void{
    	dp[x] -= dp[y];
    	dis[x][0] -= dis[y][0] + cnt[y][0];
		dis[x][1] -= dis[y][1] + cnt[y][1];
		cnt[x][0] -= cnt[y][0];
		cnt[x][1] -= cnt[y][1];
		dp[x] -= cnt[y][1] * dis[x][0] + cnt[x][0] * dis[y][1] + cnt[x][0] * cnt[y][1];
		dp[x] -= cnt[y][0] * dis[x][1] + cnt[x][1] * dis[y][0] + cnt[x][1] * cnt[y][0];
    };
    auto dfs1 = [&](auto self, int now, int father) -> void{
    	if(s[now] == 'b'){
    		cnt[now][0]++;
    	}else{
    		cnt[now][1]++;
    	}
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		add(now, v);
    	}
    };
    dfs1(dfs1, 1, 0);

    auto dfs2 = [&](auto self, int now, int father) -> void{
    	for(auto v : g[now]){
    		if(v == father)continue;
    		del(now, v);
    		if(mp.count({now, v})){
    			ans[mp[{now, v}]] = {dp[now], dp[v]};
    		}else{
    			ans[mp[{v, now}]] = {dp[v], dp[now]};
    		}
    		add(v, now);
    		self(self, v, now);
    		del(v, now);
    		add(now, v);
    	}
    };
    dfs2(dfs2, 1, 0);
    for(int i = 1; i < n; i++){
    	cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
/*
考虑所有的黑白路径 然后总的距离和除2即可
或者有序
换根？
换根就可以做到

dpi 0/1 表示黑/白色子节点到i的距离和
任意一个的黑 i + （白的距离和 + 1）
*/