#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	if(n==1&&m==1){
		cout<<'!'<<' '<<1<<' '<<1<<endl;
		return ;
	}else if(n==1){
		cout<<'?'<<' '<<1<<' '<<1<<endl;
		int res1;cin>>res1;
		if(res1==0)cout<<'!'<<' '<<1<<' '<<1<<endl;
		else cout<<'!'<<' '<<1<<' '<<1+res1<<endl;
		return ;
	}else if(m==1){
		cout<<'?'<<' '<<1<<' '<<1<<endl;
		int res1;cin>>res1;
		if(res1==0)cout<<'!'<<' '<<1<<' '<<1<<endl;
		else cout<<'!'<<' '<<res1+1<<' '<<1<<endl;
		return ;
	}
	cout<<'?'<<' '<<1<<' '<<1<<endl;
	int res1;cin>>res1;
	cout<<'?'<<' '<<1<<' '<<2<<endl;
	int res2;cin>>res2;
	if(res1==res2){
		cout<<'?'<<' '<<res1+1<<' '<<1<<endl;
		int res3;cin>>res3;
		cout<<'!'<<' '<<res1+1<<' '<<1+res3<<endl;
		return ;
	}else{
		cout<<'?'<<' '<<1<<' '<<1+res1<<endl;
		int res3;cin>>res3;
		cout<<'!'<<' '<<res3+1<<' '<<1+res1<<endl;
	}
	return ;
}
signed main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
