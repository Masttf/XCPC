#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	int sum=0;
	int temp=0;
	for(int i=n;i>=1;i--){
		if(a[i]+(temp+sum)*2>a[i]+temp+sum){
			sum+=temp;
			ans+=sum;
			temp=a[i];
		}else{
			temp+=a[i];
		}
	}
	ans+=temp+sum;
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