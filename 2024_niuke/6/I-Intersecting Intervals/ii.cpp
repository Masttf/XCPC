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
	int n, m; cin >> n >> m;
	vector a(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)cin >> a[i][j];
	}
	vector<int> dp_l(m + 1);
	vector<int> dp_r(m + 1);
	vector<int> dp_b(m + 1);
	vector<int> f_l(m + 1);
	vector<int> f_r(m + 1);
	vector<int> f_b(m + 1);
	for(int i = 1; i <= n; i++){
		swap(dp_l, f_l);
		swap(dp_r, f_r);
		swap(dp_b, f_b);
		int sum = 0;
		int mx = 0;
		int val = -Max;
		for(int j = 1; j <= m; j++){
			sum += a[i][j];
			val = max(val, max({f_l[j], f_r[j], f_b[j]}) + mx);
			dp_r[j] = val + sum;
			mx = max(mx, -sum);

		}
		
		sum = 0;
		mx = 0;
		val = -Max;
		for(int j = m; j >= 1; j--){
			sum += a[i][j];
			val = max(val, max({f_l[j], f_r[j], f_b[j]}) + mx);
			dp_l[j] = val + sum;
			mx = max(mx, -sum);
		}
		vector<int>res(m + 1);
		for(int j = 1; j <= m; j++){
			res[j] = a[i][j];
			res[j] = max(res[j], res[j - 1] + a[i][j]);
		}
		vector<int>res2(m + 2);
		for(int j = m; j >= 1; j--){
			res2[j] = a[i][j];
			res2[j] = max(res2[j], res2[j + 1] + a[i][j]);
		}
		for(int j = 1; j <= m; j++){
			dp_b[j] = max(dp_r[j], dp_l[j]);
			//dbg(res[j], res2[j]);
			dp_b[j] = max(dp_b[j], f_b[j] + res[j] + res2[j + 1]);
		}
	}
	int ans = -Max;
	for(int i = 1; i <= m; i++){
		ans = max({ans, dp_l[i], dp_r[i], dp_b[i]});
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