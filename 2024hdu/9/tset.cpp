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
	int k, x, y; cin >> k >> x >> y;
	vector<int>ans(2);
	int mx = max(x, y);
	int d = (k + mx - 1) / mx;
	ans[d % 2] = 1;
	int mi = x + y - mx;
	int dd = mx - mi;
	int dis = mx * d - k;
	if(dd * (d - 1) > dis){
		ans[1 ^ (d % 2)] = 1;
	}
	for(int i = 0; i < 2; i++){
		if(ans[i])cout << "Yes\n";
		else cout << "No\n";
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