#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+5;
int jie[maxn];
void init(){
	jie[1]=1;
	for(int i=2;i<maxn;i++){
		jie[i]=(i*jie[i-1])%mod;
	}
	return ;
}
void solve(){
	int n;cin>>n;
	int to=(n-1)*n/2;
	cout<<jie[n]*2%mod*to%mod<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
