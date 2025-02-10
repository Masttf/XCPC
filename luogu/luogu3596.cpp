#include<bits/stdc++.h>
using namespace std;
int res[105][105];
int dp[105][105];//剪枝，记录到这个点的最少花费
bool vis[105][105];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int m,n;
int ans=999999999;
int sum=0;
void dfs(int lx,int ly,int flag){
	if(lx==m&&ly==m){
		ans=min(ans,sum);
		return ;
	}
	if(sum>=ans||sum>=dp[lx][ly])return ;
	dp[lx][ly]=min(dp[lx][ly],sum);
	for(int i=0;i<4;i++){
		int tx=lx+dx[i];
		int ty=ly+dy[i];
		if(tx>=1&&tx<=m&&ty>=1&&ty<=m&&!vis[tx][ty]){
			if(!res[tx][ty]&&!flag)continue;
			vis[tx][ty]=1;
			if(res[tx][ty]==0){
				if(flag){
					sum+=2;
					res[tx][ty]=res[lx][ly];
					dfs(tx,ty,0);
					sum-=2;
					res[tx][ty]=0;
				}
			}
			else if(res[tx][ty]==res[lx][ly]){
				dfs(tx,ty,1);
			}else if(res[tx][ty]!=res[lx][ly]){
				sum+=1;
				dfs(tx,ty,1);
				sum-=1;
			}
			vis[tx][ty]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>m>>n;
	int x,y,ty;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>ty;
		res[x][y]=ty+1;
	}
	for(int i=1;i<105;i++){
		for(int j=1;j<105;j++){
			dp[i][j]=99999999;
		}
	}
	vis[1][1]=1;
	dfs(1,1,1);
	if(ans==999999999)ans=-1;
	cout<<ans;
	return 0;
}
