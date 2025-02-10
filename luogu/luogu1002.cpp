#include<bits/stdc++.h>
using namespace std;
#define int long long
int res[25][25],cnt;
void dfs(int n,int m,int row,int cow){
	if(row==n&&cow==m){
		cnt++;
		return ;
	}
	if(row<n&&cow<=m&&res[row+1][cow]!=1){
		dfs(n,m,row+1,cow);
	}
	if(row<=n&&cow<m&&res[row][cow+1]!=1){
		dfs(n,m,row,cow+1);
	}
}
int dp[25][25];
signed main(){
	int n,m;cin>>n>>m;
	int x,y;cin>>x>>y;
	res[x][y]=1;
	if(x-1>=0){
		res[x-1][y+2]=1;
		if(y>=2)
			res[x-1][y-2]=1;
	}
	if(y-2>=0){
		res[x+1][y-2]=1;
	}
	if(y-1>=0){
		res[x+2][y-1]=1;
	}
	if(x-2>=0){
		res[x-2][y+1]=1;
		if(y>=1)
			res[x-2][y-1]=1;
	}
	res[x+1][y+2]=1;
	res[x+2][y+1]=1;
	if(res[n][m]){
		cout<<cnt;
		return 0;
	}
	//dfs(n,m,0,0);
	//cout<<cnt;
	dp[1][1]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m+1;j++){
			if(res[i-1][j-1])
				continue;
			dp[i][j]+=dp[i-1][j]+dp[i][j-1];
		}
	}
	cout<<dp[n+1][m+1];
	return 0;
}
