#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)a[i]=b[i]=i;
	int ans=0;
	for(int i=n;i>=1;i--){
		int sum=0;
		int mx=0;
		for(int j=1;j<=n;j++){
			sum+=a[j]*b[j];
			mx=max(a[j]*b[j],mx);
		}
		ans=max(ans,sum-mx);
		for(int j=i;j<=n;j++){
			swap(b[j],b[j-1]);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
