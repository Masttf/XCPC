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


const int maxn = 1e5 + 5;
vector<int>t[maxn];
int dep1[maxn],dep2[maxn],p1,p2;

void dfs1(int u,int f) {
	if (dep1[p1] < dep1[u]) p1 = u;
	for (auto i : t[u]) {
		if (i == f) continue;
		dep1[i] = dep1[u] + 1;
		dfs1(i,u); 
	}
}

void dfs2(int u,int f) {
	if (dep2[p2] < dep2[u]) p2 = u;
	for (auto i : t[u]) {
		if (i == f) continue;
		dep2[i] = dep2[u] + 1;
		dfs2(i,u);
	}
}

void solve(){
	int n,s,r1,r2;cin >> n >> s >> r1 >> r2;
	for (int i = 1;i <= n;i++) {
		t[i].clear();
	}
	for (int i = 1;i < n;i++) {
		int u,v;cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	p1 = 0;
	dep1[p1] = -1;
	dep1[s] = 0;
	dfs1(s,0);
	p2 = 0;
	dep2[p2] = -1;
	dep2[p1] = 0;
	dfs2(p1,0);
	if (r2 > 2 * r1 && dep2[p2] > 2 * r1) {
		cout << "General_Kangaroo" << '\n';
	}
	else cout << "Kangaroo_Splay" << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}