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
int dy[]={0,0,1,-1};
constexpr int Max=1e18;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector time(n+1,vector<int>(m+1));
	int sx,sy;
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		if(i==1)sx=x,sy=y;
		time[x][y]=k-i+1;
	}
	vector<string>g(n+1);
	for(int i=1;i<=n;i++){
		cin>>g[i];
		g[i]=' '+g[i];
	}
	vector d(n+1,vector<unsigned long long>(m+1,Max));
	auto bfs = [&]()->void{
		priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
		q.push({0,sx,sy});
		d[sx][sy]=0;
		while(!q.empty()){
			auto [w,x,y]=q.top();
			q.pop();
			if(w<d[x][y])continue;
			for(int i=0;i<4;i++){
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(tx>=0&&tx<=n&&ty>=0&&ty<=m&&g[tx][ty]=='.'){
					int ww=max(d[x][y]+1,(unsigned long long)time[tx][ty]);
					if(d[tx][ty]>ww){
						d[tx][ty]=ww;
						q.push({ww,tx,ty});
					}
				}
			}
		}
	};
	bfs();
	unsigned long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(d[i][j]==Max)continue;
			ans+=d[i][j]*d[i][j];
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