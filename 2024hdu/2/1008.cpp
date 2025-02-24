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
const int mod = 1e9 + 7;
vector<int>t[maxn];
int dep[maxn],mx,zj1,zj2,ans[maxn],val1[maxn],val2[maxn],val[maxn];
int n,m;

int qmi(int a,int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}

void dfs(int u,int f) {
	//dbg(u,ans[u]);
	if (ans[u] > mx) {
		mx = ans[u];
		zj1 = u;
	}
	for (auto i : t[u]) {
		if (i == f) continue;
		ans[i] = (ans[u] + val[i]);
		dfs(i,u);
	}
}

int cnt[maxn],cnt1[maxn];
int mx1,mx2,Ans;

void dfs2(int u,int f) {
	//dbg(u,cnt[u],cnt1[u]);
	if (cnt[u] > mx1) {
		mx1 = cnt[u];
		mx2 = cnt1[u];
		Ans = ans[u];
		zj1 = u;
	}
	else if (cnt[u] == mx1 && cnt1[u] > mx2) {
		mx1 = cnt[u];
		mx2 = cnt1[u];
		Ans = ans[u];
		zj1 = u;
	}
	for (auto i : t[u]) {
		if (i == f) continue;
		ans[i] = (ans[u] + val[i]) % mod;
		int siz = t[i].size();
		if (siz == 1) {
			cnt1[i] = cnt1[u] + 1;
			cnt[i] = cnt[u];
		}
		else {
			cnt[i] = cnt[u] + siz; 
			cnt1[i] = cnt1[u];
		}
		dfs2(i,u);
	}
}

void solve(){
	mx = 0;
	mx1 = 0,mx2 = 0,Ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		t[i].clear();
		cnt[i] = cnt1[i] = 0;
	}
	for (int i = 1;i < n;i++) {
		int u,v;cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	//dbg(zj1,zj2);
	for (int i = 2;i <= n;i++) {
		if (i == 2) {
			val1[i] = qmi(2,m - 1);
			val2[i] = 0;
			continue;
		}
		if (m == 2) {
			val1[i] = 2;
			val2[i] = i - 2;
		}
		else {
			val1[i] = ((qmi(2,m - 1) - 2 + mod) % mod * i % mod - ((qmi(2,m - 1) - 4 + mod) % mod) + mod) % mod;
			val2[i] = i - 2;
		}
		//dbg(i,val1[i],val2[i]);
	}
	for (int i = 1;i <= n;i++) {
		int siz = t[i].size();
		if (siz == 1) val[i] = 1;
		else {
			if (m == 1) val[i] = siz;
			else val[i] = (val1[siz] * 2 % mod + val2[siz] * 3 % mod) % mod; 
		}
		//dbg(i,val[i]);
	}
	if (m <= 25) {
		for (int i = 2;i <= n;i++) {
			if (i == 2) {
				val1[i] = qmi(2,m - 1);
				val2[i] = 0;
				continue;
			}
			if (m == 2) {
				val1[i] = 2;
				val2[i] = i - 2;
			}
			else {
				val1[i] = (qmi(2,m - 1) - 2) * i - (qmi(2,m - 1) - 4);
				val2[i] = i - 2;
			}
		}
		for (int i = 1;i <= n;i++) {
			int siz = t[i].size();
			if (siz == 1) val[i] = 1;
			else {
				if (m == 1) val[i] = siz;
				else val[i] = (val1[siz] * 2 + val2[siz] * 3); 
			}
			//dbg(i,val[i]);
		}
		mx = 0;
		ans[1] = 1;
		dfs(1,0);
		//dbg(zj1);
		ans[zj1] = 1;
		mx = 0;
		dfs(zj1,0);
		cout << mx << '\n';
		return ;
	}	
	mx1 = mx2 = 0;
	if (t[1].size() == 1) {
		cnt1[1] = 1;
		cnt[1] = 0;
	}
	else {
		cnt[1] = t[1].size();
		cnt1[1] = 0;
	}
	dfs2(1,0);
	mx1 = mx2 = 0;
	if (t[zj1].size() == 1) {
		cnt1[zj1] = 1;
		cnt[zj1] = 0;
	}
	else {
		cnt[zj1] = t[zj1].size();
		cnt1[zj1] = 0;
	}
	dfs2(zj1,0);
	cout << Ans << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}