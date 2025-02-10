#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	int ok=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x==k)ok=1;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
