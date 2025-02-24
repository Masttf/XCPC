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
void solve(){
	int n; cin >> n;
	vector<int>p(n + 1);
	vector<int>bl(n + 1);
	for(int i  = 1; i <= n; i++){
		cin >> p[i];
		bl[p[i]] = i;
	}
	vector<vector<int>>g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>vis(n + 1);
	auto bfs = [&](int l, int r) -> bool{
		for(int i = l; i <= r; i++)vis[bl[i]] = 0;
		queue<int>q;
		int cnt = 0;
		int sz = 0;
		q.push(bl[l]);
		vis[bl[l]] = 1;
		while(!q.empty()){
			int u = q.front();
			//dbg(u);
			sz++;
			q.pop();
			int f = 0;
			for(auto v : g[u]){
				if(p[v] < l || p[v] > r)continue;
				f++;
				if(vis[v])continue;
				vis[v] = 1;
				q.push(v);
			}
			if(f == 1)cnt++;
		}
		if(sz == r - l + 1 && cnt == 2)return true;
		return false;
	};
	int m; cin >> m;
	for(int i = 1; i <= m; i++){
		int op, x, y; cin >> op >> x >> y;
		if(op == 1){
			swap(p[x], p[y]);
			swap(bl[p[x]], bl[p[y]]);
		}else{
			if(x == y){
				cout << "Yes\n";
				continue;
			}
			if(bfs(x, y))cout << "Yes\n";
			else cout << "No\n";
		}
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