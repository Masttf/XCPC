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
void solve(){
	int n, m; cin >> n >> m;
	if(m == n - 2){
		cout << -1 << '\n';
		return ;
	}
	vector<int>ans(n + 1);
	for(int i = 1; i <= n; i++)ans[i] = i;
	auto get = [&](int x) -> void{
		int d = x / 3;
		for(int i = 1; i  <= d; i++){
			int t = i * 3;
			ans[t - 2] = d - i + 1;
			ans[t - 1] = 2 * d - i + 1;
			ans[t] = 3 * d - i + 1;
		}
	};
	if(m == 0){
		if(n % 3 == 0){
			get(n);
		}else if(n % 3 == 1){
			get(n);
			for(int i = n - 1; i >= 1; i--){
				ans[i + 1] = ans[i];
			}
			ans[1] = n;
		}else{
			get(n);
			for(int i = n - 2; i >= 1; i--){
				ans[i + 1] = ans[i];
			}
			ans[1] = n - 1;
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	int t = (n - m) % 3;
	if(t == 0){
		get(n - m);
		for(int i = 1; i <= n; i++){
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}else if(t == 1){
		if(n - m == 4){
			swap(ans[1], ans[2]);
		}else{
			get(n - m - 1);
			for(int i = n - m - 1; i >= 1; i--){
				ans[i + 1] = ans[i];
			}
			ans[1] = n - m;
			swap(ans[n - m - 1], ans[n - m - 2]);
		}
		for(int i = 1; i <= n; i++){
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}else{
		get(n - m - 2);
		for(int i = n - m - 2; i >= 1; i--){
			ans[i + 1] = ans[i];
		}
		ans[1] = n - m - 1;
		for(int i = 1; i <= n; i++){
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}