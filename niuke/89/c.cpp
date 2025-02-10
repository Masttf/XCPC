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
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	int ok=1;
	int flag=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='#')flag=1;
		}
	}
	if(!flag){
		cout<<"Blue\n";
		return ;
	}
	vector vis(n+1,vector<int>(m+1));
	auto bfs = [&](int i,int j,int t)->bool{
		vector<string>b=a;
		queue<pair<int,int>>q;
		q.push({i,j});
		vis[i][j]=t;
		while(!q.empty()){
			auto [x,y]=q.front();
			q.pop();
			for(int k=0;k<4;k++){
				int tx=x+dx[k];
				int ty=y+dy[k];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]){
					if(a[tx][ty]=='#'){
						vis[tx][ty]=t;
						q.push({tx,ty});
					}
				}
			}
		}
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=m;jj++){
				if(a[ii][jj]=='#'&&vis[ii][jj]==t){
					for(int k=0;k<4;k++){
						int tx=ii+dx[k];
						int ty=jj+dy[k];
						if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
							if(a[tx][ty]=='.'){
								b[tx][ty]='#';
							}
						}
					}
				}
			}
		}
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=m;jj++){
				if(b[ii][jj]=='.')return false;
			}
		}
		//for(auto x:b)cout<<x<<endl;
		return true;
	};
	flag=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[i][j]&&a[i][j]=='#'){
				flag|=bfs(i,j,++cnt);
				//dbg(i,j,flag);
			}
		}
	}
	if(flag){
		cout<<"Red\n";
		return ;
	}
	cout<<"Draw\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}