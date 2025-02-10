#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,a,q;cin>>n>>a>>q;
	string s;cin>>s;
	int ct1=0,ct0=0;
	int ok=0;
	int res=0;
	if(a>=n)res=1,ok=1;
	for(int i=0;i<q;i++){
		if(s[i]=='-')ct0++;
		else ct1++;
		if(a+ct1>=n)ok=1;
		if(a+ct1-ct0>=n)res=1;
	}
	if(ok){
		if(res)cout<<"YES\n";
		else cout<<"MAYBE\n";
	}else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
