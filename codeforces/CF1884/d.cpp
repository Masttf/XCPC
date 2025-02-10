#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>vis(n+1);
	vector<int>cnt(n+1);
	vector<int>f(n+1);
	vector<int>res(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=1;
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			f[i]+=cnt[j];
		}
	}
	vector<int>d(n+1);//注意这个的复杂度是nlnn的
	for(int i=n;i>=1;i--){//因此找到某个数的倍数的个数可以nlnn找到
		d[i]=(f[i]*(f[i]-1))/2;//注意gcd可能是2g，3g所以要减掉上面的
		for(int j=i*2;j<=n;j+=i){
			d[i]-=d[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		for(int j=i;j<=n;j+=i)res[j]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!res[i])ans+=d[i];
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}