#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string a,b;cin>>a>>b;
	int d1=a[1]-a[0];
	int d2=b[1]-b[0];
	d1=abs(d1);
	d2=abs(d2);
	if(d1==4)d1=1;
	else if(d1==3)d1=2;
	if(d2==4)d2=1;
	else if(d2==3)d2=2;
	if(d1==d2)cout<<"Yes";
	else cout<<"No";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}