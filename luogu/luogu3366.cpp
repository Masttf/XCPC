//kruskal原理就是贪心很简单，每次都连最短的边构成的路径就是最小生成树
//主要是并查集判断每次要加入的边是否已经在这个集合里
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int f[5005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void unit(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fa]=fb;
}
struct node{
	int u,to,w;
	bool operator <(const node &y)const{
		return w<y.w;
	}
}edge[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].to>>edge[i].w;
	}
	sort(edge+1,edge+1+m);
	int sum=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(find(edge[i].u)!=find(edge[i].to)){
			unit(edge[i].u,edge[i].to);
			sum+=edge[i].w;
			cnt++;
		}
	}
	if(cnt==n-1)cout<<sum;
	else cout<<"orz";
	return 0;
}
/*prim
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=5005,M=2e5+5;
struct node{
	int to,val;
	node(int a,int b){to=a,val=b;}
};
vector<node>g[N];
int n,m,cnt,ans;
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii>>q;
void prim(){
	q.push({0,1});
	while(!q.empty()){
		pii temp=q.top();q.pop();
		if(vis[temp.second])continue;
		vis[temp.second]=1;
		ans+=temp.first;
		cnt++;
		for(auto x : g[temp.second]){
			if(vis[x.to])continue;
			q.push({x.val,x.to});
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back(node(v,w));
		g[v].push_back(node(u,w));
	}
	prim();
	if(cnt==n)cout<<ans;
	else cout<<"orz";
	return 0;
}
 */
