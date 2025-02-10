#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b,c;cin>>a>>b>>c;
	if(a+b==c)cout<<"yes\n";
	else if(a+c==b)cout<<"yes\n";
	else if(b+c==a)cout<<"yes\n";
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
