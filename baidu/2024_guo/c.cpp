#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int Max = 1e18;
int dx[] = {-1, 1, 0 ,0};
int dy[] = {0, 0, 1, -1};
void solve(){
	int n, x1, y1, x2, y2; cin  >> n >> x1 >> y1 >> x2 >> y2;
	int N = 1005;
	vector g(N + 1, vector<int>(N + 1));
	for(int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		g[x][y] = 1;
	}
	deque<pair<int,int>>q;
	vector d(N + 1, vector<int>(N + 1, Max));
	vector vis(N + 1, vector<int>(N + 1));
	d[x1][y1] = 0;
	q.push_back({x1, y1});
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop_front();
		if(vis[x][y])continue;
		//dbg(x, y);
		vis[x][y] = 1;
		for(int i = 0; i < 4; i++){
			int tx = dx[i] + x;
			int ty = dy[i] + y;
			if(tx < 0 || tx > N || ty < 0 || ty > N)continue;
			if(g[tx][ty] == 1){
				if(d[tx][ty] > d[x][y] + 1){
					d[tx][ty] = d[x][y] + 1;
					q.push_back({tx, ty});
				}
			}else{
				if(d[tx][ty] > d[x][y]){
					d[tx][ty] = d[x][y];
					q.push_front({tx, ty});
				}
			}
		}
	}
	cout << d[x2][y2] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--)solve();
	return 0;
}