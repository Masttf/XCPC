#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	map<char,int>m;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(len%2!=0&&i==len/2)continue;
		m[s[i]]++;
	}
	if(m.size()==1)cout<<"NO\n";
	else cout<<"YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
