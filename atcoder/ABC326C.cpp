#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	int ans=0;
	int r=1;
	for(int i=1;i<=n;i++){
		while(r<=n&&a[r]-a[i]<m){
			r++;
		}
		//cout<<i<<' '<<r<<endl;
		ans=max(ans,r-i);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}