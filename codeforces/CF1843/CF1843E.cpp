#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
pair<int,int>a[maxn];
int res[maxn];
int cnt[maxn];
int n,m;
bool check(int mid){
	for(int i=1;i<=mid;i++)cnt[res[i]]++;
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	bool ok=0;
	for(int i=1;i<=m;i++){
		int l=a[i].first,r=a[i].second;
		int d=cnt[r]-cnt[l-1];
		if(2*d>r-l+1)ok=1;
	}
	for(int i=1;i<=n;i++)cnt[i]=0;
	return ok;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=m;i++)cin>>a[i].first>>a[i].second;
	int q;cin>>q;
	for(int i=1;i<=q;i++)cin>>res[i];
	int ans=-1;
	int l=1,r=q;
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
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
