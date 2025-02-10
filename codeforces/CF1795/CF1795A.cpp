#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	reverse(b.begin(),b.end());
	a+=b;
	int flag=0;
	for(int i=0;i<n+m-1;i++){
		if(a[i]==a[i+1])flag++;
	}
	if(flag<=1)cout<<"yes\n";
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
