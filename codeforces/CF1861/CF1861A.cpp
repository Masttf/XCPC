#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int ans=13;
	int f3=0;
	int f1=0;
	for(int i=0;i<9;i++){
		if(s[i]=='3'){
			f3=1;
			if(f1)ans=13;
		}
		if(s[i]=='1'){
			f1=1;
			if(f3)ans=31;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
