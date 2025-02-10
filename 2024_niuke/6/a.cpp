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

struct node {
	int v,w;
};
const int maxn = 2e5 + 5;
vector<node>t[maxn];
int dep[maxn];
double res[maxn];
vector<char>s;
int cnt;
double val;

void dfs(int u,int f) {
	if ((int)t[u].size() == 1 && u != 1) {		
		res[u] = val;
		//cout << fixed << setprecision(12) << res[u] << '\n';
		return ;
	}	
	if (dep[u] % 2 == 0) res[u] = 1.0;
	for (auto i : t[u]) {
		if (i.v == f) continue;
		//dbg(i.v,u);
		double pre = val;
		if (i.w == 0) {
			s.push_back('0');
			int len = dep[u];
			double now = cnt * 1.0 / len;
			val = min(val,now);
			//dbg(val);
		}
		else {
			s.push_back('1');
			int len = dep[u];
			cnt++;
			double now = cnt * 1.0 / len;
			val = min(val,now);
		}
		dep[i.v] = dep[u] + 1;
		dfs(i.v,u);
		s.pop_back();
		if (i.w == 0) {
			val = pre;
		}
		else {
			val = pre;
			cnt--;
		}
		if (dep[u] % 2) {
			res[u] = max(res[u],res[i.v]);
		}	
		else {
			res[u] = min(res[u],res[i.v]);
		}
	}
}

void solve(){
	cnt = 0;
	val = 1.0;
	int n;cin >> n;
	for (int i = 1;i <= n;i++) {
		t[i].clear();
		res[i] = 0;
	}
	for (int i = 1;i < n;i++) {
		int u,v,w;cin >> u >> v >> w;
		t[u].push_back({v,w});
		t[v].push_back({u,w});
	}
	dep[1] = 1;
	dfs(1,0);
	cout << fixed << setprecision(12) << res[1] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}