#include<bits/stdc++.h>
#define lowbit(x) (x)&-(x)
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<vector<int>>f(25,vector<int>(n+1));
	for(int i=1;i<=n;i++)cin>>a[i],f[0][i]=a[i];
	for(int i=1;(1LL<<i)<=n;i++){
		for(int j=1;j+(1ll<<i)<=n+1;j++){
			f[i][j]=f[i-1][j]&f[i-1][j+(1LL<<(i-1))];
		}
	}
	int q;cin>>q;
	auto check = [&](int r,int x)->int{
		int res=(1LL<<32)-1;
		while(x){
			int d=lowbit(x);
			int temp=__lg(d);
			res&=f[temp][r-d+1];
			r-=d;
			x-=lowbit(x);
		}
		return res;
	};
	for(int i=1;i<=q;i++){
		int l,k;cin>>l>>k;
		int ans=-1;
		int r=n;
		int tl=l;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,mid-tl+1)>=k)ans=mid,l=mid+1;
			else r=mid-1;
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
