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
    sort(a.begin() + 1, a.end());
	vector<int> res;
	res.push_back(0);
	for(int i = 1; i <= n; i++){
		int j = i;
		while(j <= n && a[i] == a[j]){
			j++;
		}
		res.push_back(j - i);
		i = j - 1;
	}
	int N = res.size() - 1;
	vector dp(N + 1, vector<int>(N + 1, N));
	dp[0][0] = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= i; j++){
			if(j)dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
			if(j >= res[i]) dp[i][j - res[i]] = min(dp[i][j - res[i]], dp[i - 1][j]);
		}
	}
	int ans = N;
	for(int i = 0; i <= N; i++){
		ans = min(ans, dp[N][i]);
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
如果有多个相同的Bob吃了是亏了，因为Alice还是可以吃这个
对于Alice 来说肯定是选每次能选的最小值最优
现在就是Bob的选择问题那么就是重复的问题
对于重复块， Bob要么都不拿要么一下全拿走

定义dp ij 表示前i个物品，Bob还有j次没有操作的Alice拿到的最小值

*/