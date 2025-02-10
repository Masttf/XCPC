#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<pair<int,int>>res(n+1);
	for(int i=1;i<=n;i++)cin>>res[i].first>>res[i].second;
	sort(res.begin()+1,res.end());
	int ans=m;
	int sum=0;
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&res[j].first==res[i].first){
			sum+=res[j].second;
			j++;
		}
		i=j-1;
		if(res[i].first-sum<=m){
			ans=max(ans,m+sum);
		}
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