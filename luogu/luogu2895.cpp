#include<bits/stdc++.h>
using namespace std;
int res[305][305];
bool vis[305][305];
int dx[]={0,0,1,-1};//右左下上
int dy[]={1,-1,0,0};
struct node{
	int x,y;
};
queue<node>q;
int bfs(){
	node root;
	root.x=0,root.y=0;
	q.push(root);
	int cnt=1;
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			node temp=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int tx=temp.x+dx[i];
				int ty=temp.y+dy[i];
				if(tx<0||ty<0)continue;
				if(res[tx][ty]==-1)return cnt;
				if(!vis[tx][ty]&&cnt<res[tx][ty]){
					node a;
					a.x=tx,a.y=ty;
					q.push(a);
					vis[tx][ty]=1;
				}
			}
		}
		cnt++;
	}
	return -1;
}
int main(){
	int m;cin>>m;
	int x,y,t;
	for(int i=0;i<305;i++){
		for(int j=0;j<305;j++){
			res[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>t;//注意时间覆盖
		if(res[x][y]==-1||res[x][y]>t)res[x][y]=t;
		for(int j=0;j<4;j++){
			int tx=x+dx[j];
			int ty=y+dy[j];
			if(tx<0||ty<0)continue;
			if(res[tx][ty]==-1||res[tx][ty]>t)res[tx][ty]=t;
		}
	}
	vis[0][0]=1;
	cout<<bfs();
	return 0;
}
