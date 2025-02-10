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
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
const int Max=1e18;
bool vis[65][65][65][65];
void solve(){
	int n;cin>>n;
	vector<string>g(n);
	for(int i=0;i<n;i++)cin>>g[i];
	int ans=-1;
	auto bfs = [&](int x1,int y1,int x2,int y2)->void{
		queue<array<int,4>>q;
		q.push({x1,y1,x2,y2});
		vis[x1][y1][x2][y2]=1;
		int cnt=1;
		while(!q.empty()){
			int sz=q.size();
			for(int j=1;j<=sz;j++){
				auto [x1,y1,x2,y2]=q.front();
				q.pop();
				for(int i=0;i<4;i++){
					int tx1=x1+dx[i];
					int ty1=y1+dy[i];
					int tx2=x2+dx[i];
					int ty2=y2+dy[i];
					if(tx1<0)tx1=0;
					if(tx1>=n)tx1=n-1;
					if(ty1<0)ty1=0;
					if(ty1>=n)ty1=n-1;
					if(tx2<0)tx2=0;
					if(tx2>=n)tx2=n-1;
					if(ty2<0)ty2=0;
					if(ty2>=n)ty2=n-1;
					if(g[tx1][ty1]=='#')tx1=x1,ty1=y1;
					if(g[tx2][ty2]=='#')tx2=x2,ty2=y2;
					if(tx1==tx2&&ty1==ty2){
						ans=cnt;
						return ;
					}
					if(vis[tx1][ty1][tx2][ty2])continue;
					vis[tx1][ty1][tx2][ty2]=1;
					q.push({tx1,ty1,tx2,ty2});
					//dbg(tx1,ty1,tx2,ty2);
				}
			}
			cnt++;
			//dbg("-----");
		}
	};
	int x1=-1,y1=-1,x2,y2;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(g[i][j]=='P'){
				if(x1==-1){
					x1=i,y1=j;
				}else x2=i,y2=j;
			}
		}
	}
	bfs(x1,y1,x2,y2);
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