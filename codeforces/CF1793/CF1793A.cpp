#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b;cin>>a>>b;
	int n,m;cin>>n>>m;
	if(a<=b){//都在a买
		int t=n/(m+1);
		cout<<a*m*t+a*(n-t*(m+1))<<'\n';
	}else{//首先多出来的肯定在b买所以先假设n为m的倍数
		int t=n/(m+1);
		if(a*m<b*(m+1)){
			cout<<a*m*t+b*(n-t*(m+1))<<'\n';
		}else cout<<b*n<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
