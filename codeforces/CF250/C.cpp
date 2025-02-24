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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> cnt(k + 1);
	for(int i = 1; i <= n; i++){
		int j = i;
		while(j <= n && a[j] == a[i]){
			j++;
		}
		int pre = i - 1;
		int suf = j;
		if(pre >= 1)cnt[a[i]]++;
		if(suf <= n)cnt[a[i]]++;
		if(pre >= 1 && suf <= n){
			cnt[a[i]] -= (a[pre] != a[suf]);
		}
		i = j - 1;
	}
	int mx = 1;
	for(int i = 2; i <= k; i++){
		// dbg(i, cnt[i]);
		if(cnt[mx] < cnt[i]){
			mx = i;
		}
	}
	cout << mx << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}