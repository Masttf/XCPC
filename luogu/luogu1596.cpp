#include<bits/stdc++.h>
using namespace std;
string res[105];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
struct node{
	int x,y;
};
queue<node>q;
int n,m,cnt;
void bfs(int x,int y){
	node root;root.x=x,root.y=y;
	q.push(root);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			node temp=q.front();
			q.pop();
			for(int i=0;i<8;i++){
				int tx=temp.x+dx[i];
				int ty=temp.y+dy[i];
				if(tx>=0&&tx<n&&ty>=0&&ty<m&&res[tx][ty]=='W'){
					node a;a.x=tx,a.y=ty;
					res[a.x][a.y]='.';
					q.push(a);
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>res[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(res[i][j]=='W'){
				res[i][j]='.';
				bfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
