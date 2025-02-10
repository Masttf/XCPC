#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<int>>pre(32,vector<int>(n+1));
	for(int j=0;j<=30;j++){
		for(int i=1;i<=n;i++){
			pre[j][i]=pre[j][i-1]+((a[i]>>j)&1);
		}
	}
	int ans=0;
	for(int j=0;j<=30;j++){
		int cnt0=1,cnt1=0;
		int res=0;
		int sum0=1,sum1=0;
		for(int i=1;i<=n;i++){
			if(pre[j][i]&1)cnt1++;
			else cnt0++;
			if(pre[j][i]&1){
				res+=sum0;
			}else res+=sum1;
			sum0+=cnt0;
			sum1+=cnt1;
			sum1%=mod;
			sum1%=mod;
			res%=mod;
		}
		ans+=(1ll<<j)*res%mod;
		ans%=mod;
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
