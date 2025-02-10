#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	sort(a.begin()+1,a.end());
	int ans=0;
	for(int i=1;i<=n;i++){
		int p1=lower_bound(a.begin()+1,a.end(),a[i]-k)-a.begin();
		int p2=upper_bound(a.begin()+1,a.end(),a[i]-k)-a.begin()-1;
		if(a[p1]==a[i]-k&&a[p2]==a[i]-k){
			ans+=p2-p1+1;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t =1;
	while(t--)solve();
	return 0;
}