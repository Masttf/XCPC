#include<bits/stdc++.h>//如何在一个区间内寻找min(b[i],a[j])的和
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn],sum[maxn],ans[maxn],cnt[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],ans[i]=0,cnt[i]=0;
	for(int i=1;i<=n;i++)cin>>b[i],sum[i]=b[i]+sum[i-1];
	for(int i=1;i<=n;i++){
		int l=upper_bound(sum+i,sum+n+1,a[i]+sum[i-1])-sum;
		cnt[l]+=a[i]+sum[i-1]-sum[l-1];
		ans[i]++;
		ans[l]--;
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
	for(int i=1;i<=n;i++)cout<<b[i]*ans[i]+cnt[i]<<' ';
	cout<<'\n';
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
