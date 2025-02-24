#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll qpow(ll a,ll b){
	ll base=a;
	ll ans=1;
	while(b){
		if(b&1)ans=ans*base%998244353;
		b>>=1;
		base*=base;
		base%=998244353;
	}
	return ans;
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<qpow(2,n)-1<<'\n';
	}
	return 0;
}
