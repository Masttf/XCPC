#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k,x;cin>>n>>k>>x;
	if(x<k-1||n<k){
		cout<<-1<<'\n';
		return ;
	}
	int ans=k*(k-1)/2;
	if(x!=k)ans+=(n-k)*x;
	else ans+=(n-k)*(k-1);
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
