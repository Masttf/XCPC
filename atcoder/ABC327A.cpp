#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	for(int i=1;i<n;i++){
		if((s[i]=='a'&&s[i+1]=='b')||(s[i+1]=='a'&&s[i]=='b')){
			cout<<"Yes\n";
			return ;
		}
	}
	cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}