#include<bits/stdc++.h>
using namespace std;
const int eps=80112002;
int dp[5005];
vector<int>res[5005];//吃
vector<int>r2[5005];
//返回以这个为结尾的食物链有多少
int dfs(int x){
	if(res[x].empty())return dp[x]=1;
	if(dp[x])return dp[x];
	int sz=res[x].size();
	int sum=0;
	for(int i=0;i<sz;i++){
		sum+=dfs(res[x][i]);
		sum%=eps;
	}
	return dp[x]=sum%eps;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		res[b].push_back(a);
		r2[a].push_back(b);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(r2[i].empty())ans+=dfs(i),ans%=eps;
	}
	cout<<ans;
	return 0;
}
