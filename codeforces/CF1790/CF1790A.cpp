#include<bits/stdc++.h>
#define int long long
using namespace std;
string ans="314159265358979323846264338327";
void solve(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!=ans[i]){
			cout<<i<<'\n';
			break;
		}
		if(i==s.size()-1){
			cout<<i+1<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
