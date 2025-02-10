#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>ca(n+1),cb(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>ca[i];
	for(int i=1;i<=n;i++)cin>>cb[i];
	int ans=0;
	for(int i=0;i<=1e6;i++){
		int res=1e6;
		int ok=1;
		for(int j=1;j<=n;j++){
			int d=a[j]-ca[j]*i;
			if(d<0){
				ok=0;
				break;
			}
			if(cb[j]==0)continue;
			res=min(res,d/cb[j]);
		}
		if(ok)ans=max(ans,res+i);
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