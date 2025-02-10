#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k,a,b;cin>>n>>k>>a>>b;
	vector<pair<int,int>>res(n+1);
	for(int i=1;i<=n;i++)cin>>res[i].first>>res[i].second;
	if(a<=k&&b<=k){
		cout<<0<<'\n';
		return ;
	}
	int ans=abs(res[a].first-res[b].first)+abs(res[a].second-res[b].second);
	if(k==0){
		//cout<<"YES"<<endl;
		cout<<ans<<'\n';
		return ;
	}
	int res1=LONG_LONG_MAX;
	int res2=LONG_LONG_MAX;
	for(int i=1;i<=k;i++){
		res1=min(res1,abs(res[i].first-res[a].first)+abs(res[i].second-res[a].second));
		res2=min(res2,abs(res[i].first-res[b].first)+abs(res[i].second-res[b].second));
	}
	ans=min(ans,res1+res2);
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