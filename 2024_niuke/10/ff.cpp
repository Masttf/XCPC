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
	vector<pair<int, int>>a(n * n + 1);
	for(int i = 1; i <= n * n; i++){
		cin >> a[i].first >> a[i].second;
	}
	vector<int>ans(n * n + 1);
	vector vis(n + 1, vector<int>(n + 1));
	vector<pair<int, int>>res;
	for(int i = 1; i <= n * n; i++){
		auto [x, y] = a[i];
		if(vis[x][y])continue;
		ans[i] = 1;
		for(auto [tx, ty] : res){
			int dx = tx - x;
			int dy = ty - y;
			int d = __gcd(dx, dy);
			dx /= d;
			dy /= d;
			//dbg(dx, dy);
			int nx = x, ny = y;
			while(nx <= n && ny <= n && nx >= 1 && ny >= 1){
				vis[nx][ny] = 1;
				nx += dx;
				ny += dy;
				//dbg(nx, ny);
			}
			dx = -dx;
			dy = -dy;
			nx = x, ny = y;
			while(nx <= n && ny <= n && nx >= 1 && ny >= 1){
				vis[nx][ny] = 1;
				nx += dx;
				ny += dy;
				//dbg(nx, ny);
			}
		}
		res.push_back(a[i]);
	}
	for(int i = 1; i <= n * n; i++){
		cout << ans[i];
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}