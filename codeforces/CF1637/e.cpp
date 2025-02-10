#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
	set<pair<int, int>> s;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		s.insert({x, y});
		s.insert({y, x});
	}
	map<int, int> mp;
	for(int i = 1; i <= n; i++){
		mp[a[i]]++;
	}
	vector<vector<int>> cnt(n + 1);
	for(auto [x, y] : mp){
		cnt[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		reverse(cnt[i].begin(), cnt[i].end());
	}
	vector<int> use;
	for(int i = 1; i <= n; i++){
		if(!cnt[i].empty()){
			use.push_back(i);
		}
	}
	int ans = 0;
	for(auto i : use){
		for(auto x : cnt[i]){
			for(auto j : use){
				if(j > i)break;
				for(auto y : cnt[j]){
					if(y == x || s.count({x, y}))continue;
					ans = max(ans, (i + j) * (x + y));
					break;
				}
			}
		}
	}
	cout << ans << '\n';
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