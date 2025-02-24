#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=15;
int a[maxn][maxn];
int n,m,ans;
map<int,int>mm;
int dx[]={1,0};
int dy[]={0,1};
void dfs(int x,int y){
	mm[a[x][y]]++;
	if(x==n&&y==m){
		if(mm.size()==n+m-1)ans++;
		return ;
	}
	for(int i=0;i<2;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx<=n&&ty<=m)dfs(tx,ty);
	}
	mm[a[x][y]]--;
	if(mm[a[x][y]]==0)mm.erase(a[x][y]);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
