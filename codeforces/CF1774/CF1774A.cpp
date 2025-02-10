#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int f=1;
	if(s[0]=='1')f=0;
	for(int i=1;i<n;i++){
		if(s[i]=='1'){
			if(f)cout<<'+';
			else cout<<'-';
			f=1-f;
		}
		else cout<<'+';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
