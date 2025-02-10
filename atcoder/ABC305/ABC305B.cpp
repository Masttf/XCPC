#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[]={0,3,4,8,9,14,23};
void solve(){
	string a,b;cin>>a>>b;
	cout<<abs(res[b[0]-'A']-res[a[0]-'A'])<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}