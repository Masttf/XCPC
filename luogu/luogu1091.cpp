#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=105;
int dp1[maxn],dp2[maxn],a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		dp1[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i])dp1[i]=max(dp1[i],dp1[j]+1);
		}
	}
	for(int i=n;i>=1;i--){
		dp2[i]=1;
		for(int j=n;j>i;j--){
			if(a[j]<a[i])dp2[i]=max(dp2[i],dp2[j]+1);
		}
	}
	int ans=maxn;
	for(int i=1;i<=n;i++)ans=min(ans,n-dp1[i]-dp2[i]+1);
	cout<<ans;
	return 0;
}
