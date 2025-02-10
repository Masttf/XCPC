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
	int n, m, k;cin >> n >> m >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++)pre[i] = pre[i-1] + a[i];
	int ans = 0;
	for(int i = 1; i <= k; i++){
		ans += a[i] * (n - i + 1);
	}
	int sum = 0;
	int pos = upper_bound(a.begin() + 1, a.end(), m) - a.begin();
	int l = pos, r = k;
	int last = ans;
	int cnt = pre[k];
	int num = 0;
	while(r >= l){
		sum += cnt;
		last -= (n - r + 1) * a[r];
		last += m * (n + num - pos + 2);
		last += pre[l - 1] + num * m;
		ans = min(ans, last + sum);
		cnt -= a[r];
		cnt += m;
		r--;
		pos++;
		num++;
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