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
	int n, m; cin >> n >> m;
	vector<string> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<string> b(n + 1);
	for(int i = 1; i <= n; i++){
		b[i] = a[i];
		for(auto &x : b[i]){
			if(x >= 'A' && x <= 'Z') x = x - 'A' + 'a';
		}
	}
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = i;
	}
	auto check = [&](int x, int y) -> int{
		if(b[x] > b[y])return x;
		else if(b[x] == b[y])return y;
		else return y;
	};
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = check(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> int{
		int d = __lg(r - l + 1);
		return check(st[d][l], st[d][r - (1 << d) + 1]);
	};
	for(int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		cout << a[get(l, r)] << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)solve();
	return 0;
}