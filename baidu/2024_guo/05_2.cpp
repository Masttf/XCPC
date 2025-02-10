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
	int n, K, D; cin >> n >> K >> D;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector st_max(21, vector<int>(n + 1));
	vector st_min(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st_max[0][i] = a[i];
		st_min[0][i] = a[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i + (1ll << k) <= n + 1; i++){
			st_max[k][i] = max(st_max[k - 1][i], st_max[k - 1][i + (1ll << (k - 1))]);
			st_min[k][i] = min(st_min[k - 1][i], st_min[k - 1][i + (1ll << (k - 1))]);

		}
	}
	auto get_max = [&](int l, int r) -> int{
		int len = r - l + 1;
		int d = __lg(len);
		return max(st_max[d][l], st_max[d][r - (1ll << d) + 1]);
	};
	auto get_min = [&](int l, int r) -> int{
		int len = r - l + 1;
		int d = __lg(len);
		return min(st_min[d][l], st_min[d][r - (1ll << d) + 1]);
	};
	int ans1 = Max, ans2 = 1, ans3 = 0;
	auto check = [&](int dd) -> int{
		int mi = a[1], mx = a[1];
		int cnt = 1;
		for(int i = 1; i <= n; i++){
			int tx = max(mx, a[i]);
			int ti = min(mi, a[i]);
			if(tx - ti <= dd){
				mx = tx;
				mi = ti;
			}else{
				cnt++;
				mx = mi = a[i];
			}
		}
		return cnt;
	};
	int l = 0, r = 1e9;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid) <= K){
			r = mid - 1;
			ans1 = mid;
		}else l = mid + 1;
	}
	ans2 = check(D);

	vector<int> dp(n + 1);
	for(int i = 1; i <= n; i++){
		 l = i, r = n;
		 int res = i;
		 while(l <= r){
		 	int mid = (l + r) >> 1;
		 	int mx = get_max(i, mid);
		 	int mi = get_min(i, mid);
		 	if(mx - mi <= D){
		 		res = mid;
		 		l = mid + 1;
		 	}else r = mid -1;
		 }
		 dp[i] = res;
	}
	vector st(21, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = dp[i];
	}
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i <= n; i++){
			st[k][i] = st[k - 1][st[k - 1][i]];
		}
	}
	for(int i = 1; i <= n; i++){
		int now = i;
		for(int j = 20; j >= 0; j--){
			if(K >> j & 1){
				now = st[j][now];
			}
		}
		ans3 = max(ans3, now - i + 1);
	}
	cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}