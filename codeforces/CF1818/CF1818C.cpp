#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int cnt[maxn];
void solve(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];// 判断连续下降
	for(int i=3;i<=n;i++){
		if(a[i]<=a[i-1]&&a[i-1]<=a[i-2])cnt[i]++;
	}
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	while(q--){
		int l,r;cin>>l>>r;
		if(l==r)cout<<1<<'\n';
		else if(r-l==1)cout<<2<<'\n';
		else{
			int ans=2;
			ans=max(ans,r-l+1-(cnt[r]-cnt[l+1]));
			cout<<ans<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
