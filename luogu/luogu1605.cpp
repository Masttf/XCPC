#include<bits/stdc++.h>
using namespace std;
int trace[10][10];
int cnt;
void dfs(int row,int cow,int ex,int ey,int n,int m){
	if(row==ex&&cow==ey){
		cnt++;
		return ;
	}
	//下
	if(trace[row+1][cow]!=1&&row+1<=n){
		trace[row+1][cow]=1;
		dfs(row+1,cow,ex,ey,n,m);
		trace[row+1][cow]=0;
	}
	//右
	if(trace[row][cow+1]!=1&&cow+1<=m){
		trace[row][cow+1]=1;
		dfs(row,cow+1,ex,ey,n,m);
		trace[row][cow+1]=0;
	}
	//上
	if(trace[row-1][cow]!=1&&row-1>=1){
		trace[row-1][cow]=1;
		dfs(row-1,cow,ex,ey,n,m);
		trace[row-1][cow]=0;
	}
	//左
	if(trace[row][cow-1]!=1&&cow-1>=1){
		trace[row][cow-1]=1;
		dfs(row,cow-1,ex,ey,n,m);
		trace[row][cow-1]=0;
	}
	return ;
}
int main(){
	int n,m,t;cin>>n>>m>>t;
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	int x,y;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		trace[x][y]=1;
	}
	//注意在dfs里不会标记起点所以可能多次访问起点
	//没有注意起点就只有70分
	trace[sx][sy]=1;
	dfs(sx,sy,ex,ey,n,m);
	cout<<cnt;
	return 0;
}
