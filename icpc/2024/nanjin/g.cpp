#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

const int maxn = 2e5 + 5;
vector <int> t[maxn];
int vis[maxn],f[maxn],siz[maxn],maxx[maxn],lson[maxn],rson[maxn];

int Sum,rt,root;

void dfs(int u,int fa) {
	siz[u] = 1;
	maxx[u] = 0;
	for (auto i : t[u]) {
		if (i == fa || vis[i]) continue;
		dfs(i,u);
		maxx[u] = max(maxx[u],siz[i]);
		siz[u] += siz[i];
	}
	maxx[u] = max(maxx[u],Sum - siz[u]);
	if (maxx[u] < maxx[rt]) rt = u;
}

void solve(){
	int n;cin >> n;
	for (int i = 1;i <= n;i++) {
		t[i].clear();
		f[i] = vis[i] = siz[i] = maxx[i] = lson[i] = rson[i] = 0;
	}
	for (int i = 1;i <= n;i++) {
		int u,v;cin >> u >> v;
		lson[i] = u;
		rson[i] = v;
		if (u != 0) {
			f[u] = i;
			t[i].push_back(u);
			t[u].push_back(i);
		}
		if (v != 0) {
			f[v] = i;
			t[i].push_back(v); 
			t[v].push_back(i);
		}
	}
	rt = 0;
	maxx[rt] = 1e9; 
	Sum = n;
	root = 1;
	dfs(root,0);
	dfs(rt,0);
	while (1) {
		int q1 = -1,q2 = -1;
		vector <pair<int,int>> son;
		for (auto i : t[rt]) son.push_back({siz[i],i});
		sort(son.begin(),son.end());
		int len = son.size();
		for (int i = len - 1;i >= 0;i--) {
			if (vis[son[i].second]) continue;
			if (q1 == -1) q1 = son[i].second;
			if (q1 && q2 == -1) q2 = son[i].second;
		}
		if (q1 == -1) {
			cout << "! " << rt << '\n';
			fflush(stdout);
			break; 
		}
		if (q2 == -1) {
			q2 = rt;
		}
		cout << "? " << q1 << ' ' << q2 << '\n';
		fflush(stdout);
		int ans;cin >> ans;
		if (ans == 0) {
			if (q1 == rt) {
				cout << "! " << rt << '\n';
				fflush(stdout);
				break;
			}
			vis[rt] = 1;
			root = q1;
			rt = 0;
			maxx[rt] = 1e9; 
			Sum = siz[q1];
			root = 1;
			dfs(root,0);
			dfs(rt,0);
		}
		else if (ans == 1) {
			vis[q1] = 1;
			vis[q2] = 1;
			root = rt;
			rt = 0;
			maxx[rt] = 1e9; 
			Sum = siz[q1];
			root = 1;
			dfs(root,0);
			dfs(rt,0);
		}
		else {
			if (q2 == rt) {
				cout << "! " << rt << '\n';
				fflush(stdout);
				break;
			}
			vis[rt] = 1;
			root = q2;
			rt = 0;
			maxx[rt] = 1e9; 
			Sum = siz[q2];
			root = 1;
			dfs(root,0);
			dfs(rt,0);
		}
	}
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