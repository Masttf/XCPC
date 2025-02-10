#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	int ans=1;
	int l=1,r=INT_MAX;
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	while(l<=r){
		int mid=(l+r)>>1;
		int p=upper_bound(a.begin()+1,a.end(),mid)-a.begin()-1;
		int ct=p*mid-pre[p];
		if(ct<=k){
			ans=max(ans,mid);
			l=mid+1;
		}else r=mid-1;
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
