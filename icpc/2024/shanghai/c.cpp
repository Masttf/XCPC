#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	dbg(x);\
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int l,r;cin >> l >> r;
	if (l % 2 == 1) {
		int len = (r - l + 1);
		if (len & 1) {
			cout << "Alice" << '\n';
		}
		else {
			if (l * 2 <= r) {
				cout << "Alice" << '\n';
			}
			else cout << "Bob" << '\n';
		}
	}
	else {
		int len = (r - l + 1);
		if (len & 1) {
			int now1 = l + 1;
			int now2 = l + 3;
			if (now1 <= r && now1 * 2 <= r) {
				cout << "Bob" << '\n';
			}
			else cout << "Alice" << '\n';
		}
		else {
			cout << "Bob" << '\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}