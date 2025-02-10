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

vector<int>t[50];
int n,m, ans;
int vis[50];
void dfs(int p, int val) {
	ans = std::max(ans, val);
	for(int j:t[p]) vis[j]++;
	for(int i : t[p]) {
		if(vis[i] == 1) {
			dfs(i, val + 1);
		}
	}
	for(int j:t[p]) vis[j]--;
}
void solve(){
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int u,v;cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) {
		vis[i]++;
		dfs(i, 1);
		vis[i]--;
	}
	std::cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}