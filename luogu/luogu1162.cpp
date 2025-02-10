#include<bits/stdc++.h>
using namespace std;
int res[35][35];
bool vis[35][35];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
struct node{
	int x,y;
};
int n;
queue<node>q;
void bfs(int x,int y){
	node root;root.x=x,root.y=y;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			node temp=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int tx=temp.x+dx[i];
				int ty=temp.y+dy[i];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&res[tx][ty]==0&&!vis[tx][ty]){
					node a;a.x=tx,a.y=ty;
					vis[tx][ty]=1;
					q.push(a);
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>res[i][j];
			if(res[i][j]==1)vis[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(res[i][j]==0&&(i==1||j==1||i==n||j==n)){
				vis[i][j]=1;
				bfs(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j])res[i][j]=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<res[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
