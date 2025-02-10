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
int dy[] = {0, 0, -1, 1};
void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    int ans = n * m;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    vector vis(n + 1, vector<int>(m + 1));
    vector fg(n + 1, vector<int>(m + 1, -2));
    int cnt = 0;
    auto bfs = [&](int x, int y) -> int{
    	cnt++;
    	queue<pair<int, int>> q;
    	q.push({x, y});
    	vis[x][y] = cnt;
    	int res = 0;
    	while(!q.empty()){
			auto [nx, ny] = q.front();
			q.pop();
			for(int k = 0; k < 4; k++){
				int tx = nx + dx[k];
				int ty = ny + dy[k];
				if(tx < 1 || tx > n || ty < 1 || ty > m)continue;
				if(vis[tx][ty])continue;
				if(a[tx][ty] != '1'){
					if(fg[tx][ty] != cnt - 1){
						res++;
						fg[tx][ty] = cnt - 1;
					}
				}else{
					vis[tx][ty] = cnt;
					q.push({tx, ty});
				}
			}
    	}
    	return res;
    };
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(a[i][j] == '1' && !vis[i][j]){
    			// dbg(i, j, bfs(i, j));
    			ans = min(ans, bfs(i, j));
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