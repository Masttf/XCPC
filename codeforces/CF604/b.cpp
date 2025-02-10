#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	auto check = [&](int x)->bool{
		int cnt=0;
		int l=1,r=n;
		while(l<r){
			if(a[l]+a[r]<=x){
				l++;
				r--;
			}else r--;
			cnt++;
		}
		if(l==r)cnt++;
		return cnt<=k;
	};

	int l=a[n],r=a[n-1]+a[n];
	int ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}