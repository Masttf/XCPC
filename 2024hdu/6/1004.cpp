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
	int l, r, f;
	bool operator < (const node &y)const{
		if(l != y.l)return l < y.l;
		return f < y.f;
	}
};
void solve(){
	int n, m; cin >> n >> m;
	vector<int>p;
	vector<pair<int,int>>a(n + 1), b(m + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
		p.push_back(a[i].first + 1);
		p.push_back(a[i].second - 1);
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i].first >> b[i].second;
		p.push_back(b[i].first);
		p.push_back(b[i].second);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	int N = p.size();
	vector<int>cnt(N + 5);
	for(int i = 1; i <= n; i++){
		auto[l, r] = a[i];
		if(l == r)continue;
		l = get(l + 1);
		r = get(r - 1);
		//dbg(l, r);
		cnt[l]++;
		cnt[r + 1]--;
	}
	for(int i = 1; i <= N; i++)cnt[i] += cnt[i - 1];
	for(int i = 1; i <= N; i++)cnt[i] += cnt[i - 1];
	// for(int i = 1; i <= N; i++){
	// 	dbg(i, cnt[i]);
	// }
	vector<node>res;
	for(int i = 1; i <= n; i++){
		res.push_back({a[i].first, a[i].second, 1});
	}
	for(int i = 1; i <= m; i++){
		auto [l, r] = b[i];
		l = get(l);
		r = get(r);
		// dbg(l, r);
		// dbg(cnt[r] - cnt[l - 1]);
		if(cnt[r] - cnt[l - 1] == 0){
			// dbg(b[i].first, b[i].second);
			res.push_back({b[i].first, b[i].second, 0});
		}
	}
	sort(res.begin(), res.end());
	int ok = 1;
	int last = 0;
	for(auto [l, r, f] : res){
		if(f == 0){
			last = max(last, r + 2 * (r - l));
		}else{
			if(r > last)ok = 0;
		}
	}
	if(ok)cout << "Yes\n";
	else cout << "No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}