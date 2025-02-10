#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	string x,s;cin>>x>>s;
	int cnt=0;
	while(n<m){
		x+=x;
		n+=n;
		cnt++;
	}
	//cout<<x.find(s)<<endl;
	if(x.find(s)==string::npos){
		x+=x;
		cnt++;
		if(x.find(s)==string::npos){
			cout<<-1<<'\n';
			return ;
		}else cout<<cnt<<'\n';
	}else cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}