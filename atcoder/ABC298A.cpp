#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int f1=0,f2=1;
	for(int i=0;i<n;i++){
		if(s[i]=='o')f1=1;
		if(s[i]=='x')f2=0;
	}
	if(f1+f2==2)cout<<"Yes";
	else cout<<"No";
	return 0;
}
