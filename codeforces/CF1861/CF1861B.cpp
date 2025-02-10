#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string a,b;cin>>a>>b;
	if(a==b){
		cout<<"YES\n";
		return ;
	}
	int n=a.size();
	a=' '+a;
	b=' '+b;
	for(int i=1;i<n;i++){
		if(a[i]=='0'&&a[i+1]=='1'){
			if(b[i]==a[i]&&b[i+1]==a[i+1]){
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
