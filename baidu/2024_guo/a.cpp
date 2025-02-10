#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int Max = 1e18;
void solve(){
	int n; cin >> n;
	vector<int>b(n + 1);
	for(int i = 1; i <= n; i++)cin >>b[i];
	vector a(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)cin >> a[i][j];
	}
	auto get = [&](int i, int j, int k) -> int{
		return max({b[i], b[j], b[k], a[i][j], a[i][k], a[j][k], a[i][j] * a[j][k] * a[i][k]});
	};
	int ans = -Max;
	int block = n / 3;
	vector<int>cnt(n + 1);
	vector temp(block + 1, vector<int>());
	auto dfs = [&](auto self, int now, int val) -> void{
		if(now == n + 1){
			ans = max(ans, val);
			return ;
		}
		for(int i = 1; i <= block; i++){
			if(cnt[i] == 3)continue;
			cnt[i]++;
			int d = val;
			temp[i].push_back(now);
			if(cnt[i] == 3){
				d += get(temp[i][0], temp[i][1], temp[i][2]);
			}
			self(self, now + 1, d);
			temp[i].pop_back();
			cnt[i]--;
		}
	};
	dfs(dfs, 1, 0);
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}