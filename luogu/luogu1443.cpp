#include<bits/stdc++.h>
using namespace std;
int res[405][405];
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
bool vis[405][405];
int n,m;
int cnt=1;
struct node{
	int x,y;
};
queue<node> q;
void bfs(int x,int y){
	node root;
	root.x=x;
	root.y=y;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			node temp=q.front();
			q.pop();
			for(int i=0;i<8;i++){
				int tx=temp.x+dx[i];
				int ty=temp.y+dy[i];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]){
					res[tx][ty]=cnt;
					node a;
					a.x=tx;
					a.y=ty;
					vis[tx][ty]=1;
					q.push(a);
				}
			}
		}
		cnt++;
	}
	return ;
}
int main(){
	cin>>n>>m;
	int x,y;cin>>x>>y;
	vis[x][y]=1;
	bfs(x,y);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(res[i][j]==0){
				if(i==x&&y==j)cout<<0<<"    ";
				else cout<<-1<<"    ";
			}
			else cout<<res[i][j]<<"    ";
		}
		cout<<'\n';
	}
	return 0;
}
