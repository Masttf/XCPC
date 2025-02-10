#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=-1;
	for(int i=0;i<=n;i++){//假设有一个说谎
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>i)cnt++;
		}
		if(cnt==i)ans=i;
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
