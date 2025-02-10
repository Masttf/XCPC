#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,1,0,-1,1,0,-1};
string res[105];
string a="yizhong";
bool vis[105][105];
int n;
void dfs(pair<int,int> x){
	for(int i=0;i<8;i++){
		int tx=x.first+dx[i];
		int ty=x.second+dy[i];
		if(tx>=0&&tx<n&&ty>=0&&ty<n&&res[tx][ty]=='i'){
			int idx=1;
			while(idx<=6&&tx>=0&&tx<n&&ty>=0&&ty<n&&res[tx][ty]==a[idx]){
				tx+=dx[i];
				ty+=dy[i];
				idx++;
			}
			if(idx==7){
				int temp1=x.first,temp2=x.second;
				vis[temp1][temp2]=1;
				while(idx>1){
					temp1+=dx[i];
					temp2+=dy[i];
					vis[temp1][temp2]=1;
					idx--;
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>res[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(res[i][j]=='y'){
				dfs({i,j});
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!vis[i][j])cout<<'*';
			else cout<<res[i][j];
		}
		cout<<'\n';
	}
	return 0;
}
