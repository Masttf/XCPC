#include<bits/stdc++.h>
using namespace std;
char res[105][105];
bool vis[105][105];
int n,m;
int cnt;
int main(){
	int x,y;cin>>n>>m>>x>>y;
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>res[i][j];
		}
		getchar();
	}
	char fast=res[x][y];
	vis[x][y]=1;
	while(x>=1&&x<=n&&y>=1&&y<=m){
		if(vis[x][y]){
			if(fast=='U')x--;
			else if(fast=='D')x++;
			else if(fast=='R')y++;
			else if(fast=='L')y--;
		}
		else if(res[x][y]=='U'){
			if(fast!=res[x][y])cnt++;
			vis[x][y]=1;
			x--;
			fast='U';
		}
		else if(res[x][y]=='D'){
			if(fast!=res[x][y])cnt++;
			vis[x][y]=1;
			x++;
			fast='D';
		}
		else if(res[x][y]=='L'){
			if(fast!=res[x][y])cnt++;
			vis[x][y]=1;
			y--;
			fast='L';
		}
		else if(res[x][y]=='R'){
			if(fast!=res[x][y])cnt++;
			vis[x][y]=1;
			y++;
			fast='R';
		}
	}
	cout<<cnt;
	return 0;
}
