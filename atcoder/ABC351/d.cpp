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
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve(){
	int n,m;cin>>n>>m;
	vector<string>g(n+1);
	for(int i=1;i<=n;i++){
		cin>>g[i];
		g[i]=' '+g[i];
	}
	vector vis(n+1,vector<int>(m+1));
	int tot=1;
	auto bfs = [&](int s,int t)->int{
		queue<pair<int,int>>q;
		int cnt=1;
		vis[s][t]=tot;
		q.push({s,t});
		while(!q.empty()){
			auto [x,y]=q.front();
			q.pop();
			int ok=1;
			for(int i=0;i<4;i++){
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&g[tx][ty]=='#')ok=0;
			}
			if(ok){
				for(int i=0;i<4;i++){
					int tx=x+dx[i];
					int ty=y+dy[i];
					if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&g[tx][ty]!='#'&&vis[tx][ty]!=tot){
						vis[tx][ty]=tot;
						cnt++;
						q.push({tx,ty});
					}
				}
			}
		}
		return cnt;
	};
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]=='#')continue;
			if(!vis[i][j]){
				ans=max(ans,bfs(i,j));
				tot++;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}