#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
vector<int>f[maxn],p[maxn];
bool vis[maxn];
int n;
int cnt[maxn];//拿到每个子节点的有多少个节点
int d[maxn];//拿到以这个为根节点然后他的子节点到根节点的距离
int dfs(int x){//输入一个节点返回子节点到该节点的所有距离和
	int c=1;
	vis[x]=1;
	int sum=0;
	int sz=f[x].size();
	for(int i=0;i<sz;i++){
		int son=f[x][i];
		if(vis[son])continue;
		vis[son]=1;
		p[x].push_back(son);
		sum+=dfs(son)+cnt[son];
		c+=cnt[son];
	}
	cnt[x]=c;
	return sum;
}
void dp(int x){
	if(p[x].empty())return ;
	int sz=p[x].size();
	for(int i=0;i<sz;i++){
		int s=p[x][i];
		d[s]=d[x]+n-2*cnt[s];
		dp(s);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	int x,y;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		f[x].push_back(y);
		f[y].push_back(x);
	}
	d[1]=dfs(1);//以1为根节点
	dp(1);
	int mi=1;
	for(int i=2;i<=n;i++){
		if(d[mi]>d[i]){
			mi=i;
		}
	}
	cout<<mi<<' '<<d[mi];
	return 0;
}
