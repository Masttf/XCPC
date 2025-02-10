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
	vector ans(n+1,vector<char>(m+1));
	int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
	vector<pair<int,int>>a(n*m+1);
	for(int i=1;i<=n*m;i++){
		int x,y;cin>>x>>y;
		a[i]={x,y};
	}
	auto check = [&](int t)->bool{
		dbg(t);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)ans[i][j]='.';
		}
		for(int i=1;i<=t;i++){
			auto [x,y]=a[i];
			ans[x][y]='#';
		}
		if(ans[x1][y1]=='#')return false;
		if(ans[x2][y2]=='#')return false;
		vector vis(n+1,vector<int>(m+1));
		auto bfs = [&]()->void{
			queue<pair<int,int>>q;
			q.push({x1,y1});
			vis[x1][y1]==1;
			while(!q.empty()){
				auto [x,y]=q.front();
				dbg(x,y);
				q.pop();
				for(int i=0;i<4;i++){
					int tx=x+dx[i];
					int ty=y+dy[i];
					if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]&&ans[tx][ty]!='#'){
						vis[tx][ty]==1;
						q.push({tx,ty});
					}
				}
			}
		};
		bfs();
		return vis[x2][y2];
	};
	int l=0,r=n*m;
	int res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}else r=mid-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)ans[i][j]='.';
	}
	for(int i=1;i<=res;i++){
		auto [x,y]=a[i];
		ans[x][y]='#';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}