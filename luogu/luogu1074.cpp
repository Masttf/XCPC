#include<bits/stdc++.h>
using namespace std;
int res[10][10];
int score[10][10];
pair<int,int> c[15];
bool vx[10][10],vy[10][10],vc[10][10];
int ans=-1;
//优化从每行以及有最多的数开始dfs
void dfs(int x,int y,int sum,int cur){//传入开始坐标,和
	if(y==10){
		cur--;
		x=c[cur].second;
		y=1;
	}
	if(x==0){
		ans=max(ans,sum);
		return ;
	}
	if(res[x][y]){
		dfs(x,y+1,sum+res[x][y]*score[x][y],cur);
	}else if(res[x][y]==0){
		for(int i=1;i<=9;i++){
			if(!vx[x][i]&&!vy[y][i]&&!vc[(x-1)/3*3+(y-1)/3+1][i]){
				vx[x][i]=1;vy[y][i]=1;vc[(x-1)/3*3+(y-1)/3+1][i]=1;
				res[x][y]=i;
				dfs(x,y+1,sum+res[x][y]*score[x][y],cur);
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
		c[i].second=i;
		c[i].first=0;
		for(int j=1;j<=9;j++){
			cin>>res[i][j];
			if(res[i][j]){
				c[i].first++;
				vx[i][res[i][j]]=1;
				vy[j][res[i][j]]=1;
				vc[(i-1)/3*3+(j-1)/3+1][res[i][j]]=1;
			}
		}
	}
	int lx=1,rx=9,uy=1,dy=9;
	int cnt=6;
	while(lx<=rx&&uy<=dy){//初始化每个点的分值螺旋矩阵
		for(int i=lx;i<=rx;i++) score[uy][i]=cnt;
		uy++;
		for(int i=uy;i<=dy;i++) score[i][rx]=cnt;
		rx--;
		for(int i=rx;i>=lx;i--) score[dy][i]=cnt;
		dy--;
		for(int i=dy;i>=uy;i--) score[i][lx]=cnt;
		lx++;
		cnt++;
	}
	sort(c+1,c+10);
	dfs(c[9].second,1,0,9);
	cout<<ans;
	return 0;
}
