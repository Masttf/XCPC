#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<int> vis[105][105];
queue<node>q;
string res[105];
void bfs(node start,int n,int m){
	q.push(start);
	int ans=999999;
	int cnt=1;
	if(!vis[start.x][start.y].empty())ans=vis[start.x][start.y][0];
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			node temp=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int tx=temp.x+dx[i];
				int ty=temp.y+dy[i];
				if(tx>=0&&tx<n&&ty>=0&&ty<m&&res[tx][ty]=='.'){
					if(!vis[tx][ty].empty()){
						for(int z=0;z<vis[tx][ty].size();z++){
							if(vis[tx][ty][z]>=cnt)ans=min(ans,vis[tx][ty][z]);
						}
					}
					res[tx][ty]='#';
					node a;a.x=tx,a.y=ty;
					q.push(a);
				}
			}
		}
		cnt++;
	}
	ans==999999? cout<<"NO"<<'\n' :cout<<"YES "<<ans<<'\n';
}
int main(){
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>res[i];
		}
		node start;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(res[i][j]=='H'){
					start.x=i;
					start.y=j;
					res[i][j]='#';
				}
			}
		}
		for(int i=0;i<105;i++){
			for(int j=0;j<105;j++){
				vis[i][j].clear();
			}
		}
		int k,x,y;cin>>k;
		for(int i=0;i<k;i++){
			cin>>x>>y;
			vis[x-1][y-1].push_back(i);
		}
		bfs(start,n,m);
	}
	return 0;
}
