#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	if(n==1){
		cout<<"a\n";
		return ;
	}
	for(int j=2;j<=26;j++){
		if(n%j!=0){
			for(int i=1;i<=n;i++){
				cout<<(char)('a'+i%j);
			}
			cout<<'\n';
			return ;
		}
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
