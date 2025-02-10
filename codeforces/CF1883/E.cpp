#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		if(cnt[i-1]>=30||a[i]<a[i-1]*(1ll<<cnt[i-1])){
			if(a[i-1]>a[i]){
				int d=(a[i-1]+a[i]-1)/a[i];
				int k=__lg(d);
				cnt[i]=cnt[i-1]+k;
				if(a[i]*(1ll<<k)<a[i-1])cnt[i]++;
			}else{
				int d=a[i]/a[i-1];
				int k=__lg(d);
				cnt[i]=cnt[i-1]-k;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=cnt[i];
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