#include<bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	if(n%m!=0){
		cout<<1<<'\n';
		cout<<n<<'\n';
		return ;
	}else{
		cout<<2<<'\n';
		cout<<n-m+1<<' '<<m-1<<'\n';
		return ;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
