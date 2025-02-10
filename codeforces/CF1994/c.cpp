#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)cin>>a[i];
    vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++)pre[i] = pre[i-1] + a[i];
    int ans = 0;
	vector<int> dp(n + 1);
	for(int i = n; i >= 1; i--){
		int l = i, r = n;
		int t = i - 1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(pre[mid] - pre[i - 1] <= x){
				t = mid;
				l = mid + 1;
			}else r = mid -1;
		}
		//dbg(i, t);
		int res = (t - i + 1);
		if(t + 2 <= n) res += dp[t + 2];
		dp[i] = res;
		ans += res;
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}