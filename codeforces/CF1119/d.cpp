#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<int>res(n+1);
	for(int i=1;i<n;i++){
		res[i]=a[i+1]-a[i];
	}
	res[n]=1e18+1;
	sort(res.begin()+1,res.end());
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+res[i];
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		int len=r-l+1;
		int d=lower_bound(res.begin()+1,res.end(),len)-res.begin();
		int ans=pre[d-1]+(n-d+1)*len;
		cout<<ans<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}