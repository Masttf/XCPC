//二分加dijkstra
//wa最后一个点，可能第一个就超二分的值
//需要开long long
#include<bits/stdc++.h>
#define pll pair<int,int>
#define int long long
using namespace std;
const int maxn=1e4+5;
struct node{
	int to,w,f;
	node(int a,int k,int c){to=a,w=k,f=c;}
};
vector<node>res[maxn];
int f[maxn],d[maxn],n,m,b;
priority_queue<pll,vector<pll>,greater<pll> >q;
bool vis[maxn];
bool check(int x){
	if(f[1]>x)return false;
	for(int i=1;i<=n;i++)vis[i]=0,d[i]=LONG_LONG_MAX;
	d[1]=0;
	q.push({0,1});
	while(!q.empty()){
		pll temp=q.top();q.pop();
		if(vis[temp.second])continue;
		vis[temp.second]=1;
		int sz=res[temp.second].size();
		for(int i=0;i<sz;i++){
			node y=res[temp.second][i];
			if(y.f>x)continue;
			if(d[y.to]>temp.first+y.w){
				d[y.to]=temp.first+y.w;
				q.push({d[y.to],y.to});
			}
		}
	}
	return d[n]<=b;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int mi=LONG_LONG_MAX,mx=0;
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++)cin>>f[i],mi=min(mi,f[i]),mx=max(mx,f[i]);;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		res[u].push_back(node(v,w,f[v]));
		res[v].push_back(node(u,w,f[u]));
	}
	int ans=-1,left=mi,right=mx;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,right=mid-1;
		else left=mid+1;
	}
	if(ans==-1)cout<<"AFK";
	else cout<<ans;
	return 0;
}
