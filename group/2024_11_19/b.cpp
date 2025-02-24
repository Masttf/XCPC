#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
	int n, b, d; cin >> n >> b >> d;
	int mx = (1 << b) - 1;
	vector<int> ans(n + 1);
	auto check = [&](int pos) -> bool{
		for(int i = 1; i < pos; i++){
			int val = ans[i] ^ ans[pos];
			int cnt = 0;
			while(val){
				cnt++;
				val -= lowbit(val);
			}
			if(cnt < d)return false;
		}
		return true;
	};
	auto dfs = [&](auto self, int now, int last) -> void{
		if(now == n + 1){
			int flag = 0;
			for(int i = 1; i <= n; i++){
				flag++;
				cout << ans[i] << " \n"[flag == 10];
				flag %= 10;
			}
			exit(0);
		}
		for(int i = last; i <= mx; i++){
			ans[now] = i;
			if(check(now)){
				self(self, now + 1, i + 1);
			}
			
		}
	};
	dfs(dfs, 1, 0);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)solve();
	return 0;
}