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

struct node {
	int color;
	int x;
	friend bool operator< (node a, node b) {
		return a.x < b.x;
	}
};
int n, m, k, w;
void solve(){
	
	cin >> n >> m >> k >> w;
	vector<node> v;
	v.emplace_back(0, 0);
	v.emplace_back(0, w + 1);
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		v.emplace_back(1, x);
	}
	for(int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		v.emplace_back(0, x);
	}
	sort(v.begin(), v.end());

	vector<int> ans;
	int ok = 1;
	auto get = [&](int l, int r) -> void{
		if(l > r)return ;
		// dbg(l, r);
		// for(auto i = l; i <= r; i++){
		// 	cout << v[i].x << ' ';
		// }
		// cout << endl;
		vector<pair<int, int>> tmp;
		int last = -1;
		for(int i = l; i <= r; ++i) {
			if(last == -1 || last < v[i].x){
				tmp.push_back({v[i].x, v[i].x + k - 1});
				last = v[i].x + k - 1;
			}
		}
		// dbg(last);
		if(last >= v[r + 1].x){
			int d = last - v[r + 1].x + 1;
			int sz = tmp.size();
			for(int i = sz - 1; i >= 1; i--){
				if(d == 0)break;
				auto &[ll, rr] = tmp[i];
				ll -= d;
				rr -= d;
				d = max(0ll, tmp[i - 1].second - tmp[i].first + 1);
			}
			tmp[0].first -= d;
			tmp[0].second -= d;
		}
		if(tmp[0].first <= v[l - 1].x){
			ok = 0;
			return ;
		}
		for(auto [ll, rr] : tmp){
			ans.push_back(ll);
		}
	};
	const int sz = v.size();
	int last = -1;
	for(int i = 0 ; i < sz; i++){
		if(v[i].color == 0){
			if(last != -1){
				get(last + 1, i - 1);
			}
			last = i;
		}
	}
	if(ok){
		cout << ans.size() << '\n';
		for(auto x : ans){
			cout << x << ' ';
		}
		cout << '\n';
		return ;
	}
	cout << -1 << '\n';
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