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
	int n,m,a,b;cin >> n >> m >> a >> b;
	if (n > m) swap(n,m);
	if (a == 0 && b == 0) {
		if (n == 1 && m == 2) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}
	}
	else if (a == 0 && b == 1) {
		if (n % 2 == 1 && m % 2 == 1) {
			cout << "No" << '\n';
		}
		else if (n == 1 && m == 2) {
			cout << "Yes" << '\n'; 
		}	
		else if (n == 1) {
			cout << "No" << '\n';
		}
		else cout << "Yes" << '\n';
	}
	else if (a == 1 && b == 0) {
		if (n == 1 && m % 2 == 0) {
			cout << "Yes" << '\n';
		}
		else if (n % 2 == 0 && m == 1) {
			cout << "Yes" << '\n';
		}
		else cout << "No" << '\n';
	}
	else {
		if (n % 2 == 1 && m % 2 == 1) {
			cout << "No" << '\n';
		}
		else cout << "Yes" << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}