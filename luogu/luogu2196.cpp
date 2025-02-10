#include<bits/stdc++.h>
using namespace std;
int res[25];
int connect[25][25];
int n;
//表示从这个洞开挖能挖到的最大地雷个数
int dp[25];
int ans[25][25],cnt=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i];
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			cin>>connect[i][j];
		}
	}
	dp[n]=res[n];
	int sum=n;
	ans[n][1]=n;
	ans[n][0]=1;
	for(int i=n-1;i>=1;i--){
		int mx=0;
		int id=-1;
		int len=n-i;
		for(int j=1;j<=len;j++){
			if(connect[i][j]!=0){
				if(mx<dp[i+j]){
					mx=dp[i+j];
					id=i+j;
				}
			}
		}
		dp[i]=res[i]+mx;
		if(dp[sum]<dp[i])sum=i;
		if(id==-1){
			ans[i][0]=1;
			ans[i][1]=i;
		}else{
			for(int j=1;j<=ans[id][0];j++){
				ans[i][j]=ans[id][j];
			}
			ans[i][0]=ans[id][0]+1;
			ans[i][ans[i][0]]=i;
		}
	}
	for(int i=ans[sum][0];i>=1;i--){
		cout<<ans[sum][i]<<' ';
	}
	cout<<'\n'<<dp[sum];
	return 0;
}
//回溯算法
//#include<bits/stdc++.h>
//using namespace std;
//const int mx=25;
//int n;
//int res[mx];
//int path[mx][mx];
//vector<vector<int>> vis(mx);
//int maxn,sum;
//vector<int>ans;
//void backtarck(int x,int start){
//	for(int i=x+1;i<=n;i++){
//		if(path[x][i]){
//			vis[start].push_back(i);
//			sum+=res[i];
//			backtarck(i,start);
//			vis[start].pop_back();
//			sum-=res[i];
//		}
//	}
//	if(maxn<sum){
//		maxn=sum;
//		ans=vis[start];
//	}
//	return ;
//}
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>res[i];
//	}
//	for(int i=1;i<=n-1;i++)
//	{
//		for(int j=i+1;j<=n;j++)cin>>path[i][j];
//	}	
//	for(int i=1;i<=n;i++){
//		sum+=res[i];
//		vis[i].push_back(i);
//		backtarck(i,i);
//		sum-=res[i];
//	}
//	for(int i=0;i<ans.size();i++){
//		cout<<ans[i]<<' ';
//	}
//	cout<<'\n'<<maxn;
//	return 0;
//}
