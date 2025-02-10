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
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    vector vis(n + 1, vector<int>(m + 1));
    int ans = 0;
    auto dfs = [&](auto self, int x, int y, int step) -> void{
    	if(step == k){
    		ans++;
    		return ;
    	}
    	for(int i = 0; i < 4; i++){
    		int tx = x + dx[i];
    		int ty = y + dy[i];
    		if(tx <= 0 || tx > n || ty <= 0 || ty > m)continue;
    		if(a[tx][ty] == '#')continue;
    		if(vis[tx][ty])continue;
    		vis[tx][ty] = 1;
    		self(self, tx, ty, step + 1);
    		vis[tx][ty] = 0;
    	}
    };
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(a[i][j] == '.'){
    			vis[i][j] = 1;
    			dfs(dfs, i, j, 0);
    			vis[i][j] = 0;
    		}
    	}
    }
    cout << ans << '\n';
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