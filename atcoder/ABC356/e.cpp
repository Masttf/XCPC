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
    int mx = *max_element(a.begin() + 1, a.end());
	int ans = 0;
	vector<int> cnt(mx + 1);
	for(int i = 1; i <= n; i++){
		cnt[a[i]]++;
	}
	vector<int> pre(mx + 1);
	for(int i = 1; i <= mx; i++){
		pre[i] = pre[i - 1] + cnt[i];
	}
	for(int i = 1; i <= mx; i++){
		if(!cnt[i])continue;
		ans += cnt[i] * (cnt[i] - 1) / 2;
		for(int j = i; j <= mx; j += i){
			int r = min(mx + 1, j + i);
			int l = j - 1;
			if(j == i) l = j;
			ans += (pre[r - 1] - pre[l]) * (j / i) * cnt[i];
		}
		// dbg(i, ans);
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
/*
n^2 -> nlog?
*/