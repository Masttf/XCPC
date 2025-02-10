#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=3e3+5;
int a[maxn],pw[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod;
	int cnt=0;
	for(int i=1;i<=n;i++){//算贡献
		int l=i,r=i;
		for(int j=i+1;j<=n;j++){
			while(l>=1&&a[i]-a[l]<=a[j]-a[i])l--;
			while(r<=n&&a[r]-a[j]<a[j]-a[i])r++;
			cnt=(cnt+pw[l-1+1]*pw[n-r+1])%mod;
		}
	}
	cout<<cnt;
	return 0;
}
