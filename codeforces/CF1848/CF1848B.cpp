#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
vector<int>g[maxn];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=k;i++)g[i].clear();
	for(int i=1;i<=n;i++)cin>>a[i],g[a[i]].push_back(i);
	if(n==1){
		cout<<0<<'\n';
		return ;
	}
	int ans=INT_MAX;
	for(int i=1;i<=k;i++){
		int last=0;
		vector<int>tem;
		for(auto x:g[i]){
			tem.push_back(x-last-1);
			last=x;
		}
		tem.push_back(n-last);
		sort(tem.begin(),tem.end());
		int res=max(tem[tem.size()-1]/2,tem[tem.size()-2]);
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
