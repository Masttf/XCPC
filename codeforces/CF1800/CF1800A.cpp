#include<bits/stdc++.h>
#define int long long
using namespace std;//meow
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int flag=1;
	int i=0;
	while(s[i]=='m'||s[i]=='M'){
		i++;
		if(flag==1)flag=2;
	}
	while(s[i]=='e'||s[i]=='E'){
		i++;
		if(flag==2)flag=3;
	}
	while(s[i]=='o'||s[i]=='O'){
		i++;
		if(flag==3)flag=4;
	}
	while(i<n&&(s[i]=='w'||s[i]=='W')){
		i++;
		if(flag==4)flag=5;
	}
	if(i==n&&flag==5)cout<<"yes\n";
	else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
