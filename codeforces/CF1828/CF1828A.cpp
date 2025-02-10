#include<bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
	int n;cin>>n;
	
	for(int i=1;i<=n;i++)cout<<2*i<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
