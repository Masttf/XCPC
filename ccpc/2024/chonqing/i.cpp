#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

const int mod = 998244353;

void solve(){
	vector <int> a(15);
	for (int i = 1;i <= 9;i++) cin >> a[i];
	if (a[1] <= a[2]) {
		a[3] += a[1];
		a[2] -= a[1];
		a[1] = 0;
		int ans = 1;
		for (int i = 1;i <= 10;i++) {
			for (int j = 1;j <= a[i];j++) {
				ans = (ans * i);
				ans %= mod;
			}
		}
		cout << ans << '\n';
	}
	else {
		int ans = 1;
		int dis = a[1] - a[2];
		if (dis % 3 == 0) {
			a[3] += a[2];
			a[2] = 0;
			a[3] += dis / 3;
			a[1] = 0;
		}
		else if (dis % 3 == 1) {
			a[3] += a[2];
			a[2] = 0;
			a[3] += dis / 3;
			a[1] = 0;
			if (a[3]) {
				a[4]++;
				a[3]--;
			}
			else {
				int ok = 0;
				for (int j = 2;j <= 9;j++) {
					if (a[j]) {
						a[j]--;
						a[j + 1]++;
						ok = 1;
						break;
					}
				}
				if (!ok) a[1] = 1;
			}
		}
		else {
			a[3] += a[2];
			a[2] = 0;
			a[3] += dis / 3;
			a[1] = 0;
			a[2]++;
		}
		for (int i = 1;i <= 10;i++) {
			for (int j = 1;j <= a[i];j++) {
				ans = (ans * i);
				ans %= mod;
			}
		}
		cout << ans << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	 cin >> t;
	while(t--)solve();
	return 0;
}