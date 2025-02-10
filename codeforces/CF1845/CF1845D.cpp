#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
int a[maxn];
int sum[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int res=0;
	sum[n+1]=0;
	for(int i=n;i>=1;i--){
		res+=a[i];
		sum[i]=max(sum[i+1],res);
	}
	res=0;
	int ans=0;
	int tem=sum[1];
	for(int i=1;i<=n;i++){
		res+=a[i];
		if(res+sum[i+1]>tem){
			ans=res;
			tem=res+sum[i+1];
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
