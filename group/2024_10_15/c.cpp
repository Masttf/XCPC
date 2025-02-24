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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
	int add = 0;
	vector<pair<int, int>>res;
	vector<int> b = a;
	for(int i = n; i >= 1; i--){
		a[i] += add;
		if(a[i] <= 0)continue;
		res.push_back({a[i], i});
		add -= a[i];
	}
	vector<int> cnt(1);
	vector<int> sum(1);
	for(auto [x, y] : res){
		// dbg(x, y);
		cnt.push_back(cnt.back() + x);
		sum.push_back(sum.back() + x * y);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int pos = lower_bound(cnt.begin(), cnt.end(), b[i]) - cnt.begin();
		ans += sum[pos - 1];
		b[i] -= cnt[pos - 1];
		ans += b[i] * res[pos - 1].second;
		//dbg(i, pos, ans);
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}