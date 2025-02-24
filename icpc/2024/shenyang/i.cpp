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

const int maxn = 1e4 + 5;
vector <int> t[maxn];
vector <int> leaf;
vector <int> line[maxn];
vector <int> route;
int a[maxn],vis[maxn],dep[maxn],check[100],fa[maxn];

void dfs(int u,int f) {
	int ok = 0;
	route.push_back(u);
	for (auto i : t[u]) {
		if (i == f) continue;
		ok = 1;
		dep[i] = dep[u] + 1;
		dfs(i,u);
	}
	if (!ok) {
		leaf.push_back(u);
		line[u] = route;
	}
	route.pop_back();
}

void solve(){
	route.clear();
	leaf.clear();
	for (int i = 0;i < 100;i++) check[i] = 0;
	int n;cin >> n;
	int N = 1;
	for (int i = 1;i <= n + 1;i++) N *= 2;
	N--;	
	//dbg(N);
	for (int i = 1;i <= N;i++) vis[i] = 0,line[i].clear(),t[i].clear();
	for (int i = 2;i <= N;i++) {
		cin >> a[i];
	}
	for (int i = 1;i <= N;i++) {
		int l,r;
		l = 2 * i,r = 2 * i + 1;
		if (l > N || r > N) continue;
		t[i].push_back(l);
		t[i].push_back(r);
		t[l].push_back(i);
		t[r].push_back(i);
		fa[l] = i,fa[r] = i;
	}
	dfs(1,0);
	int len = leaf.size(),cnt = 0;
	for (int i = 0;i < len;i++) {
		for (int j = 0;j < i;j++) {
			int preu = leaf[i],prev = leaf[j];
			int u1 = leaf[i],v1 = leaf[j];
			int length = line[u1].size();
			int sum1 = 0,sum2 = 0,ok = 0;
			for (int k = 0;k < length;k++) {
				int u = line[u1][k],v = line[v1][k];
				if (u == v) continue;
				if (vis[u] || vis[v]) {
					ok = 1;
					break;
				}
				sum1 += a[u],sum2 += a[v];
			}
			if (ok) continue;
			if (sum1 == sum2 && sum1 != 0) {
				while (fa[u1] != fa[v1]) u1 = fa[u1],v1 = fa[v1];
				u1 = fa[u1],v1 = fa[v1];
				if (check[dep[u1 * 2 + 1]]) {
					//dbg(u1);
					while (u1 * 2 + 1 <= preu && check[dep[u1 * 2 + 1]]) {
						u1 = u1 * 2 + 1;
					}
					//dbg(u1,preu,check[dep[u1]],dep[u1]);
					if (u1 == preu && !check[dep[u1]]) {
						cnt++;
						vis[u1] = 1;
						check[dep[u1]] = 1; 
						continue;
					}
					if (u1 * 2 + 1 <= preu && !check[dep[u1 * 2 + 1]]) {
						cnt++;
						vis[u1 * 2 + 1] = 1;
						check[dep[u1 * 2 + 1]] = 1;
					}
					else if (u1 != preu && u1 * 2 + 1 > preu && !check[dep[u1 * 2]]) {
						cnt++;
						vis[u1 * 2] = 1;
						check[dep[u1 * 2]] = 1;
					}
					else {
						cout << "-1" << '\n';
						return ;
					}
				} 
				else {
					cnt++;
					vis[u1 * 2 + 1] = 1;
					check[dep[u1 * 2 + 1]] = 1;
					//dbg(i,j,u1);
				}
			}
		}
	}
	cout << cnt << '\n';
	//dbg(cnt);
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