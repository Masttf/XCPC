#include<bits/stdc++.h>
//#define int long long
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
void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int,int>>edge(m + 1);
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		edge[i] = {u, v};
	}
	vector<int> f(n + 1), sz(n + 1), num(n + 1);
	vector<pair<int, int>>stk;
	for(int i = 1; i <= n; i++)f[i] = i, sz[i] = 0, num[i] = 1;
	auto find = [&](int x) -> int{
		while(f[x] != x){
			x = f[x];
		}
		return x;
	};
	auto merge = [&](int x) -> void{
		auto [a, b] = edge[x];
		int fa = find(a);
		int fb = find(b);
		if(fa == fb){
			sz[fb]++;
			stk.push_back({fa,fb});
			return ;
		}
		if(num[fa] > num[fb])swap(fa, fb);
		f[fa] = fb;
		sz[fb] += sz[fa] + 1;
		num[fb] += num[fa];
		stk.push_back({fa, fb});
	};
	auto rollback = [&](int x) -> void{
		while(stk.size() > x){
			auto [fa, fb] = stk.back();
			stk.pop_back();

			if(fa != fb){
				f[fa] = fa;
				sz[fb] -= sz[fa];
				num[fb] -= num[fa];
			}
			sz[fb]--;
		}
	};
	vector<vector<int>>tr(n * 4);
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			tr[p].push_back(val);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
	};
	for(int i = 1; i <= m; i++){
		auto[u, v] = edge[i];
		if(u > v)swap(u, v);
		if(u > 1)updata(updata, 1, n, 1, u - 1, i, 1);
		if(u + 1 <= v - 1)updata(updata, 1, n, u + 1, v - 1, i, 1);
		if(v < n)updata(updata, 1, n, v + 1, n, i, 1);
	}
	vector<int>bel(n + 5);
	int tot = 0;
	vector t(n + 5,vector<int>());
	for (int i = 1;i <= m;i++) {
		auto [u,v]  = edge[i];
		t[u].push_back(v);
		t[v].push_back(u);
	}
	vector<int>vis(n + 5);
	int p = 0,ok = 0,cnt = 0;
	auto dfs1 = [&](auto self,int u,int fa) ->void {
		bel[u] = tot;
		cnt++;
		if ((int)t[p].size() < (int)t[u].size()) {
			p = u;
		}
		for (auto i : t[u]) {
			if (i == fa) continue;
			if (vis[i]) {
				ok = 1;
				continue;
			}
			vis[i] = 1;
			self(self,i,u);
		}
	};
	vector<int>noju;
	for (int i = 1;i <= n;i++) {
		if (!vis[i]) {
			vis[i] = 1;
			tot++;
			p = 0;
			ok = 0;
			cnt = 0;
			dfs1(dfs1,i,0);
			if (ok) {
				noju.push_back(tot);
			}
			else {
				if ((int)t[p].size() != cnt - 1) {
					noju.push_back(tot);
				}
			}
		}
	}
	if (noju.size() > 1) {
		cout << "-1" << '\n';
		return ;
	}
	vector<int>res(n + 1);
	if (noju.size() == 1) {
		int now = noju[0];
		for(int i = 1 ; i <= n; i++){
			if(bel[i] == now)res[i] = 1;
		}
	}else{
		for(int i = 1; i <= n; i++)res[i] = 1;
	}
	vector<int>ssz(n + 1);
	for(int i = 1 ; i <= n; i++){
		ssz[i] = t[i].size();
	}
	auto check = [&](int x) -> bool{
		int ok = 0;
		//dbg(x);
		for (auto i : t[x]) {
			ssz[i]--;
		}
		for (auto i : t[x]) {
			int bian = sz[find(i)];
			int dian = num[find(i)];
			if (bian != dian - 1) continue;;
			if (ssz[i]  == dian - 1) {
				ok++;
			}
			else {
				if (ssz[i] == 1) {
					int ss1;
					for (auto j : t[i]) {
						if (j == i || j == x) continue;
						ss1 = j;
					}
					if (ssz[ss1] == dian - 1) {
						ok++;
					}
				}
			}
		}
		for (auto i : t[x]) {
			ssz[i]++;
		}
		if (ok == t[x].size()) return true;
		else return false;
	};
	vector<int>ans;
	auto dfs = [&](auto self, int l, int r, int p) -> void{
		int siz = stk.size();
		for(auto x : tr[p]){
			merge(x);
		}
		if(l == r){
			if(res[l] == 1 && check(l)){
				ans.push_back(l);
			}
			rollback(siz);
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		rollback(siz);
	};
	dfs(dfs, 1, n, 1);
	if(ans.empty())cout << -1 << '\n';
	else{
		for(auto x : ans)cout << x << ' ';
		cout << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}