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
int a[100][100];
void solve(){
	int n;
	std::cin >> n;
	a[1][1] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			a[i][j] += a[i - 1][j] + a[i][j - 1];
		}
	}
	std::cout << a[n][n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}