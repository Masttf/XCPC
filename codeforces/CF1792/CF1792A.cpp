#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int x,cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x>1)ans++;
		else cnt++;
	}
	ans+=(cnt+1)/2;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
