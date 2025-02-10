#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & - (x))
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
struct node{
	int l, r, id, ty;
};
void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<int>>G(m + 1);
	vector<int> du(m + 1);
	vector<int> pos(n + 1);
	vector<int> ff(m + 1);
	vector<pair<int, int>>qu(m + 1);
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		pos[u] = i;
		qu[i] = {u, v};
	}
	vector<int> dep(n + 1);
	vector<vector<int>> f(25, vector<int>(n + 1));
	vector<int> last(n + 1);
	auto dfs = [&](auto self, int now, int father) -> void{
		dep[now] = dep[father]+1;
		f[0][now] = father;
		for(int i = 1; (1ll << i) < dep[now]; i++){
			f[i][now] = f[i - 1][f[i - 1][now]];
		}
		for(auto v : g[now]){
			if(v == father)continue;
			if(pos[now])last[v] = now;
			else last[v] = last[now];
			self(self, v, now);
		}
		return ;
	};
	dfs(dfs, 1, 0);
	
	auto lca = [&](int a, int b) -> int{
		if(dep[a] < dep[b])swap(a,b);
		for(int i = 20; i >= 0; i--){
			if(dep[a] - (1ll << i) >= dep[b])a = f[i][a];
		}
		if(a == b)return a;
		for(int i = 20; i >= 0; i--){
			if(f[i][a] != f[i][b]){
				a = f[i][a];
				b = f[i][b];
			}
		}
		return f[0][a];
	};
	
	for(int i = 1; i <= m; i++){
		auto [u, v] = qu[i];
		ff[i] = lca(u, v);
	}
	for(int i = 1; i <= m; i++){
		auto [u, v] = qu[i];
		int now = u;
		while(last[now] && dep[last[now]] >= dep[ff[i]]){
			//dbg(now);
			G[pos[last[now]]].push_back(i);
			du[i]++;
			//dbg(pos[last[now]], i, now);
			//dbg(i, now, last[now], pos[last[now]], ff[pos[last[now]]]);
			if(dep[ff[pos[last[now]]]] >= dep[ff[i]])now = ff[pos[last[now]]];
			else now = last[now];
			//dbg(now);
		}
		now = v;
		if(pos[now]){
			if(pos[now] != i){
				G[pos[now]].push_back(i);
				du[i]++;
				//dbg(pos[now], i, now);
			}
		}
		while(last[now] && dep[last[now]] >= dep[ff[i]]){
			//dbg(now);
			if(pos[last[now]] != i){
				G[pos[last[now]]].push_back(i);
				du[i]++;
				//dbg(pos[last[now]], i, now);
			}
			if(dep[ff[pos[last[now]]]] >= dep[ff[i]])now = ff[pos[last[now]]];
			else now = last[now];
			//dbg(now);
		}
	}
	vector<int> ans;
	auto bfs = [&]()->void{
		queue<int> q;
		for(int i = 1; i <= m; i++){
			if(!du[i])q.push(i);
		}
		while(!q.empty()){
			int u = q.front();
			//dbg(u);
			q.pop();
			ans.push_back(u);
			for(auto v : G[u]){
				du[v]--;
				if(!du[v])q.push(v);
			}
		}
	};
	bfs();
	if(ans.size() == m){
		cout << "Yes\n";
		for(auto x : ans)cout << x << ' ';
		cout << '\n';
	}else cout << "No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}