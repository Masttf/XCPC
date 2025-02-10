#include<bits/stdc++.h>
#define int long long
using namespace std;
//要分成两个集合，贪心来说我只要让一个集合尽可能的达到自己的极限这样给另一个的机会更大
void solve(){
	int w,f,n;cin>>w>>f>>n;
	vector<int>a(n+1);
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	bitset<1000005>dp;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		dp|=dp<<a[i];
	}
	auto check = [&](int x)->bool{
		int ta=x*w;int tb=x*f;
		for(int i=min(sum,ta);i>=0;i--){
			if(dp[i]==1){
				if(tb>=sum-i)return true;
				else return false;
			}
		}
	};
	int ans=-1;
	int l=1,r=(sum+max(w,f)-1)/max(w,f);
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
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
