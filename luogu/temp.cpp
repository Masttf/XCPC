#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max = 1e18;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void solve(){
    int n, m, sx, sy; cin >> n >> m >> sx >> sy;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    vector dis(n + 1, vector<int>(m + 1));
    auto bfs1 = [&]() -> void{
    	vector vis(n +1, vector<int>(m + 1));
    	queue<pair<int, int>>q;
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			if(a[i][j] == '@'){
    				q.push({i, j});
    				dis[i][j] = 0;
    				vis[i][j] = 1;
    			}
    		}
    	}
    	while(!q.empty()){
    		auto [x, y] = q.front();
    		q.pop();
    		for(int i = 0; i < 4; i++){
    			int tx = x + dx[i];
    			int ty = y + dy[i];
    			if(tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] == '#' || vis[tx][ty])continue;
				vis[tx][ty] = 1;
				dis[tx][ty] = dis[x][y] + 1;
				q.push({tx, ty});
    		}
    	}
    };
    bfs1();
    vector d(n + 1, vector<int> (m + 1));
    int ans = Max;
    auto bfs = [&]() -> void{
    	vector vis(n +1, vector<int>(m + 1));
    	queue<array<int, 4>>q;
    	q.push({sx, sy, sx, sy});
    	vis[sx][sy] = 1;
    	d[sx][sy] = 0;
    	while(!q.empty()){
    		auto [x, y, xx, yy] = q.front();
    		q.pop();
    		for(int i = 0; i < 4; i++){
    			int tx = x + dx[i];
    			int ty = y + dy[i];
    			int txx = xx + dx[i ^ 1];
    			int tyy = yy + dy[i ^ 1];
    			if(tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] == '#' || vis[tx][ty])continue;
    			if(txx < 1 || txx > n || tyy < 1 || tyy > m || a[txx][tyy] == '#')continue;
    			vis[tx][ty] = 1;
    			d[tx][ty] = d[x][y] + 1;
    			q.push({tx, ty, txx, tyy});
    			if(a[tx][ty] == '@'){
    				ans = min(ans, d[tx][ty] + dis[txx][tyy]);
    			}
    		}
    	}
    };
    bfs();
    if(ans == Max)cout << -1 << '\n';
    else cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}