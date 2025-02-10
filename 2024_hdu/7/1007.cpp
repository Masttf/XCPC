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
	int n, m, k;cin >> n >> m >> k;
	vector<int>a(n + 1);
	vector<int>p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p.push_back(a[i]);
		p.push_back(a[i] - k);
		p.push_back(a[i] + k);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin();
	};
	vector<int>l1(n + 1);
	vector<int>l2(n + 1);
	int sz = p.size();
	vector<int>tr(sz * 4);
	auto updata = [&](auto self, int l, int r, int x, int val, int p) -> void{
		if(l == r){
			tr[p] = val;
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, val, p << 1);
		else self(self, mid + 1, r, x, val, p << 1 | 1);
		tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
	};
	auto query = [&](auto self, int l, int r, int x, int y, int p) -> int{
		if(x <= l && r <= y)return tr[p];
		int res = 0;
		int mid = (l + r) >> 1;
		if(x <= mid)res = max(res, self(self, l, mid, x, y, p << 1));
		if(y > mid)res = max(res, self(self, mid + 1, r, x, y, p << 1 | 1));
		return res;
	};
	for(int i = 1; i <= n; i++){
		l1[i] = query(query, 1, sz, get(a[i] - k), get(a[i]), 1);
		l2[i] = query(query, 1, sz, get(a[i]), get(a[i] + k), 1);
		updata(updata, 1, sz, get(a[i]), i, 1);
	}
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		vector dp(2, vector<int>(n + 1));
		for(int j = l; j <= r; j++){
			dp[0][j] = max(dp[1][j - 1], dp[0][j - 1]);
			dp[1][j] = 1;
			if(l1[j] >= l)dp[1][j] = max(dp[1][j], dp[1][l1[j]] + 1);
			if(l2[j] >= l)dp[1][j] = max(dp[1][j], dp[1][l2[j]] + 1);
		}
		cout << r - l + 1 - max(dp[0][r], dp[1][r]) << '\n';
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