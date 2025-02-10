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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

   	auto check = [&](int x) -> pair<int, int>{
   		for(int i = 1; i <= n; i++){
   			a[i] -= x;
   		}
   		vector dp(n + 1, vector<int>(2, 0));
   		vector cnt(n + 1,vector<int>(2, 0));
   		for(int i = 1; i <= n; i++){
   			dp[i][1] = dp[i - 1][0] + a[i];
   			cnt[i][1] = cnt[i - 1][0] + 1;
   			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
   			if(dp[i - 1][1] == dp[i][0]){
   				cnt[i][0] = max(cnt[i][0], cnt[i - 1][1]);
   			}
   			if(dp[i - 1][0] == dp[i][0]){
   				cnt[i][0] = max(cnt[i][0], cnt[i - 1][0]);
   			}
   		}
   		int c = 0;
   		int sum = 0;
   		sum = max(dp[n][1], dp[n][0]);
   		if(dp[n][1] == sum) c = max(c, cnt[n][1]); 
   		if(dp[n][0] == sum) c = max(c, cnt[n][0]);
   		sum += k * x;
   		for(int i = 1; i <= n; i++){
   			a[i] += x;
   		}
   		return {c, sum};
   	};

   	int l = 1, r = 1e6;
   	int ans = -1e9;
   	while(l <= r){
   		int mid = (l + r) >> 1;
   		auto [c, sum] = check(mid);
   		if(c >= k){
   			ans = sum;
   			l = mid + 1;
   		}else r = mid - 1;
   	}
   	if(ans == -1e9)ans = check(0).second;
   	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}