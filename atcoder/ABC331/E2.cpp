#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>a(n+1),b(m+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	vector<int>c(k+1);
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		c[i]=a[x]+b[y];
	}
	sort(a.begin()+1,a.end());
	sort(b.begin()+1,b.end());
	sort(c.begin()+1,c.end());
	auto check = [&](int x)->bool{
		int res=0;
		for(int i=1;i<=n;i++){
			res+=b.end()-lower_bound(b.begin()+1,b.end(),x-a[i]);
		}
		res-=c.end()-lower_bound(c.begin()+1,c.end(),x);
		return res>0;
	};
	int ans=2e9;
	int l=2,r=2e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
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