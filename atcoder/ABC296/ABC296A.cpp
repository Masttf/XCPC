#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int flag=1;
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1])flag=0;
	}
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}

