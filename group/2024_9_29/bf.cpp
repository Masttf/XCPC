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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void solve(int n, int m){
    vector vis(n + 1, vector<int>(m + 1));
    int cnt = 2 * (n + m) - 4;
    int tot = 2 * (n + m) - 4;
    int ans = 0;
    auto bfs = [&](int x, int y) -> int{
    	vector d(n + 1, vector<int>(m + 1));
    	int num = 0;
    	queue<pair<int, int>>q;
    	q.push({x, y});
    	d[x][y] = 1;
    	while(!q.empty()){
    		auto [xx, yy] = q.front();
    		num++;
    		q.pop();
    		for(int i = 0; i < 4; i++){
    			int tx = xx + dx[i];
    			int ty = yy + dy[i];
    			if(tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] != vis[x][y] || d[tx][ty])continue; 
    			d[tx][ty] = 1;
    			q.push({tx, ty});
    		}
    	}
    	return num;
    };
    auto check = [&]() -> bool{
    	int f = 0;
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			if(vis[i][j] == 1){
    				if(bfs(i, j) != tot - cnt)return false;
    				else{
    					f = 1;
    					break;
    				}
    			}
    		}
    		if(f)break;
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			if(vis[i][j] == 0){
    				return bfs(i, j) == cnt;
    			}
    		}
    	}
    	return true;
    };
    auto dfs = [&](auto self, int x, int y) -> void{
    	if(y > m){
    		x++;
    		y = 1;
    	}
    	if(x == n + 1){
    		if(cnt == tot || cnt == 0)return ;
    		if(cnt == 1 || cnt == tot - 1 || check()){
    			ans++;
    			// for(int i = 1; i <= n; i++){
    			// 	for(int j = 1; j <= m; j++){
    			// 		cout << vis[i][j] << ' ';
    			// 	}
    			// 	cout << '\n';
    			// }
    			// cout << endl;
    		}
    		return ;
    	}
    	if(cnt == 0)return ;
    	self(self, x, y + 1);
    	vis[x][y] = 1;
    	if(x == 1 || x == n || y == 1 || y == m)cnt--;
    	self(self, x, y + 1);
    	vis[x][y] = 0;
    	if(x == 1 || x == n || y == 1 || y == m)cnt++;
    };
    dfs(dfs, 1, 1);
    cout << ans / 2<< '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    for(int i = 2; i <= 4; i++){
    	for(int j = 2; j <= 4; j++){
    		dbg(i, j);
    		solve(i, j);
    	}
    }
    return 0;
}