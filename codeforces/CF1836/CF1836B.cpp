#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k,g;cin>>n>>k>>g;
	int tot=k*g;
	int d=(g+1)/2;
	if(n*(d-1)>=tot){
		cout<<tot<<'\n';
	}else{
		tot-=n*(d-1);
		tot%=g;
		int res=(n-1)*(d-1);
		int tem=(d-1)+tot;
		tem%=g;
		if(tem<d){
			res+=tem;
		}else{
			res-=g-tem;
		}
		cout<<res<<'\n';
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
