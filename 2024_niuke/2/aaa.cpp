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
	int n,m,k;cin >> n >> m >> k;
	vector a(n + 5,vector<int>(m + 5));
	int x,y;cin >> x >> y;
	char op;cin >> op;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			a[i][j] = 0;
		}
	}
	int mi = (n + m);
	if (k < mi) {
		cout << "No" << '\n';
		return ;
	}
	
	if (a[x][y] == 1) {
		cnt = k - (n + m);
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				a[i][j] = 0;
			}
		}
		a[x][y] = 1;
		if (1) {
			int temp = y;
			while (temp > 0) {
				a[x][temp] ^= 1;
				temp -= 2;
			}
			temp = y;
			while (temp <= m) {
				a[x][temp] ^= 1;
				temp += 2;
			}
		}
		for (int i = x + 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				if (a[i - 1][j + 1] == 1 && j + 1 <= m) {
					cnt--;
					a[i][j] ^= 1;
					if (cnt == 0) break;
				} 
			}
			if (cnt == 0) break;
		}
		for (int i = x - 1;i >= 1;i--) {
			for (int j = 1;j <= m;j++) {
				if (a[i + 1][j - 1] == 1 && j - 1 >= 0) {
					cnt--;
					a[i][j] ^= 1;
					if (cnt == 0) break;
				}
			}
			if (cnt == 0) break;
		}
		if (cnt == 0 && a[x][y] == (op - 'A')) {
			cout << "Yes" << '\n';
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= m;j++) {
					if (a[i][j] == 0) cout << 'A';
					else cout << 'B';
				}
				cout << '\n';
			}
			return ;
		}
	}
	if (a[x][y] == 0) {
		cnt = k - (n + m);
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				a[i][j] = 1;
			}
		}
		a[x][y] = 0;
		if (1) {
			int temp = y;
			while (temp > 0) {
				a[x][temp] ^= 1;
				temp -= 2;
			}
			temp = y;
			while (temp <= m) {
				a[x][temp] ^= 1;
				temp += 2;
			}
		}
		for (int i = x + 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				if (a[i - 1][j + 1] == 1 && j + 1 <= m) {
					cnt--;
					a[i][j] ^= 1;
					if (cnt == 0) break;
				} 
			}
			if (cnt == 0) break;
		}
		for (int i = x - 1;i >= 1;i--) {
			for (int j = 1;j <= m;j++) {
				if (a[i + 1][j - 1] == 1 && j - 1 >= 0) {
					cnt--;
					a[i][j] ^= 1;
					if (cnt == 0) break;
				}
			}
			if (cnt == 0) break;
		}
		if (cnt == 0 && a[x][y] == (op - 'A')) {
			cout << "Yes" << '\n';
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= m;j++) {
					if (a[i][j] == 0) cout << 'A';
					else cout << 'B';
				}
				cout << '\n';
			}
			return ;
		}
	}
	cout << "No" << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}