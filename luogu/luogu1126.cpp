#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,f;
};
int res[55][55];
bool vis[55][55][5];
bool v2[55][55];
int n,m;
int dx[]={0,1,0,-1};//0E 1S 2W 3N//转向利用加减取余
int dy[]={1,0,-1,0};
queue<node>q;
bool je(int x,int y){
	if(x<1||x>=n||y<1||y>=m||res[x][y]||res[x+1][y]||res[x][y+1]||res[x+1][y+1])return 1;
	return 0;
}
int bfs(){
	int x,y,ex,ey,cnt=1;
	char te;
	cin>>x>>y>>ex>>ey>>te;
	if(x==ex&&y==ey)return 0;
	node root;root.x=x,root.y=y;
	switch(te){
	case 'E':
		root.f=0;
		break;
	case 'S':
		root.f=1;
		break;
	case 'W':
		root.f=2;
		break;
	case 'N':
		root.f=3;
		break;
	}
	v2[x][y]=1;
	vis[root.x][root.y][root.f]=1;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			node t=q.front();q.pop();
			for(int i=1;i<=3;i++){
				int tx=t.x+i*dx[t.f];
				int ty=t.y+i*dy[t.f];
				if(je(tx,ty))break;
				if(v2[tx][ty])continue;
				node a;a.x=tx,a.y=ty,a.f=t.f;
				v2[tx][ty]=1;
				q.push(a);
				if(tx==ex&&ty==ey)return cnt;
			}
			int nf=(t.f+1+4)%4;
			if(!vis[t.x][t.y][nf]){
				vis[t.x][t.y][nf]=1;
				node a=t;a.f=nf;
				q.push(a);
			}
			nf=(t.f-1+4)%4;
			if(!vis[t.x][t.y][nf]){
				vis[t.x][t.y][nf]=1;
				node a=t;a.f=nf;
				q.push(a);
			}
		}
		cnt++;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)cin>>res[i][j];
	cout<<bfs();
	return 0;
}
