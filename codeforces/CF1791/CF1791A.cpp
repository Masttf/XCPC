#include<bits/stdc++.h>
#define int long long
using namespace std;
string ans="codeforces";
void solve(){
	char a;
	cin>>a;
	int f=0;
	for(auto x:ans){
		if(a==x)f=1;
	}
	if(f)cout<<"yes\n";
	else cout<<"no\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
