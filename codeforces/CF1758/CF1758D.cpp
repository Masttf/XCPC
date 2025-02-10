#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	if(n%2==0){//偶数构造n方
		for(int i=1;i<=n/2;i++){
			cout<<i+n<<' '<<n-i<<' ';
		}
		cout<<'\n';
	}else{//奇数构造2n方
		cout<<4*n<<' ';
		for(int i=1;i<=n/2;i++){
			if(i==n/2){
				cout<<i+n+(n-n/2)+3*n<<' '<<n-i-(n-n/2)+3*n<<' ';
			}
			else cout<<i+n+3*n<<' '<<n-i+3*n<<' ';
		}
		cout<<'\n';
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
