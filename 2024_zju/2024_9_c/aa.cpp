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
struct node{
	int l, r, val;
};
constexpr int Max = 1e18;
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	auto check = [&](int x) -> bool{
		if(abs(a[1] - a[2]) > x)return false;
		set<int> s;
		s.insert(a[1]);
		for(int i = 3; i <= n; i++){
			auto it = s.lower_bound(a[i] - x);
			int ok = 0;
			if(it != s.end() && (*it) <= a[i] + x)ok = 1;
			if(abs(a[i] - a[i - 1]) > x)s.clear();
			if(ok)s.insert(a[i - 1]);
			if(s.empty())return false;
		}
		return true;
	};
	int l = 0, r = 1e9;
	int ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	cout << ans << '\n';
	vector<int> res(n + 1);
	res[2] = 1;
	int ok = 0;
	auto dfs = [&](auto self, int now, int l, int r) -> void{
		if(ok)return ;
		if(now == n + 1){
			ok = 1;
			for(int i = 2; i <= n; i++){
				if(res[i])cout << 'R';
				else cout << 'L';
			}
			cout << '\n';
			return ;
		}
		if(abs(a[now] - l) <= ans){
			res[now] = 0;
			self(self, now + 1, a[now], r);
		}
		if(abs(a[now] - r) <= ans){
			res[now] = 1;
			self(self, now + 1, l, a[now]);
		}
	};
	dfs(dfs, 3, a[1], a[2]);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
