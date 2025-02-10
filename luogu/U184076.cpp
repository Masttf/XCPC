#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
vector<int>f[maxn];
bool vis[maxn];
int d[maxn],cnt[maxn];
int dfs(int root,int deep){
	int c=1;
	vis[root]=1;
	d[root]=deep;
	int sz=f[root].size();
	for(int i=0;i<sz;i++){
		int son=f[root][i];
		if(vis[son])continue;
		c+=dfs(son,deep+1);
	}
	return cnt[root]=c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int x,y;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		f[x].push_back(y);
		f[y].push_back(x);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++){
		cout<<d[i]<<' '<<cnt[i]<<'\n';
	}
	return 0;
}
