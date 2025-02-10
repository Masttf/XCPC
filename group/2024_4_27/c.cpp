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
using i128 = __int128;
int p;

bool check(int x) {
	if ((i128)x * (i128)p > (i128)1e18) return 0;
	int a = x * p;
	int b = x;
	int now = 0;
	for (int i = 0;i <= 10000;i++) {
		int fm = a + i;
		int fz = b + i;
		if (fm % fz == 0) now++;
		else now = 0;
		if (now == 3) return 1;
	}
	return 0;
}

void solve(){
	//cin >> p;
	// int l = 1,r = 1e5;
	// int ans = 0;
	// while (l <= r) {
	// 	int mid = (l + r) >> 1;
	// 	if (check(mid)) {
	// 		l = mid + 1;
	// 		ans = max(ans,mid);
	// 	}
	// 	else {
	// 		r = mid - 1;
	// 	}
	// }
	// cout << ans << '\n';
	// for (int i = 1;i <= ans;i++) {
	// 	if (!check(i)) {
	// 		cout << "wa";
	// 		cout << i;
	// 		return ; 
	// 	}
	// }
	//if (p == 1) return;
	//cout << p << "::->";
	cin >> p;
	vector<int>ans;
	for (int i = 1;i <= 1000;i++) {
		if (check(i)) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) cout << i << ' ';
	cout << '\n';
	//cout << ans;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	// for (int i = 1;i <= 100;i++) {
	// 	p = i;
	// 	solve();
	// }
	while (t--) solve();
	return 0;
}