#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	if(s[0]=='0'){
		cout<<0<<'\n';
		return ;
	}
	int ans=1;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='?'){
			if(i==0)ans*=9;
			else ans*=10;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
