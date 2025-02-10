#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=25;
int a[maxn][maxn],b[maxn][maxn];
int s[maxn];
bool vis[maxn];
int ans=0;
int n;
int sum=0;
void dfs(int cnt){
	if(sum+s[n]-s[cnt-1]<=ans)return ;
	if(cnt==n+1)ans=max(ans,sum);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		sum+=b[cnt][i]*a[i][cnt];
		vis[i]=1;
		dfs(cnt+1);
		sum-=b[cnt][i]*a[i][cnt];
		vis[i]=0;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i]=max(s[i],b[i][j]*a[j][i]);
		}
	}
	for(int i=1;i<=n;i++)s[i]+=s[i-1];
	dfs(1);
	cout<<ans;
	return 0;
}
/*
  3
  10 2 3
  2 3 4
  3 4 5
  2 2 2
  3 5 3
  4 5 1
 */
