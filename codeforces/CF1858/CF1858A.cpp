#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b,c;cin>>a>>b>>c;
	c%=2;
	if(c==1)a++;
	if(a>b)cout<<"First\n";
	else cout<<"Second\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
