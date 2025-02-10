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
	string ans;
	int cnt = 0;
	mt19937 rng(random_device{}());
	while (cnt <= 10) {
		int x = rng() % 3;
		if (x == 0) ans += '?';
		else if (x == 1) ans += '(';
		else ans += ')';
		cnt++;
	}
	cout << ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}