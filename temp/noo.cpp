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
	vector<vector<int>> vis(n + 1, vector<int>(m + 1));
	int cnt = 2 * (n + m) - 4;
	int tot = 2 * (n + m) - 4;
	if(n == 1){
		tot = m;
		cnt = m;
	}
	int sum = 0;
	int ans = 0;
	vector<pair<int ,int>>res;
	for(int i = 1; i <= n; i++){
		res.push_back({i, 1});
		res.push_back({i, m});
	}
	for(int i = 2; i < m; i++){
		res.push_back({1, i});
		if(n != 1)res.push_back({n, i});
	}
	for(int i = 2; i < n; i++){
		for(int j = 2; j < m; j++){
			res.push_back({i, j});
		}
	}
	//dbg(res.size());
	vector<vector<int>> d(n + 1, vector<int>(m + 1));
	auto bfs = [&](int x, int y) -> int{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				d[i][j] = 0;
			}
		}
		int num = 0;
		queue<pair<int, int>>q;
		q.push({x, y});
		d[x][y] = 1;
		while(!q.empty()){
			int xx = q.front().first;
			int yy = q.front().second;
//			auto [xx, yy] = q.front();
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
					if(bfs(i, j) != sum)return false;
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
					return bfs(i, j) == (n * m - sum);
				}
			}
		}
		return true;
	};
	auto dfs = [&](auto self, int now) -> void{
//		auto [x, y] = res[now];
		int x = res[now].first;
		int y = res[now].second;
		if(cnt == 0)return ;
		if(now == n * m){
			if(cnt == tot)return ;
			if(check()){
				ans++;
				 if(ans % 1000 == 0)dbg(ans);
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
		self(self, now + 1);
		vis[x][y] = 1;
		if(x == 1 || x == n || y == 1 || y == m)cnt--;
		sum++;
		self(self, now + 1);
		sum--;
		vis[x][y] = 0;
		if(x == 1 || x == n || y == 1 || y == m)cnt++;
	};
	dfs(dfs, 0);
	cout << ans / 2<< '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; // cin >> t;
	// dbg(1, 6);
	 solve(6, 6);
//	for(int i = 1; i <= 5; i++){
//		for(int j = 2; j <= 6; j++){
//			dbg(i, j);
//			solve(i, j);
//		}
//	}
	return 0;
}
