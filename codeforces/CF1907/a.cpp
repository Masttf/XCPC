#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	char t1=s[0];
	int t2=s[1]-'0';
	for(int i=1;i<=8;i++){
		if(i==t2)continue;
		cout<<t1<<i<<'\n';
	}
	for(char i='a';i<='h';i++){
		if(i==t1)continue;
		cout<<i<<t2<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}