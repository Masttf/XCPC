#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
const int maxn=305;
string s[maxn];
int n,m,t,flag=1;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
bool vis[maxn][maxn];
queue<pair<int,int>>q;
vector<pair<int,int>>k;
map<pair<int,int>,int>rr;
int d[30][30];
int dp[(1LL<<20)][20];
void bfs(int x,int y){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)vis[i][j]=0;
	}
	q.push({x,y});
	vis[x][y]=1;
	int cnt=1;
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			pair<int,int>root=q.front();
			q.pop();
			int ux=root.first,uy=root.second;
			for(int i=0;i<4;i++){
				int tx=ux+dx[i];
				int ty=uy+dy[i];
				if(tx>=0&&tx<n&&ty>=0&&ty<m&&s[tx][ty]!='#'&&!vis[tx][ty]){
					if(rr.count({tx,ty})){
						d[rr[{x,y}]][rr[{tx,ty}]]=cnt;
					}
					vis[tx][ty]=1;
					q.push({tx,ty});
				}
			}
		}
		cnt++;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>t;
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++)d[i][j]=INT_MAX;
	}
	for(int i=0;i<n;i++)cin>>s[i];
	int x,y,xx,yy;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
				x=i,y=j;
			}else if(s[i][j]=='G'){
				xx=i,yy=j;
			}
		}
	}
	int idx=0;
	k.push_back({x,y});
	rr[{x,y}]=idx++;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='o')k.push_back({i,j}),rr[{i,j}]=idx++;
		}
	}
	k.push_back({xx,yy});
	rr[{xx,yy}]=idx++;
	int sz=k.size();
	for(int i=0;i<sz;i++){
		bfs(k[i].first,k[i].second);
	}
	for(int i=0;i<(1LL<<sz);i++){
		for(int j=0;j<sz;j++)dp[i][j]=INT_MAX;
	}
	dp[1][0]=0;//初始化起点
	for(int i=1;i<(1LL<<sz);i++){
		for(int j=0;j<sz;j++){
			if(i>>j&1){
				for(int k=0;k<sz;k++){
					if((i^(1LL<<j)>>k)&1){
						dp[i][j]=min(dp[i][j],dp[i^(1LL<<j)][k]+d[j][k]);
					}
				}
			}
		}
	}
	int ans=-1;
	for(int i=1;i<(1LL<<sz);i++){
		if((i>>(sz-1)&1)&&dp[i][sz-1]<=t){
			int tem=i;
			int cnt=-2;
			while(tem){
				cnt++;
				tem-=lowbit(tem);
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
