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
void err(T arg, Ts ... args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int mod = 1e9 + 7;
void solve(){
	int m; cin >> m;
	vector<int> cnt(10);
	for(int i = 0; i < 10; i++)cin >>cnt[i];
	if(m == 1){
		for(int i = 0; i < 10; i++){
			if(cnt[i]){
				cout << i << '\n';
				return ;
			}
		}
	}
	vector p(10, vector<int>(60));
	p[0][0] = 10;
	for(int i = 1; i <= 32; i++){
		p[0][i] = p[0][i - 1] * p[0][i - 1] % mod;
	}
	for(int i = 1; i < 10; i++)p[i][0] = i;
	for(int j = 1; j < 10; j++){
		for(int i = 1; i <= 32; i++){
			p[j][i] = (p[j][i - 1] * p[0][i - 1]) % mod + p[j][i - 1];
			p[j][i] %= mod;
		}
	}
	
	auto pw = [&](int x) -> int{
		int res = 1;
		for(int i = 31; i >= 0; i--){
			if(x >> i & 1){
				res = res * p[0][i] % mod;
			}
		}
		return res;
	};
	int ans = 0;
	for(int i = 1; i < 10; i++){
		if(cnt[i]){
			cnt[i]--;
			m--;
			ans = i * pw(m) % mod;
			break;
		}
	}
	auto add = [&](int x, int d) -> void{
		if(x == 0)return ;
		int res = pw(m - d);
		int t = 0;
		int num = d;
		for(int i = 31; i >= 0; i--){
			if(d >> i & 1){
				num -= (1ll << i);
				t += p[x][i] * pw(num) % mod;
				t %= mod;
			}
		}
		res = res * t % mod;
		ans = (ans + res) % mod;
	};
	for(int i = 0; i < 10; i++){
		if(m == 0)break;
		add(i, min(cnt[i], m));
		m -= min(cnt[i], m);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; cin >> t;
	while(t--)solve();
	return 0;
}