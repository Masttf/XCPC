#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	s=' '+s;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='B'){
			ans++;
			i+=k-1;
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
