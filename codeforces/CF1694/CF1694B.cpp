#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int ans=n;
	for(int i=0;i<n-1;i++){
		if(s[i]!=s[i+1])ans+=i+1;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
