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
	constexpr int N = 1e5;
	int cnt = 0;
	vector<int> a(n), vis(N + 1);
	for(int i = 0; i < n; ++i) {
		std::cin >> a[i];
		vis[a[i]] = 1;
	}
	for(int i = 1; i < n; ++i) {
		int k = std::gcd(a[i], a[i - 1]);
		if(!vis[k]) cnt++;
	}
	dbg(cnt);
	if(cnt % 2 == 0){
		cout << "Haitang\n";
	}else{
		cout << "dXqwq\n";
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