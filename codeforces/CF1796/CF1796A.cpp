#include<bits/stdc++.h>
#define int long long
using namespace std;
string ans="FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
void solve(){
	int k;cin>>k;
	string s;cin>>s;
	for(int i=0;i<=32-k;i++){
		int flag=1;
		for(int j=0;j<=k-1;j++){
			if(s[j]!=ans[i+j])flag=0;
		}
		if(flag){
			cout<<"yes\n";
			return ;
		}
	}
	cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
