#include<bits/stdc++.h>
using namespace std;
int res[105][105];
int dp[105][105];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
//定义为从这个点开始划能划的最大距离
int dfs(int x,int y){
	int sum=1;
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&res[x][y]>res[tx][ty]){
			if(dp[tx][ty])sum=max(dp[tx][ty]+1,sum);
			else sum=max(dfs(tx,ty)+1,sum);
		}
	}
	return dp[x][y]=sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>res[i][j];
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mx=max(mx,dfs(i,j));
		}
	}
	cout<<mx;
	return 0;
}
