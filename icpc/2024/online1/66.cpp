#include <bits/stdc++.h>

using namespace std;
#define int long long
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ... Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve() {
	int n; cin >> n;
	vector<int> a(n + 1);
	vector st(21, vector<pair<int ,int>>(n + 1));
	int ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		st[0][i] = {a[i], i};
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1 << k) <= n + 1; i++){
			st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
		}
	}
	auto get = [&](int l, int r) -> pair<int ,int>{
		int d = __lg(r - l + 1);
		return max(st[d][l], st[d][r - (1 << d) + 1]);
	};
	auto dfs = [&](auto self, int l, int r) -> void{
		if(l >= r)return ;
		//dbg(l, r);
		ans += r - l + 1;
		int mx = get(l, r).first;
		vector<int>res;
		res.push_back(r + 1);
		while(r >= l){
			auto [mxx, pos] = get(l, r);
			if(mxx == mx){
				r = pos - 1;
				res.push_back(pos);
			}else break;
		}
		reverse(res.begin(),res.end());
		ans -= res.size() - 1;
		int last = l - 1;
		for(auto x : res){
			//ans += x - last - 1;
			//dbg(x, ans);
			self(self, last + 1, x - 1);
			last = x;
		}
	};
	dfs(dfs, 1, n);
	cout << ans << '\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}