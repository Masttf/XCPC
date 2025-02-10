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
	int n;cin >> n;
	vector a(2,vector<char>(n + 5));
	for (int i = 1;i <= n;i++) {
		cin >> a[0][i];
	}
	for (int i = 1;i <= n;i++) {
		cin >> a[1][i];
	}
	a[0][n + 1] = a[1][n + 1] = 'W';
	int st = -1;
	int mx = 0,ans = 0,cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (a[0][i] == 'R' && a[1][i] == 'R') {
			if (st == -1) {
				st = 2;
				ans = 2;
				continue;
			}	
			else {
				ans += 2;
				if (st == 0 || st == 1) cnt++;
			}
		}
		else if (a[0][i] == 'R' && a[1][i] == 'W') {
			if (st == -1) {
				st = 0;
				ans = 1;
				continue;
			}
			else {
				if (st == 2) {
					cnt = 0;
					ans++;
					st = 0;
				}
				else if (st == 0) {
					if (cnt % 2 == 0) ans++;
					cnt = 0; 
				}
				else if (st == 1) {
					if (cnt == 0) {
						cnt = 0;
						mx = max(mx,ans);
						ans = 1;
						st = 0;
						continue;
					}
					if (cnt % 2 == 1) ans++;
					cnt = 0;
				}
			}
		}
		else if (a[0][i] == 'W' && a[1][i] == 'R') {
			if (st == -1) {
				st = 1;
				ans = 1;
				continue;
			}
			else {
				if (st == 2) {
					cnt = 0;
					ans++;
					st = 1;
				}
				else if (st == 0) {
					if (cnt  == 0) {
						cnt = 0;
						mx = max(mx,ans);
						ans = 1;
						st = 1;
						continue;
					}
					if (cnt % 2 == 1) ans++;
					cnt = 0; 
				}
				else if (st == 1) {
					if (cnt % 2 == 0) ans++;
					cnt = 0;
				}
			}
		}
		else {
			mx = max(mx,ans);
			cnt = 0;
			ans = 0;
			st = -1;
		}
	}
	if (ans != 0) ans--;
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}