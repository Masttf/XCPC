#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,d;cin>>n>>m>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	int ans=-1;
	for(int i=1;i<=n;i++){
		int p=upper_bound(b+1,b+1+m,a[i]+d)-b-1;
		if(p&&abs(a[i]-b[p])<=d)ans=max(ans,a[i]+b[p]);
	}
	cout<<ans;
	return 0;
}
