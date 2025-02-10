#include <bits/stdc++.h>

using namespace std;
#define int long long
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ... Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve() {
	int n = 32;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] < a[1])cnt++;
	}
	if(cnt == 31){
		cout << 1 << '\n';
	}else if(cnt >= 27){
		cout << 2 << '\n';
	}else if(cnt >= 13){
		cout << 4 << '\n';
	}else if(cnt >= 6){
		cout << 8 << '\n';
	}else if(cnt >= 2){
		cout << 16 << '\n';
	}else cout << 32 << '\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}