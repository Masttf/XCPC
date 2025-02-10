#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,x,y;cin>>n>>x>>y;
	int d1=n/x;
	int d2=n/y;
	int tot=x*y/__gcd(x,y);
	int d3=n/tot;
	d1-=d3;
	d2-=d3;
	int val1=d1*(n+n-d1+1)/2;
	int val2=d2*(d2+1)/2;
	cout<<val1-val2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
