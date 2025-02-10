#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=10007;
const int maxn=2e5+5;
vector<int>g[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>val(n+1);
	for(int i=1;i<=n;i++)cin>>val[i];
	int ans=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(g[i].size()==1)continue;
		vector<int>temp;
		int mx1=0,mx2=0;
		int s=0;
		for(auto v:g[i]){
			temp.push_back(v);
			s+=val[v];
			if(mx1==0||val[v]>mx1){
				mx2=mx1;
				mx1=val[v];
			}else{
				mx2=max(mx2,val[v]);
			}
		}
		ans=max(ans,mx1*mx2);
		for(auto x:temp){
			sum+=val[x]*(s-val[x])%mod;
			sum%=mod;
		}
	}
	cout<<ans<<' '<<sum<<'\n';
	return 0;
}
