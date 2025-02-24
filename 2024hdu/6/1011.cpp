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
constexpr int Max = 1e18;
void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n + 1);
	vector<int>du(n + 1);
	for(int i = 1; i <= n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		du[u]++;
		du[v]++;
	}
	auto topu = [&]() -> void{
		queue<int>q;
		for(int i = 1; i <= n; i++){
			if(du[i] == 1)q.push(i);
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto v : g[u]){
				du[v]--;
				if(du[v] == 1)q.push(v);
			}
		}
	};
	topu();
	vector<int>f(n + 1);
	f[0] = -1;
	auto dfs = [&](auto self, int now, int father) -> void{
		for(auto v : g[now]){
			if(v == father || du[v] == 2)continue;
			self(self, v, now);
			f[now] = max(f[now], f[v] + 1);
		}
	};
	for(int i = 1; i <= n; i++){
		if(du[i] == 2){
			dfs(dfs, i, 0);
		}
	}
	// for(int i = 1; i <= n; i++){
	// 	dbg(i, f[i]);
	// }
	vector<int>o(n + 1, -Max), ans(n + 1);
	vector<int>res(1);
	vector<int>vis(n + 1);
	auto dfs3 = [&](auto self, int now) -> void{
		res.push_back(now);
		vis[now] = 1;
		for(auto v : g[now]){
			if(vis[v])continue;
			if(du[v] == 2){
				self(self, v);
			}
		}
	};
	for(int i = 1; i <= n; i++){
		if(du[i] == 2){
			dfs3(dfs3, i);
			break;
		}
	}
	// for(auto x : res)cout << x << ' ';
	// cout << endl;
	int sz = res.size() - 1;
	vector<int>st1(sz + 2), st2(sz + 2), st3(sz + 1), st4(sz + 1);
	st1[sz + 1] = st2[sz + 1] = st3[0] = st4[0] = -Max;
	for(int i = sz; i >= 1; i--){
		o[res[i]] = max({o[res[i]], st1[i + 1] - i, st2[i + 1] + i});
		st1[i] = max(st1[i + 1], f[res[i]] + i);
		st2[i] = max(st2[i + 1], f[res[i]] + sz - i);
	}
	for(int i = 1; i <= sz; i++){
		o[res[i]] = max({o[res[i]], st3[i - 1] + i, st4[i - 1] - i});
		st3[i] = max(st3[i - 1], f[res[i]] - i);
		st4[i] = max(st4[i - 1], f[res[i]] + i + sz);
	}
	auto dfs2 = [&](auto self, int now, int father, int mx) -> void{
		int mx1 = 0;
		int mx2 = 0;
		for(auto v : g[now]){
			if(v == father || du[v] == 2)continue;
			if(f[v] > f[mx1]){
				swap(mx1, mx2);
				mx1 = v;
			}else if(f[v] > f[mx2]){
				mx2 = v;
			}
		}
		ans[now] = max({ans[now], f[now] + mx, f[mx1] + f[mx2] + 2});
		for(auto v : g[now]){
			if(v == father || du[v] == 2)continue;
			if(v == mx1){
				self(self, v, now, max(mx, f[mx2] + 1) + 1);
			}else{
				self(self, v, now, max(mx, f[mx1] + 1) + 1);
			}
		}
		
	};
	for(int i = 1; i <= n; i++){
		if(du[i] == 2){
			dfs2(dfs2, i, 0, o[i]);
		}
	}
	
	vector<int>pre(n + 1), suf(n + 5);
	pre[0] = suf[n + 1] = -Max;
	for(int i = 1; i <= sz; i++){
		pre[i] = max(pre[i - 1], f[res[i]] - i);
	}
	for(int i = sz; i >= 1; i--){
		suf[i] = max(suf[i + 1], f[res[i]] + i);
	}
	for(int i = 1; i <= sz; i++){
		ans[res[i]] = max({ans[res[i]], pre[i - 1] + suf[i], pre[i] + suf[i + 1]});
	}
	int mxi = -Max, mxj = -Max;
    for(int i = 1; i <= sz; i++){
        mxj = max(mxj, mxi + f[res[i]] - i + sz);
        mxi = max(mxi, f[res[i]] + i);
        ans[res[i]] = max(ans[res[i]], mxj);
    }
    mxi = mxj = -Max;
    for(int i = sz; i >= 1; i--){
        mxj = max(mxj, mxi + f[res[i]] + i + sz);
        mxi = max(mxi, f[res[i]] - i);
        ans[res[i]] = max(ans[res[i]], mxj);
    }
	for(int i = 1; i <= n; i++)cout << ans[i] << " \n"[i == n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}