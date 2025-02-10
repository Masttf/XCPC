#include<bits/stdc++.h>
using namespace std;
string res[305];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<pair<int,int>>q;
vector<pair<int,int>>con[30];
pair<int,int> start,ed;
int n,m;
int bfs(){
	int cnt=1;
	q.push(start);
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			pair<int,int> temp=q.front();q.pop();
			for(int i=0;i<4;i++){
				int tx=temp.first+dx[i];
				int ty=temp.second+dy[i];
				if(tx>=0&&tx<n&&ty>=0&&ty<m&&res[tx][ty]!='#'){
					if(res[tx][ty]=='=')return cnt;
					if(res[tx][ty]>='A'&&res[tx][ty]<='Z'){
						if(con[res[tx][ty]-'A'][0]==make_pair(tx,ty)){
							pair<int ,int>b=con[res[tx][ty]-'A'][1];
							tx=b.first;
							ty=b.second;
						}else{
							pair<int ,int>b=con[res[tx][ty]-'A'][0];
							tx=b.first;
							ty=b.second;
						}
					}else if(res[tx][ty]=='.'){
						res[tx][ty]='#';
					}
					q.push(make_pair(tx,ty));
				}
			}
		}
		cnt++;
	}
	return cnt;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>res[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(res[i][j]>='A'&&res[i][j]<='Z'){
				con[res[i][j]-'A'].push_back({i,j});
			}
			else if(res[i][j]=='@')start=make_pair(i,j);
			else if(res[i][j]=='=')ed=make_pair(i,j);
		}
	}
	res[start.first][start.second]='#';
	cout<<bfs();
	return 0;
}
