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
    int ans = 0;
	vector<int> cnt(n + 1);
	vector<int> b(n + 1);
	int mx = 0;
	for(int i = 1; i <= n; i++){
		ans += a[i];
		cnt[a[i]]++;
		if(cnt[a[i]] >= 2)mx = max(mx, a[i]);
		b[i] = mx;
	}
	mx = 0;
	cnt.assign(n + 1, 0);
	for(int i = 1; i <= n; i++){
		ans += b[i];
		cnt[b[i]]++;
		if(cnt[b[i]] >= 2)mx = max(mx, b[i]);
		ans += (n - i + 1) * mx;
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
/*
由a产生的第一次b数组是
单调不减的
然后每次操作是连续的会右移一次
*/