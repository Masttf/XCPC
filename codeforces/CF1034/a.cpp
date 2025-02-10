#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int d=0;
	for(int i=1;i<=n;i++)cin>>a[i],d=__gcd(d,a[i]);
	//cout<<d<<endl;
	int m=0;
	for(int i=1;i<=n;i++){
		a[i]/=d;
		m=max(m,a[i]);
	}
	//cout<<m<<endl;
	vector<int>prim;
	vector<int>vis(m+1);
	for(int i=2;i<=m;i++){
		if(!vis[i])prim.push_back(i);
		for(int j=0;prim[j]*i<=m;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
	vector<int>cnt(m+1);
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	int ans=0;
	for(auto i:prim){
		int res=0;
		for(int j=i;j<=m;j+=i){
			res+=cnt[j];
		}
		ans=max(ans,res);
	}
	ans=n-ans;
	if(ans==n){
		ans=-1;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}