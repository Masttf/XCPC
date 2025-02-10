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
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> l(n + 5), r(n + 5);
	for(int i = 1; i <= n; i++){
		if(a[i] > a[i - 1])l[i] = l[i - 1] + 1;
		else l[i] = 1;
	}
	for(int i = n; i >= 1; i--){
		if(a[i] > a[i + 1])r[i] = r[i + 1] + 1;
		else r[i] = 1;
	}
	vector<int> pre(n + 5), suf(n + 5);
	for(int i = 1; i <= n; i++){
		pre[i] = max({pre[i - 1], l[i], r[i]});
	}
	for(int i = n; i >= 1; i--){
		suf[i] = max({suf[i + 1], l[i], r[i]});
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(l[i] > 1 && r[i] > 1){
			int mx = max(l[i], r[i]);
			int mx2 = max(pre[i - 1], suf[i + 1]);
			if(mx2 >= mx)continue;
			if(l[i] - l[i] % 2 >= r[i])continue;
			if(r[i] - r[i] % 2 >= l[i])continue;
			ans++;
		}
	}
	cout << ans << '\n';
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