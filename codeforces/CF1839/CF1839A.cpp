#include<bits/stdc++.h>
#define int long long
using namespace std;
bool vis[105];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)vis[i]=0;
	if(k==1){
		cout<<n<<'\n';
		return ;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=1;j<=i;j++)if(vis[j])res++;
		if(res<(i+k-1)/k)vis[i]=1;
		res=0;
		for(int j=0;j<i;j++)if(vis[n-j])res++;
		if(res<(i+k-1)/k)vis[n-i+1]=1;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])ans++;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
