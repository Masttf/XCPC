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

const int maxn = 2e5 + 5;
vector<int>t[maxn];
int fa[maxn],siz[maxn],dep[maxn];
vector<pair<int,int>>pi;

void dfs(int u,int f) {
	siz[u] = 1;
	for (auto i : t[u]) {
		if (i == f) continue;
		dep[i] = dep[u] + 1;
		fa[i] = u;
		dfs(i,u);
		siz[u] += siz[i];
	}
}

void solve(){
	int n;cin >> n;
	for (int i = 1;i <= n;i++) {
		t[i].clear();
		fa[i] = 0;
	}
	pi.clear();
	for (int i = 1;i < n;i++) {
		int u,v;cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
		pi.push_back({u,v});
	}
	dep[1] = 1;
	dfs(1,0);
	for (int i = 1;i <= n;i++) {
		if (t[i].size() != 2) continue;
		int s1 = t[i][0],s2 = t[i][1];
		//dbg(s1,s2);
		int siz_s1,siz_s2;
		if (dep[s1] > dep[i]) {
			siz_s1 = siz[s1];
		}
		else siz_s1 = siz[1] - siz[i];
		if (dep[s2] > dep[i]) {
			siz_s2 = siz[s2];
		} 
		else siz_s2 = siz[1] - siz[i];
		int ok1 = 0,ok2 = 0;
		//dbg(siz_s1,siz_s2);
		//cout << (int)t[s1].size() << ' ' << siz_s1 << '\n';
		if ((int)t[s1].size() - 1 == siz_s1 - 1) {
			ok1 = 1;
		} 
		else {
			if ((int)t[s1].size() == 2) {
				int ss1;
				for (auto j : t[s1]) {
					if (j == i) continue;
					ss1 = j;
				}
				if ((int)t[ss1].size() == siz_s1 - 1) {
					ok1 = 1;
				}
			}
		}
		//dbg(ok1);
		if ((int)t[s2].size() - 1 == siz_s2 - 1) {
			ok2 = 1;
		} 
		else {
			if ((int)t[s2].size() == 2) {
				int ss2;
				for (auto j : t[s2]) {
					if (j == i) continue;
					ss2 = j;
				}
				if ((int)t[ss2].size() == siz_s2 - 1) {
					ok2 = 1;
				}
			}
		}
		if (ok1 && ok2) {
			cout << "Yes" << '\n';
			return ; 
		}
	}
	cout << "No" << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}