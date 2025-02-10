#include<bits/stdc++.h>
using namespace std;
int res[10][10];
bool vx[10][10],vy[10][10],vc[10][10];
int flag=0;
void dfs(int x,int y){//传入开始坐标
	if(y==10)x++,y=1;
	if(x==10&&y==1){
		flag=1;
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				cout<<res[i][j]<<' ';
			}
			cout<<'\n';
		}
		return ;
	}
	if(flag==1)return ;
	if(res[x][y]){
		dfs(x,y+1);
	}else if(res[x][y]==0){
		for(int i=1;i<=9;i++){
			if(!vx[x][i]&&!vy[y][i]&&!vc[(x-1)/3*3+(y-1)/3+1][i]){
				vx[x][i]=1;vy[y][i]=1;vc[(x-1)/3*3+(y-1)/3+1][i]=1;
				res[x][y]=i;
				dfs(x,y+1);
				vx[x][i]=0;vy[y][i]=0;vc[(x-1)/3*3+(y-1)/3+1][i]=0;
				res[x][y]=0;
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>res[i][j];
			if(res[i][j]){
				vx[i][res[i][j]]=1;
				vy[j][res[i][j]]=1;
				vc[(i-1)/3*3+(j-1)/3+1][res[i][j]]=1;
			}
		}
	}
	dfs(1,1);
	return 0;
}
