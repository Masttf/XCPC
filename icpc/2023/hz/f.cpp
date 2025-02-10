#include <bits/stdc++.h>
using namespace std;
#define int long long

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

void solve() {
	int n,q;cin >> n >> q;
	set<int>s;
	vector<int>a(n+1),to(n+5),zj1(n+5),zj2(n+5);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	vector<vector<pair<int,int>>>g(n+1);
	for (int i = 1;i < n;i++) {
		int u,v,w;cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	int now = 0;
	while (s.count(now)) now++;
	for (int i = 1;i <= n;i++) {
		if (a[i] <= now){
			to[a[i]] = i;
		} 
	}
	vector<int>dep(n+1);
	vector<vector<int>>f(25,vector<int>(n+1));
	auto dfs = [&](auto self,int now,int father)->void{
		f[0][now]=father;
		dep[now]=dep[father]+1;
		for(int i=1;(1ll<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
		}
		for(auto [v,w]:g[now]){
			if(v==father)continue;
			self(self,v,now);
		}
		return ;
	};
	dfs(dfs,1,0);
	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b])a= f[i][a];
		}
		if(a==b)return a;
		for(int i=22;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				a=f[i][a];
				b=f[i][b];
			}
		}
		return f[0][a];
	};	
	//dbg(lca(3,4));
	auto check = [&](int mid,int x,int k)->bool{
		int lca1 = lca(x,zj1[mid]);
		int lca2 = lca(x,zj2[mid]);
		int now1 = dep[x] + dep[zj1[mid]] - 2 * dep[lca1];
		int now2 = dep[x] + dep[zj2[mid]] - 2 * dep[lca2];
		int res = max(now1,now2);
		//dbg(mid,x,k,res,lca1,lca2,now1,now2);
		return res<=k;
	};
	for (int i = 0;i <= now - 1;i++) {
		if (i == 0) {
			zj1[i] = to[i];
			zj2[i] = to[i];
		}
		else if (i == 1) {
			zj2[i] = to[i];
			zj1[i] = zj1[i - 1];
		}
		else {
			int d1;
			int lca1 = lca(zj1[i - 1],zj2[i - 1]);
			int now1 = dep[zj1[i - 1]] + dep[zj2[i - 1]] - 2 * dep[lca1];
			int lca2 = lca(zj1[i - 1],to[i]);
			int now2 = dep[zj1[i - 1]] + dep[to[i]] - 2 * dep[lca2];
			int lca3 = lca(zj2[i - 1],to[i]);
			int now3 = dep[zj2[i - 1]] + dep[to[i]] - 2 * dep[lca2];
			if (now2 >= now3) {
				if (now2 >= now1) {
					zj1[i] = zj1[i - 1];
					zj2[i] = to[i];
				}
			}
			else {
				if (now3 >= now1) {
					zj2[i] = zj2[i - 1];
					zj1[i] = to[i];
				}
			}
			//dbg(lca1,lca2,lca3);
		}
		//dbg(zj1[i],zj2[i],i);
	}
	for (int i = 1;i <= q;i++) {
		int x,k;cin >> x >> k;
		int l = 0,r = now - 1;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid,x,k)) {
				l = mid + 1;
				ans = max(ans,mid);
			}
			else r = mid - 1;
		}
		cout << ans + 1 << '\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	//std::cin >> T;
	while(T--) solve();
	return 0;
}