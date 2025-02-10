#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int maxn = 1e5+5;
void solve(){
	int n, m, q;cin >> n >> m >> q;
	map<pair<int, int>, int> val;
	vector<array<int, 3>> e(m);
	for(int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		e[i-1] = {w, u, v};
		val[{u, v}] = w;
		val[{v, u}] = w;
	}
	sort(e.begin(), e.end());
	vector<int> f(n + 1);
	auto find = [&](auto self, int x) -> int{
		return f[x] == x ? x : f[x] = self(self, f[x]);
	};
	int block = sqrt(n);
	vector<int> vis(n + 1);
	for(int i = 1; i <= q; i++){
		int k; cin >> k;
		vector<int> a(k + 1);
		for(int j = 1; j <= k; j++){
			cin >> a[j];
			vis[a[j]]=1;
			f[a[j]] = a[j];
		}
		if(k > block){
			int ans = 0;
			int sz = k;
			for(auto [w, u, v] : e){
				if(!vis[u] || !vis[v])continue;
				int fa = find(find, u);
				int fb = find(find, v);
				if(fa == fb)continue;
				f[fa] = fb;
				ans += w;
				sz--;
			}
			if(sz != 1)cout << -1 << '\n';
			else cout << ans << '\n';
		}else{
			vector<array<int, 3>>edge;
			for(int j = 1; j <= k; j++){
				for(int r = j + 1; r <= k; r++){
					if(val.count({a[j], a[r]})){
						edge.push_back({val[{a[j], a[r]}], a[j], a[r]});
					}
				}
			}
			sort(edge.begin(), edge.end());
			int ans = 0;
			int sz = k;
			for(auto [w, u, v] : edge){
				int fa = find(find, u);
				int fb = find(find, v);
				if(fa == fb)continue;
				f[fa] = fb;
				ans += w;
				sz--;
			}
			if(sz != 1)cout << -1 << '\n';
			else cout << ans << '\n';
		}
		for(int j = 1; j <= k; j++){
			vis[a[j]]=0;
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}