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
	int n; cin >> n;
	bitset<15> vis;
	map<unsigned long long, int>m;
	auto dfs = [&](auto self) ->void{
		if(m.count(vis.to_ulong()))return ;
		m[vis.to_ulong()] = 1;
		// for(auto x : vis)cout <<x;
		// cout << '\n';
		for(int i = 0; i < n; i++){
			vis[i].flip();
			if(i)vis[i - 1].flip();
			if(i + 1 <= n - 1)vis[i + 1].flip();
			self(self);
			vis[i].flip();
			if(i)vis[i - 1].flip();
			if(i + 1 <= n - 1)vis[i + 1].flip();
		}
	};
	dfs(dfs);
	cout << m.size() << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}