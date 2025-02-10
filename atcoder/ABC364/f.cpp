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
	int n, q;cin >> n >> q;

	vector<int>f(n + 5);
	for(int i = 1; i <= n + 4; i++)f[i] = i;
	int now = 0;
	auto find = [&](auto self, int x) -> int{
		//dbg(x);
		return f[x] == x ? x : f[x] = self(self, f[x]);
	};
	vector<array<int, 3>>a(q + 1);
	//find(find, 2e5);
	for(int i = 1; i<= q; i++){
		dbg(i);
		int l, r, c; cin >> l >> r >> c;
		a[i] = {c, l, r};
		for(int j = l; j < r; j++){
			
			j = find(find, j);
			if(i == 2){
				dbg(j);
			}
			if(j >= 2e5 - 10)dbg(j);
			if(j >= r)break;
			f[j] = j + 1;

		}
	}
	int ok = find(find, 1);
	if(ok >= n){
		sort(a.begin() + 1, a.end());
		int ans = 0;
		for(int i = 1; i <= n + 1; i++)f[i] = i;
		for(int i = 1; i <= q; i++){
			auto [c, l, r] = a[i];
			int flag = 1;
			for(int j = l; j <= r; j++){
				j = find(find, j);
				if(j > r)break;
				flag = 0;
				ans += c;
				if(j != r)f[j] = j + 1;
			}
			if(flag)ans += c;
			//dbg(i, ans);
		}
		cout << ans << '\n';
	}else{
		cout << -1 << '\n';
		return ;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}