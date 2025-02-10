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
	int n; cin >> n;
	vector<pair<int, int>>a(n * n + 1);
	for(int i = 1; i <= n * n; i++){
		cin >> a[i].first >> a[i].second;
	}
	vector<int>ans(n * n + 1);
	vector<pair<int, int>>res;
	vector<int>cntx(n + 1);
	vector<int>cnty(n + 1);
	for(int i = 1; i <= n * n; i++){
		auto [xx, yy] = a[i];
		if(cntx[xx] > 2)continue;
		if(cnty[yy] > 2)continue;
		int ok = 1;

		set<pair<int, int>>m;
		for(auto [x, y] : res){
			int tx = xx - x;
			int ty = yy - y;
			pair<int, int>tep = {tx/__gcd(tx, ty), ty/__gcd(tx, ty)};
			if(tep.second < 0){
				tep.first = - tep.first;
				tep.second = -tep.second;
			}
			if(m.count(tep)){
				ok = 0;
				break;
			}
			m.insert(tep);
		}
		if(ok){
			cntx[xx]++;
			cnty[yy]++;
			ans[i] = 1;
			res.push_back(a[i]);
		}
	}
	for(int i = 1; i <= n * n; i++){
		cout << ans[i];
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}