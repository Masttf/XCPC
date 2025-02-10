#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b,c,d;cin>>a>>b>>c>>d;
	if(d<b){
		cout<<-1<<'\n';
		return ;
	}
	if(d==b){
		if(c>a)cout<<-1<<'\n';
		else cout<<a-c<<'\n';
		return ;
	}
	int t1=c-a;
	int t2=d-b;
	double k=t1*1.0/t2;
	if(k<=0||k<=1){
		int ans=d-b+abs(a+d-b-c);
		cout<<ans<<'\n';
	}else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
