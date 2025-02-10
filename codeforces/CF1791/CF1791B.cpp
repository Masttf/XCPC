#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int a=0,b=0,f=0;
	string s;cin>>s;
	for(auto x:s){
		if(x=='U')b++;
		else if(x=='R')a++;
		else if(x=='L')a--;
		else b--;
		if(a==1&&b==1)f=1;
	}
	if(f)cout<<"yes\n";
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
