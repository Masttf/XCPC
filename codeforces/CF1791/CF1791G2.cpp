#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
pair<int,int> a[maxn];
int sum[maxn];
void solve(){//考虑一下每个点应该给谁吃
	int n,c;cin>>n>>c;
	int x;
	for(int i=1;i<=n;i++)cin>>x,a[i]={min(x+i,n+1-i+x),x+i};
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i].first;
	int ans=0;//应该枚举一开始跳每个点的情况；
	for(int i=1;i<=n;i++){
		if(c<a[i].second)continue;
		ans=max(ans,1LL);
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			int val=sum[mid];//二分不看某个数
			if(mid>=i)val-=a[i].first;
			if(val+a[i].second<=c)ans=max(mid+(mid<i),ans),l=mid+1;
			else r=mid-1;
		}
		
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
