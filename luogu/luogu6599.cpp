#include<bits/stdc++.h>
#define int unsigned long long
const int mod=1e9+7;
using namespace std;
void solve(){
	int n,l;cin>>n>>l;
	if(n==1)cout<<0<<'\n';
	else{
		int len=log2(n);
		int a=1LL<<(len+1);
		cout<<(l/2)*(l-l/2)%mod*(a-1)%mod<<'\n';
	}
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
