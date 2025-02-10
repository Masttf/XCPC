//对于每个点都有取与被取两种状态
#include<bits/stdc++.h>
using namespace std;
int dx[]={1,1,1,0,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};
int res[10][10];
int vis[10][10];
int mx;
int n,m;
bool judge(int x,int y){
	for(int z=0;z<9;z++){
		int tx=x+dx[z];
		int ty=y+dy[z];
		if(vis[tx][ty])return false;
	}
	return true;
}
void dfs(int sum,int x,int y){//dfs时应该先考虑好每个单位的状态然后进行递归
	if(y==m+1){
		dfs(sum,x+1,1);
		return ;
	}
	if(x==n+1){
		mx=max(sum,mx);
		return ;
	}
	dfs(sum,x,y+1);
	if(judge(x,y)){
		vis[x][y]=1;
		sum+=res[x][y];
		dfs(sum,x,y+1);
		vis[x][y]=0;
		sum-=res[x][y];
	}
	return ;
}
void slove(){
	memset(res,0,sizeof(res));
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>res[i][j];
		}
	}
	mx=0;
	dfs(0,1,1);
	cout<<mx<<'\n';
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		slove();
	}
	return 0;
}
