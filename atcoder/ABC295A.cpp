#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		if(s=="and"||s=="not"||s=="that"||s=="the"||s=="you")flag=1;
	}
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}
