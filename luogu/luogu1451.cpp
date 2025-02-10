#include<bits/stdc++.h>
using namespace std;
int res[105][105];
int vis[105][105],cnt;
int dx[]={0,1,0,-1};//右下左上
int dy[]={1,0,-1,0};
int n,m;
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
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&res[tx][ty]>0&&!vis[tx][ty]){
					q.push(a);
					vis[tx][ty]=1;
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	char ch;
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch;
			res[i][j]=ch-'0';
		}
		getchar();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(res[i][j]!=0&&!vis[i][j]){
				bfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
