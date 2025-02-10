#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int ok=1;
	if(!(s[0]>='A'&&s[0]<='Z')){
		ok=0;
	}
	for(int i=1;i<s.size();i++){
		if(!(s[i]>='a'&&s[i]<='z'))ok=0;
	}
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}