#include<bits/stdc++.h>
using namespace std;
int n,m;
int yanhui[15][15];
int vis[20];
vector<int>track;
int flag=0;
void dfs(int po,int sum){
	if(po==n+1){
		if(sum==m){
			for(int i=0;i<n;i++)cout<<track[i]<<' ';
			flag=1;
		}
		return ;
	}
	if(flag)return ;
	if(sum>=m)return ;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			track.push_back(i);
			dfs(po+1,sum+i*yanhui[n][po]);
			vis[i]=0;
			track.pop_back();
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	yanhui[1][1]=1;
	for(int i=2;i<=13;i++){
		for(int j=1;j<=i;j++)yanhui[i][j]=yanhui[i-1][j]+yanhui[i-1][j-1];
	}
	dfs(1,0);
	return 0;
}
