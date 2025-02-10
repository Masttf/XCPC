#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	string s;cin>>s;
	s=' '+s;
	int q;cin>>q;
	int val0=0;
	int val1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')val0^=a[i];
		else val1^=a[i];
	}
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int l,r;cin>>l>>r;
			val0^=(pre[r]^pre[l-1]);
			val1^=(pre[r]^pre[l-1]);
		}else{
			int g;cin>>g;
			if(g==0)cout<<val0<<' ';
			else cout<<val1<<' ';
		}
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
