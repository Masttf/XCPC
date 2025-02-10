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
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
void solve(){
    int n, m; cin >> n >> m;
    int K; cin >> K;
    int sx, sy; cin >> sx >> sy;
    vector a(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    	}
    }
    int limit = min(n * m, K);
    vector dis(n + 1, vector(m + 1, vector<int>(limit + 1)));
    vector vis(n + 1, vector(m + 1, vector<bool>(limit + 1)));
    auto dij = [&]() -> void{
    	queue<array<int, 3>> q;
    	dis[sx][sy][0] = 0;
    	q.push({sx, sy, 0});
    	while(!q.empty()){
    		auto [x, y, step] = q.front();
    		q.pop();
    		vis[x][y][step] = 0;
    		if(step == limit)continue;
    		// dbg(x, y, step, W);
    		for(int i = 0; i <= 4; i++){
    			int tx = x + dx[i];
    			int ty = y + dy[i];
    			if(tx <= 0 || tx > n || ty <= 0 || ty > m)continue;
    			if(dis[tx][ty][step + 1] > dis[x][y][step] - a[tx][ty]){
    				dis[tx][ty][step + 1] = dis[x][y][step] - a[tx][ty];
    				if(!vis[tx][ty][step + 1]){
    					vis[tx][ty][step + 1] = 1;
    					q.push({tx, ty, step + 1});
    				}
    				
    			}
    		}
    	}
    };
    dij();
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		ans = min(ans, dis[i][j][limit] - (a[i][j] * (K - limit)));
    	}
    }
    cout << -ans << '\n';
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