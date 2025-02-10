//先拿到最短路径，然后最短的路径一定是从它前面的路径走来的
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int mod=100003;
int n,m;
vector<int>g[maxn];
bool vis[maxn];
int d[maxn],c[maxn];
queue<int>q;
void bfs(){
	vis[1]=1;
	q.push(1);
	d[1]=0;
	int cnt=1;
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			int temp=q.front();q.pop();
			int l=g[temp].size();
			for(int i=0;i<l;i++){
				if(vis[g[temp][i]])continue;
				vis[g[temp][i]]=1;
				d[g[temp][i]]=cnt;
				q.push(g[temp][i]);
			}
		}
		cnt++;
	}
}
struct node{
	int id,dt;
	bool operator <(const node &y)const{
		return dt<y.dt;
	}
}ans[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		if(u==v)continue;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	c[1]=1;
	bfs();
	for(int i=1;i<=n;i++)ans[i].id=i,ans[i].dt=d[i];
	sort(ans+1,ans+1+n);
	for(int i=1;i<=n;i++){
		if(ans[i].dt==0&&ans[i].id!=1)c[ans[i].id]=0;
		else {
			int sz=g[ans[i].id].size();
			for(int j=0;j<sz;j++){
				int temp=g[ans[i].id][j];
				if(ans[i].dt+1==d[temp])c[temp]+=c[ans[i].id],c[temp]%=mod;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<c[i]<<'\n';
	return 0;
}
