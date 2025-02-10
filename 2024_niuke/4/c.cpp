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
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)cin >> a[i];
	vector<int> vis(n + 1);
	vector<int> cnt(n + 1);
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		int len = 0;
		int now = i;
		while(!vis[now]){
			vis[now] = 1;
			len++;
			now = a[now];
		}
		cnt[len]++;
	}
	int ans = 0;
	for(int i = n; i > 4; i--){
		//dbg(i, cnt[i]);
		if(i % 3 == 1 || i % 3 == 0){
			ans += (i / 3) * cnt[i];
		}else{
			ans += (i / 3) * cnt[i];
			cnt[2] += cnt[i];
		}
	}
	if(n >= 4)ans += cnt[4];
	if(n >= 3)ans += cnt[3];
	if(n >= 2)ans += (cnt[2] + 1) / 2;
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