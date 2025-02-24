#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int maxn = 100;
int dis[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {-2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2};
int dx1[] = {1, -1, 2, -2, 2, -2, 1, -1};
int dy1[] = {-2, -2, -1, -1, 1, 1, 2, 2};
void init(){
	queue<pair<int, int>> q;
	q.push({1, 1});
	vis[1][1] = 1;
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(tx > 0 && ty > 0 && tx < maxn && ty < maxn && !vis[tx][ty]){
				vis[tx][ty] = 1;
				dis[tx][ty] = dis[x][y] + 1;
				q.push({tx, ty});
			}
		}
		for(int i = 0; i < 8; i++){
			int tx = x + dx1[i];
			int ty = y + dy1[i];
			if(tx > 0 && ty > 0 && tx < maxn && ty < maxn && !vis[tx][ty]){
				vis[tx][ty] = 1;
				dis[tx][ty] = dis[x][y] + 1;
				q.push({tx, ty});
			}
		}
	}
	return ;
}
void solve(){
	int x, y; cin >> x >> y;
	cout << dis[x][y] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 2;
	init();
	// cin >> t;
	while(t--)solve();
	return 0;
}