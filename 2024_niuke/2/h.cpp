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
	int n, x, y;cin >> n >> x >> y;
	string s; cin >> s;
	s = ' ' + s;
	if(x == 0 && y == 0){
		cout << (n + 1) * (n) /2 << '\n';
		return ;
	}
	map<pair<int,int>,int> m;
	vector<pair<int,int>> a(n + 5);
	a[n + 1] = {0, 0};
	m[a[n + 1]] = n + 1;
	int ans = 0;
	for(int i = n; i >= 1; i--){
		auto [lx, ly] = a[i + 1];
		if(s[i] == 'W'){
			ly++;
		}else if(s[i] == 'A'){
			lx--;
		}else if(s[i] == 'S'){
			ly--;
		}else{
			lx++;
		}
		int dx = lx - x;
		int dy = ly - y;
		if(m.count({dx, dy})){
			ans += n - m[{dx, dy}] + 2;
		}
		a[i] = {lx, ly};
		m[{lx, ly}] = i;
		//dbg(i, lx, ly , ans);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}