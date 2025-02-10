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
constexpr int Max = 1e18;
void solve(){
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i++){
    	a[i] = s[i] - '0';
    	pre[i] = pre[i - 1];
    	if(a[i] == 0)pre[i]++;
    }
    vector dp(k + 1, vector<int>(n + 1));
    vector<int> mi(k + 1, Max);
    auto check = [&](int x) -> bool{
    	//dbg(x);
    	for(int i = 0; i <= k; i++){
    		mi[i] = Max;
    		for(int j = 0; j <= n; j++){
    			dp[i][j] = Max;
    		}
    	}
    	int l = 1;
    	dp[0][0] = 0;
    	for(int i = 1; i <= n; i++){
    		for(int j = 0; j <= k; j++){
    			dp[j][i] = dp[j][i - 1];
    		}
    		if(i == x){
    			mi[0] = min(mi[0], 0ll);
    		}
    		while(i - l >= x){
    			if(a[l] == 0){
    				for(int j = 0; j < k; j++){
	    				mi[j] = min(mi[j], dp[j][l - 1] - pre[l]);
	    			}
    			}
    			l++;
    		}
    		for(int j = 1; j <= k; j++){
    			dp[j][i] = min(dp[j][i], pre[i] + mi[j - 1]);
    		}
    	}
    	return dp[k][n] <= m;
    };
    int ans = -1;
    int l = 1, r = n;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(check(mid)){
    		ans = mid;
    		l = mid + 1;
    	}else r = mid - 1;
    }
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