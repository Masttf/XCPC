#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int Max = 1e18;
void solve(){
	int n; cin >> n;
	vector<int> a(2 * n + 2);
	vector<int> last(2 * n + 2, -1); 
	vector<int> nex(2 * n + 2);
	vector<int> pos(n + 1, -1);
	vector<pair<int, int>>res; 
	for(int i = 1; i <= 2 * n; i++){
		cin >> a[i];
		if(pos[a[i]] == -1){
			pos[a[i]] = i;
		}else{
			last[i] = pos[a[i]];
			nex[pos[a[i]]] = i;
			res.push_back({i - last[i] + 1, a[i]});
		}
	}
	res.push_back({2 * n + 2, 0});
	nex[0] = 2 * n + 1;
	last[2 * n + 1] = 0;
	pos[0] = 0;
	sort(res.begin(), res.end());
	vector dp(n + 1, vector<int>(2 * n + 2));
	for(int i = 0; i <= n; i++){
		int x = res[i].second;
		dp[x][pos[x]] = x;
		for(int j = pos[x] + 1; j <= nex[pos[x]]; j++){
			dp[x][j] = dp[x][j - 1] + x;
			if(j != nex[pos[x]] && last[j] != -1 && last[j] >= pos[x]){
				dp[x][j] = max(dp[x][j], dp[x][last[j] - 1] + dp[a[j]][j]);
			}
		}
	}
	cout << dp[0][2 * n + 1] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}