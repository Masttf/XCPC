#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=50;
string a[maxn],b[maxn];
int n,m;
int flag=0;
bool vis[maxn][maxn];
bool check(int h,int w){
	for(int i=0;i<n;i++){
		int c=(i+h)%n;
		for(int j=0;j<m;j++){
			int d=(j+w)%m;
			if(a[c][d]!=b[i][j])return false;
		}
	}
	return true;
}
void dfs(int h,int w){
	if(flag)return ;
	if(vis[h][w])return ;
	vis[h][w]=1;
	if(h==n-1&&w==m-1)return ;
	int res=1;
	res=check(h,w);
	if(res)flag=1;
	if(flag)return ;
	if(h!=n-1)dfs(h+1,w);
	if(w!=m-1)dfs(h,w+1);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	dfs(0,0);
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}
