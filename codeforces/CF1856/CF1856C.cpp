#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	int p=n;
	vector<int>res(n+1);
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i],ans=max(ans,a[i]);
	res[n]=a[n];
	for(int i=n-1;i>=1;i--){
		if(a[i]<=res[i+1])res[i]=res[i+1]+1;
		else res[i]=a[i],p=i;
	}
	for(int i=1;i<=p-1;i++){
		int l=res[p]+1,r=res[i];
		while(l<=r){
			int mid=(l+r)>>1;
			int cost=0;
			int cnt=0;
			for(int j=i;j<p;j++){
				if(mid+cnt<=a[j])break;
				cost+=mid-a[j]+cnt;
				cnt--;
			}
			if(cost<=k)ans=max(ans,mid),l=mid+1;
			else r=mid-1;
		}
	}
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
