//bfs连通块 即所有连在一切的点答案相同
#include<bits/stdc++.h>
using namespace std;
int res[1005][1005];
int vis[1005][1050],cnt=1,cur;
int ans[100005];
int dx[]={0,1,0,-1};//右下左上
int dy[]={1,0,-1,0};
int n;
struct node{
	int x,y;
};
queue<node>q;
void bfs(int x,int y){
	node root;
	root.x=x,root.y=y;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			node temp=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				node a;
				int tx=temp.x+dx[i];
				int ty=temp.y+dy[i];
				a.x=tx,a.y=ty;
				if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&res[tx][ty]==1-res[temp.x][temp.y]&&!vis[tx][ty]){
					q.push(a);
					vis[tx][ty]=cur;
					cnt++;
				}
			}
		}
	}
	return ;
}
int main(){
	int m;cin>>n>>m;
	getchar();
	char ch;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ch;
			res[i][j]=ch-'0';
		}
		getchar();
	}
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(!vis[x][y]){
			cur++;
			vis[x][y]=cur;
			bfs(x,y);
			ans[cur]=cnt;
			cnt=1;
		}
		cout<<ans[vis[x][y]]<<'\n';
	}
	return 0;
}
