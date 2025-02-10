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
constexpr int Max = 1e18;
void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vector<array<int, 3>>>g(n + 1);
	for(int i = 1; i <= m; i++){
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		g[u].push_back({v, c, w});
		g[v].push_back({u, c, w});
	}
	vector<vector<pair<int, int>>> pos(m + 1);
	vector<int>l(m + 1), r(m + 1);
	for(int i = 1; i <= k; i++){
		int c, w; cin >> c >> w;
		pos[c].push_back({w, i});
	}
	vector<int> val(k + 1), time(k + 1);
	vector st(21, vector<int>(k + 1));
	{
		int tot = 0;
		for(int i = 1; i <= m; i++){
			l[i] = tot + 1;
			for(auto [x, y] : pos[i]){
				val[++tot] = x;
				time[tot] = y;
				st[0][tot] = x;
			}
			r[i] = tot;
		}
	}
	for(int s = 1; s <= 20; s++){
		for(int i = 1; i + (1 << s) <= k + 1; i++){
			st[s][i] = max(st[s - 1][i], st[s - 1][i + (1 << (s - 1))]);
		}
	}
	auto get = [&](int L, int R) -> int{
		int d = __lg(R - L + 1);
		return max(st[d][L], st[d][R - (1 << d) + 1]);
	};
	auto findFirst = [&](int c, int t, int w) -> int{
		if(l[c] > r[c])return -1;
		int p = lower_bound(time.begin() + l[c], time.begin() + r[c] + 1, t) - time.begin();
		if(p > r[c])return -1;
		int res = -1;
		int L = p, R = r[c];
		while(L <= R){
			int mid = (L + R) >> 1;
			if(get(p, mid) >= w){
				res = mid;
				R = mid - 1;
			}else L = mid + 1;
		}
		return res;
	};
	vector<int>vis(n + 1);
	vector<pair<int, int>>dis(n + 1, {k + 1, 0});
	auto dij = [&]() -> void{
		priority_queue<array<int ,3>, vector<array<int, 3>>, greater<array<int, 3>>>q;
		q.push({0, 0, 1});
		dis[1] = {0, 0};
		while(!q.empty()){
			auto [t, d, u] = q.top();
			q.pop();
			if(vis[u])continue;
			vis[u] = 1;
			for(auto [v, c, w] : g[u]){
				int ps = findFirst(c, t, w);
				if(ps == -1)continue;
				if(time[ps] == t){
					if(d + w <= val[ps]){
						if(dis[v].first > t || (dis[v].first == t && dis[v].second > w + d)){
							dis[v] = {time[ps], w + d};
							q.push({dis[v].first, dis[v].second, v});
						}
					}else{
						ps = findFirst(c, t + 1, w);
						if(ps == -1)continue;
						if(dis[v].first > time[ps] || (dis[v].first == time[ps] && dis[v].second > w)){
							dis[v] = {time[ps], w};
							q.push({dis[v].first, dis[v].second, v});
						}
					}
				}else{
					if(dis[v].first > time[ps] || (dis[v].first == time[ps] && dis[v].second > w)){
						dis[v] = {time[ps], w};
						q.push({dis[v].first, dis[v].second, v});
					}
				}
			}
		}
	};
	dij();
	for(int i = 1; i <= n; i++)cout << vis[i];
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