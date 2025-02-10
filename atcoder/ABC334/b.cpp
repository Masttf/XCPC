#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,m,l,r;cin>>a>>m>>l>>r;
	if(r<a){
		int d1=(a-r-1)/m;
		int d2=(a-l)/m;
		cout<<d2-d1<<'\n';
	}else if(l<a){
		int d1=(r-a)/m;
		int d2=(a-l)/m;
		cout<<d1+d2+1<<'\n';
	}else{
		int d1=(r-a)/m;
		int d2=(l-1-a)/m;
		cout<<d1-d2<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}