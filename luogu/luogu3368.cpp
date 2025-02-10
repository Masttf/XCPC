//区间修改，单点值
#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
#define int long long
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
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int t,x,y,k;
	int old=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		updata(i,t-old);
		old=t;
	}
	for(int i=1;i<=m;i++){
		cin>>t;
		if(t==1){
			cin>>x>>y>>k;
			updata(x,k);
			updata(y+1,-k);
		}else {
			cin>>k;
			cout<<sum(k)<<'\n';
		}
	}
	return 0;
}
