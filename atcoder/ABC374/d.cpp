#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n; cin >> n;
    int t, s; cin >> s >> t;
    vector<array<int, 4>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < 4; j++){
    		cin >> a[i][j];
    	}
    }
    auto dis = [&](int x1, int y1, int x2, int y2) -> double{
    	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    double ans = 1e18;
    vector<int> vis(n + 1);
    // vector<pair<int, int>>track;
    double sum = 0;
    auto dfs = [&](auto self, int now, int lx, int ly) -> void{
    	if(now == n + 1){
    		// for(auto [x, y] : track){
    		// 	cout << x << ' ' << y << '\n';
    		// }
    		// cout << endl;
    		ans = min(ans, sum);
    		return ;
    	}
    	for(int i = 1; i <= n; i++){
    		if(vis[i])continue;
    		vis[i] = 1;
    		double len = dis(a[i][0], a[i][1], a[i][2], a[i][3]);
    		sum += len * 1.0 / t;
    		sum += dis(lx, ly, a[i][0], a[i][1]) / s;
    		// track.push_back({i, 1});
    		self(self, now + 1, a[i][2], a[i][3]);
    		sum -= dis(lx, ly, a[i][0], a[i][1]) / s;
    		// track.pop_back();

    		// track.push_back({i, 2});
    		sum += dis(lx, ly, a[i][2], a[i][3]) / s;
    		self(self, now + 1, a[i][0], a[i][1]);
    		sum -= dis(lx, ly, a[i][2], a[i][3]) / s;
    		sum -= len * 1.0 / t;
    		vis[i] = 0;
    		// track.pop_back();
    	}
    };
    dfs(dfs, 1, 0, 0);
    cout << setprecision(15) << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}