//模板首先是利用邻接矩阵来存储下一个节点和他的权值
//每次从优先队列头拿出来的就是该节点到起点的最短节点，需要vis[]标记已经找到同时避免重复寻找该节点的相邻节点
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
struct bian{
	int to,val;
	bian(int a,int b){to=a,val=b;}
};
struct node{
	int id,dist;
	node(int a,int b){id=a,dist=b;}
	bool operator <(const node &y) const
	{
		return dist>y.dist;
	}
};
int d[maxn];
bool vis[maxn];
vector<bian>g[maxn];
int n,m,s;
priority_queue<node>q;
void bfs(){
	d[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		node t=q.top();q.pop();
		int sz=g[t.id].size();
		if(vis[t.id])continue;
		vis[t.id]=1;
		for(int i=0;i<sz;i++){
			bian y=g[t.id][i];
			if(vis[y.to])continue;
			if(d[y.to]>t.dist+y.val){
				q.push(node(y.to,t.dist+y.val));
				d[y.to]=t.dist+y.val;
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back(bian(v,w));
	}
	for(int i=1;i<=n;i++)d[i]=INT_MAX;
	bfs();
	for(int i=1;i<=n;i++)cout<<d[i]<<' ';
	return 0;
}
