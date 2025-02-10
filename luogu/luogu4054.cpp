#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
int tree[305][305][105];
int res[305][305];
int n,m;
void updata(int x,int y,int c){//只需更新父节点的计数即可
	int t=res[x][y];
	for(int i=x;i<=n;i+=lowbit(i)){//访问父节点
		for(int j=y;j<=m;j+=lowbit(j)){
			tree[i][j][t]--;
			tree[i][j][c]++;
		}
	}
	res[x][y]=c;
	return ;
}
int sum(int x,int y,int c){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i)){//访问所有计数和
		for(int j=y;j>0;j-=lowbit(j)){
			ans+=tree[i][j][c];
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int temp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>temp;
			updata(i,j,temp);
		}
	}
	int q;cin>>q;
	int t,x,x2,y,y2,c;
	while(q--){
		cin>>t;
		if(t==1){
			cin>>x>>y>>c;
			updata(x,y,c);
		}else{
			cin>>x>>x2>>y>>y2>>c;
			cout<<sum(x2,y2,c)-sum(x2,y-1,c)-sum(x-1,y2,c)+sum(x-1,y-1,c)<<'\n';
		}
	}
	return 0;
}
