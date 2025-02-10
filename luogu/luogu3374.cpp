//单点修改，区间和
#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
const int maxn=5e5+5;
int res[maxn];
int n,m;
void updata(int x,int d){
	while(x<=n){
		res[x]+=d;
		x+=lowbit(x);
	}
	return ;
}
int sum(int x){
	int ans=0;
	while(x>0){
		ans+=res[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int t,x,y;
	for(int i=1;i<=n;i++){
		cin>>t;
		updata(i,t);
	}
	for(int i=1;i<=m;i++){
		cin>>t>>x>>y;
		if(t==1){
			updata(x,y);
		}else cout<<sum(y)-sum(x-1)<<'\n';
	}
	return 0;
}
