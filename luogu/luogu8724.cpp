#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e4+5;
struct node{
	int v,val,d;
};
vector<node>g[maxn];
bool vis[maxn][5];
int d[maxn][5];
int n,m;
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>> >q;
void bfs(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++){
			d[i][j]=INT_MAX;
			vis[i][j]=0;
		}
	}
	d[1][0]=0;
	q.push({0,{1,0}});
	while(!q.empty()){
		pair<int,int>temp=q.top().second;q.pop();
		int now=temp.first;
		int tag=temp.second;
		if(vis[now][tag])continue;
		vis[now][tag]=1;
		for(auto x:g[now]){
			int v=x.v;
			if(x.d+tag<=2&&d[v][x.d+tag]>d[now][tag]+x.val){
				d[v][x.d+tag]=d[now][tag]+x.val;
				q.push({d[v][x.d+tag],{v,x.d+tag}});
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=m;i++){
		int a,b,c,d;cin>>a>>b>>c>>d;
		node t1,t2;
		t1.v=b,t1.val=c,t1.d=d;
		t2.v=a,t2.val=c,t2.d=d;
		g[a].push_back(t1);
		g[b].push_back(t2);
	}
	bfs();
	cout<<d[n][0]-min(d[n][1],d[n][2]);
	return 0;
}
/*
  4 5
  1 4 2 1
  1 2 1 0
  2 3 4 1
  2 3 9 0
  3 4 5 0
  
 */
