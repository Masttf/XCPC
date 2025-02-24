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
void solve(){
	int n; cin >> n;
	string a, b; cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	auto dfs = [&](auto self, int now) -> int{
		if(now == 1){
			if(a[0] == '1' || b[0] == '1')return 1;
			else return 0;
		}
		if(a[now - 1] == '1' || b[now - 1] == '1')return self(self, now - 1);
		return 0;
	};
	cout << dfs(dfs, n) << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--)solve();
	return 0;
}