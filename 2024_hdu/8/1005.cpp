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
	int l, r, k; cin >> l >> r >> k;
	if(k >= 64){
		cout << r - l + 1 << '\n';
		return ;
	}
	map<pair<int, int>, int>m;
	auto dfs = [&](auto self, int len ,int cnt) -> int{
		if(len <= 0 || cnt < 0)return 0;
		if(m.count({len, cnt}))return m[{len, cnt}];
		return m[{len, cnt}] = 1 + self(self, (len - 1) / 2, cnt - 1) + self(self, len / 2, cnt);
	};
	cout << dfs(dfs, r - l + 1, k) << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}