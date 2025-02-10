#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<vector<int>>t(2,vector<int>(n+1));
	auto updata = [&](int x,int val,int k)->void{
		while(x<=n){
			t[k][x]+=val;
			x+=lowbit(x);
		}
		return ;
	};
	auto ask = [&](int x,int k)->int{
		int res=0;
		while(x){
			res+=t[k][x];
			x-=lowbit(x);
		}
		return res;
	};
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int d=ask(a[i]-1,1);
		int d2=ask(a[i]-1,0);
		updata(a[i],1,0);
		if(d2==0)continue;
		if(d==0)updata(a[i],1,1),ans++;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
