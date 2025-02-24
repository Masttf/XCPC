#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int n;cin>>n;
	int ans=0;
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if(s[i]!='?'){
			ans+=(s[i]-'0')*(1LL<<(sz-1-i));
		}
	}
	if(ans>n)cout<<-1;
	else{
		for(int i=0;i<sz;i++){
			if(s[i]=='?'){
				if(ans+(1LL<<(sz-i-1))<=n)ans+=(1LL<<(sz-i-1));
			}
		}
		cout<<ans;
	}
	return 0;
}
