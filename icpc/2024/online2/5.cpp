#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int Max = 1e18;
void solve(){
	int n, m, D;
	cin >> n >> m >> D;
	vector<vector<int>>g(n + 1);
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int k; cin >> k;
	vector<int> s(k + 1);
	for(int i = 1; i <= k; i++){
		cin >> s[i];
	}
	vector dis(n + 1, vector<int>(2, Max));
	{
		vector vis(n + 1, vector<int>(2));
		queue<pair<int, int>>q;
		for(int i = 1; i <= k; i++){
			dis[s[i]][0] = 0;
			q.push({s[i], 0});
		}
		int cnt = 0;
		while(!q.empty() && cnt < D){
			int sz = q.size();
			for(int j = 0; j < sz; j++){
				auto [u, ty] = q.front();
				q.pop();
				for(auto v : g[u]){
					if(vis[v][ty ^ 1])continue;
					dis[v][ty ^ 1] = dis[u][ty] + 1;
					vis[v][ty ^ 1] = 1;
					q.push({v, ty ^ 1});
				}
			}
			cnt++;
		}
	}
	vector d(n + 1, vector<int>(2, Max));
	vector pre(n + 1, vector<pair<int ,int>>(2, {-1, -1}));
	{
		//dbg("ppp");
		vector vis(n + 1, vector<int>(2));
		queue<pair<int, int>>q;
		d[1][0] = 0;
		vis[1][0] = 1;
		q.push({1, 0});
		while(!q.empty()){
			auto [u, ty] = q.front();
			q.pop();
			//dbg(u, ty, d[u][ty]);
			for(auto v : g[u]){
				if(vis[v][ty ^ 1])continue;
				if(dis[v][ty ^ 1] <= d[u][ty] + 1)continue;
				d[v][ty ^ 1] = d[u][ty] + 1;
				vis[v][ty ^ 1] = 1;
				pre[v][ty ^ 1] = {u, ty};
				q.push({v, ty ^ 1});
			}
		}
	}
	int mi = min(d[n][0], d[n][1]);
	if(mi == Max){
		cout << -1 << '\n';
		return ;
	}
	pair<int ,int> now = {n, -1};
	if(d[n][0] == mi){
		now.second = 0;
	}else{
		now.second = 1;
	}
	vector<int>res;
	int tot = mi;
	while(tot--){
		res.push_back(now.first);
		now = pre[now.first][now.second];
	}
	res.push_back(1);
	reverse(res.begin(), res.end());
	cout << mi << '\n';
	for(auto x : res)cout << x << ' ';
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}