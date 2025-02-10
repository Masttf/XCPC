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


int m,k,h;
bool check(int x) {
	if (x >= h) return 1;
	if (x < m) return 0;
	if (m == k) return 1;
	int st = (x - m);
	int need = st / (m - k);
	int ans = x + (1 + need) * k;
	if (ans >= h) return 1;
	else return 0;
}

void solve(){
	cin >> m >> k >> h;
	int l = 0,r = 1e9;
	int ans = r;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = min(ans,mid);
		}
		else l = mid + 1;
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