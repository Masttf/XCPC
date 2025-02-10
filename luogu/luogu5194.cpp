//要养成ll的好习惯
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10005;
int res[maxn],psum[maxn];
int n,k;
int mx=0;
void dfs(int start,int sum){
	if(sum>k)return ;
	if(sum+psum[start]<=mx)return ;
	mx=max(sum,mx);
	for(int i=start;i>=1;i--){
		dfs(i-1,sum+res[i]);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>res[i];
	for(int i=1;i<=n;i++)psum[i]=psum[i-1]+res[i];
	dfs(n,0);
	cout<<mx;
	return 0;
}
